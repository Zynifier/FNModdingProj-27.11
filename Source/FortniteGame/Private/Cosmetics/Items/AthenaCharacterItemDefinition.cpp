// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaCharacterItemDefinition.h"
#include "Animation/AnimInstance.h"
#include "AssetRegistry/AssetData.h"
#include "Customization/CustomCharacterPart.h"
#include "Engine/AssetManager.h"
#include "Engine/SkeletalMesh.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "STW/Heroes/FortHeroType.h"

#if WITH_EDITOR
#include "Cosmetics/Variants/FortCosmeticVariant.h"
#include "HAL/FileManager.h"
#include "ISourceControlModule.h"
#include "ISourceControlProvider.h"
#include "Misc/DataValidation.h"
#include "Misc/PackageName.h"
#include "Modules/ModuleManager.h"
#include "PackageHelperFunctions.h"
#include "SourceControlOperations.h"

DEFINE_LOG_CATEGORY_STATIC(LogFortCosmetics, Log, All);

static bool CheckOutPackageForMigration(UObject* Object, bool bSkipCheckOut)
{
	FString Filename;
	if (!FPackageName::DoesPackageExist(Object->GetPathName(), &Filename))
	{
		UE_LOG(LogFortCosmetics, Error, TEXT("[MigratePartsFromHID] %s Does not exist on disk! Not doing anything because this is spooky."), *GetNameSafe(Object));
		return false;
	}

	if (!IFileManager::Get().IsReadOnly(*Filename))
	{
		return true;
	}

	ISourceControlProvider& SourceControlProvider = FModuleManager::LoadModuleChecked<ISourceControlModule>(TEXT("SourceControl")).GetProvider();
	FSourceControlStatePtr SourceControlState = SourceControlProvider.GetState(Filename, EStateCacheUsage::Use);
	if (!SourceControlState.IsValid())
	{
		return false;
	}

	if (!SourceControlState->IsCurrent())
	{
		UE_LOG(LogFortCosmetics, Error, TEXT("[MigratePartsFromHID] %s is not synced to head, can not submit"), *Filename);
		return false;
	}

	if (!SourceControlState->IsSourceControlled())
	{
		return false;
	}

	if (!SourceControlState->IsCheckedOut() && !SourceControlState->IsAdded() && !SourceControlState->IsDeleted() && !bSkipCheckOut)
	{
		if (SourceControlProvider.Execute(ISourceControlOperation::Create<FCheckOut>(), Filename) != ECommandResult::Succeeded)
		{
			UE_LOG(LogFortCosmetics, Warning, TEXT("[MigratePartsFromHID] %s could not be checked out!"), *Filename);
			return false;
		}

		UE_LOG(LogFortCosmetics, Display, TEXT("[MigratePartsFromHID] %s Checked out successfully"), *Filename);
	}

	return true;
}
#endif

static EFortCustomPartType::Type GetCharacterPartType(const TSoftObjectPtr<UCustomCharacterPart>& CharacterPartPtr)
{
	if (CharacterPartPtr.IsNull())
	{
		return EFortCustomPartType::NumTypes;
	}

	if (const UCustomCharacterPart* CharacterPart = CharacterPartPtr.Get())
	{
		return CharacterPart->CharacterPartType;
	}

	FAssetData CharacterPartAssetData;
	if (!UAssetManager::Get().GetAssetDataForPath(CharacterPartPtr.ToSoftObjectPath(), CharacterPartAssetData))
	{
		return EFortCustomPartType::NumTypes;
	}

	EFortCustomPartType::Type CharacterPartType = EFortCustomPartType::NumTypes;

	const FAssetTagValueRef CharacterPartTypeTag = CharacterPartAssetData.TagsAndValues.FindTag(FName(TEXT("CharacterPartType")));
	if (CharacterPartTypeTag.IsSet())
	{
		const int64 CharacterPartTypeValue = StaticEnum<EFortCustomPartType::Type>()->GetValueByNameString(CharacterPartTypeTag.AsString());
		if (CharacterPartTypeValue >= 0)
		{
			CharacterPartType = (EFortCustomPartType::Type)CharacterPartTypeValue;
		}
	}

	return CharacterPartType;
}

bool UAthenaCharacterItemDefinition::FindBodyType_BP(const TArray<FMcpVariantChannelInfo>& InCharacterVariantChannels, TEnumAsByte<EFortCustomBodyType::Type>& OutBodyType) const
{
	return false;
}

EFortCustomGender::Type UAthenaCharacterItemDefinition::GetCharacterGender_BP(const FFortAthenaLoadout& Loadout) const
{
	return EFortCustomGender::Type();
}

#if WITH_EDITOR
EDataValidationResult UAthenaCharacterItemDefinition::IsDataValid(FDataValidationContext& Context) const
{
	Super::IsDataValid(Context);

	auto ValidateCharacterPart = [&Context](const UCustomCharacterPart* CharacterPart)
	{
		if (!CharacterPart)
		{
			Context.AddError(NSLOCTEXT("AthenaCharacterItemDefinition", "NullCharacterPart", "Character provides null character part. Null character parts should be removed"));
			return;
		}

		if (CharacterPart->CharacterPartType == EFortCustomPartType::Head)
		{
			const EFortCustomBodyType::Type BodyType = CharacterPart->BodyTypesPermitted;
			if (BodyType != EFortCustomBodyType::Small && BodyType != EFortCustomBodyType::Medium && BodyType != EFortCustomBodyType::Large)
			{
				Context.AddError(FText::Format(NSLOCTEXT("AthenaCharacterItemDefinition", "HeadInvalidBodyType", "Head part {0} has invalid body type {1}. Heads should specify fixed body types"), FText::FromString(CharacterPart->GetName()), StaticEnum<EFortCustomBodyType::Type>()->GetDisplayNameTextByValue(BodyType)));
			}
		}
	};

	auto LoadCharacterPart = [](const TSoftObjectPtr<UCustomCharacterPart>& CharacterPartPtr) -> const UCustomCharacterPart*
	{
		if (CharacterPartPtr.IsNull())
		{
			return nullptr;
		}

		const UCustomCharacterPart* CharacterPart = CharacterPartPtr.Get();
		if (!CharacterPart)
		{
			CharacterPart = CharacterPartPtr.LoadSynchronous();
			ensureMsgf(CharacterPart, TEXT("Failed to load asset pointer %s"), *CharacterPartPtr.ToString());
		}

		return CharacterPart;
	};

	for (const TSoftObjectPtr<UCustomCharacterPart>& CharacterPartPtr : BaseCharacterParts)
	{
		ValidateCharacterPart(LoadCharacterPart(CharacterPartPtr));
	}

	for (UFortCosmeticVariant* ItemVariant : ItemVariants)
	{
		if (!ItemVariant)
		{
			continue;
		}

		ItemVariant->PreValidateVariant();

		const FGameplayTagContainer AllVariantTags = ItemVariant->GetAllVariantTags();
		for (const FGameplayTag& VariantTag : AllVariantTags)
		{
			TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantCharacterParts;
			ItemVariant->GetVariantCharacterParts(VariantCharacterParts, VariantTag);

			for (const TSoftObjectPtr<UCustomCharacterPart>& VariantCharacterPartPtr : VariantCharacterParts)
			{
				ValidateCharacterPart(LoadCharacterPart(VariantCharacterPartPtr));
			}
		}
	}

	return Context.GetNumErrors() == 0 ? EDataValidationResult::Valid : EDataValidationResult::Invalid;
}

void UAthenaCharacterItemDefinition::MigratePartsFromHID()
{
	if (!HeroDefinition || BaseCharacterParts.Num() != 0)
	{
		return;
	}

	TArray<UFortHeroSpecialization*> HeroSpecializations;
	HeroDefinition->GetSpecializations(HeroSpecializations);

	if (HeroSpecializations.Num() > 1)
	{
		UE_LOG(LogFortCosmetics, Warning, TEXT("[MigratePartsFromHID] %s specified too many HeroSpecializations! Athena Outfits should have only ever used a single HeroSpecialization!"), *GetNameSafe(HeroDefinition));
	}

	if (!CheckOutPackageForMigration(HeroDefinition, false) || !CheckOutPackageForMigration(this, false))
	{
		return;
	}

	bool bCheckedOutAllHeroSpecializations = true;
	for (UFortHeroSpecialization* HeroSpecialization : HeroSpecializations)
	{
		if (!CheckOutPackageForMigration(HeroSpecialization, false))
		{
			bCheckedOutAllHeroSpecializations = false;
		}
	}

	if (!bCheckedOutAllHeroSpecializations)
	{
		return;
	}

	if (HeroSpecializations.Num() > 0)
	{
		if (UFortHeroSpecialization* FirstHeroSpecialization = HeroSpecializations[0])
		{
			Modify();
			BaseCharacterParts = FirstHeroSpecialization->GetCharacterPartPtrs();
		}

		for (UFortHeroSpecialization* HeroSpecialization : HeroSpecializations)
		{
			HeroSpecialization->Modify();
			HeroSpecialization->CharacterParts.Empty();

			FString HeroSpecializationFilename;
			if (FPackageName::DoesPackageExist(HeroSpecialization->GetPathName(), &HeroSpecializationFilename))
			{
				SavePackageHelper(HeroSpecialization->GetPackage(), HeroSpecializationFilename);
			}
		}
	}

	HeroDefinition->Modify();
	HeroDefinition->Specializations.Empty();

	FString HeroDefinitionFilename;
	if (FPackageName::DoesPackageExist(HeroDefinition->GetPathName(), &HeroDefinitionFilename))
	{
		SavePackageHelper(HeroDefinition->GetPackage(), HeroDefinitionFilename);
	}

	FString CharacterItemDefinitionFilename;
	if (FPackageName::DoesPackageExist(GetPathName(), &CharacterItemDefinitionFilename))
	{
		SavePackageHelper(GetPackage(), CharacterItemDefinitionFilename);
	}
}
#endif

void UAthenaCharacterItemDefinition::GetPreviewSkeletalMeshes(TArray<USkeletalMesh*>& OutList, TArray<TSubclassOf<UAnimInstance>>& OutAnimBP) const
{
	TSet<EFortCustomPartType::Type> PreviewedPartTypes;

	for (const TSoftObjectPtr<UCustomCharacterPart>& CharacterPartPtr : BaseCharacterParts)
	{
		if (CharacterPartPtr.IsNull())
		{
			continue;
		}

		const EFortCustomPartType::Type CharacterPartType = GetCharacterPartType(CharacterPartPtr);

		bool bPartTypeAlreadyPreviewed = false;
		PreviewedPartTypes.Add(CharacterPartType, &bPartTypeAlreadyPreviewed);

		CharacterPartPtr.LoadSynchronous();

		if (bPartTypeAlreadyPreviewed)
		{
			continue;
		}

		const UCustomCharacterPart* CharacterPart = CharacterPartPtr.Get();
		if (USkeletalMesh* PartSkeletalMesh = CharacterPart->GetSkeletalMesh())
		{
			OutList.Add(PartSkeletalMesh);
			OutAnimBP.Add(CharacterPartType == EFortCustomPartType::Head ? CharacterPart->GetAnimClass() : TSubclassOf<UAnimInstance>());
		}
	}
}

USkeletalMesh* UAthenaCharacterItemDefinition::GetPreviewBaseMesh() const
{
	for (const TSoftObjectPtr<UCustomCharacterPart>& CharacterPartPtr : BaseCharacterParts)
	{
		if (CharacterPartPtr.IsNull() || GetCharacterPartType(CharacterPartPtr) != EFortCustomPartType::Body)
		{
			continue;
		}

		const UCustomCharacterPart* BodyPart = CharacterPartPtr.LoadSynchronous();

		TArray<USkeletalMesh*> MasterSkeletalMeshes;
		for (const TSoftObjectPtr<USkeletalMesh>& MasterSkeletalMeshPtr : BodyPart->MasterSkeletalMeshes)
		{
			if (MasterSkeletalMeshPtr.IsNull())
			{
				continue;
			}

			USkeletalMesh* MasterSkeletalMesh = MasterSkeletalMeshPtr.Get();
			if (!MasterSkeletalMesh)
			{
				MasterSkeletalMesh = MasterSkeletalMeshPtr.LoadSynchronous();
				ensureMsgf(MasterSkeletalMesh, TEXT("Failed to load asset pointer %s"), *MasterSkeletalMeshPtr.ToString());
			}

			if (MasterSkeletalMesh)
			{
				MasterSkeletalMeshes.Add(MasterSkeletalMesh);
			}
		}

		return MasterSkeletalMeshes.IsValidIndex(0) ? MasterSkeletalMeshes[0] : nullptr;
	}

	return nullptr;
}
