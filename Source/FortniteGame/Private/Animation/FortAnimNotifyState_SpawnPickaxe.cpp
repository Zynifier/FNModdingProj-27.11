// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimNotifyState_SpawnPickaxe.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/GameDataCosmetics.h"
#include "Cosmetics/Items/AthenaPickaxeItemDefinition.h"
#include "Engine/AssetManager.h"
#include "Engine/SkeletalMesh.h"
#include "FortAssetManager.h"
#include "FortGameInstance.h"
#include "GameplayTagContainer.h"
#include "Items/FortItemTypeEnum.h"
#include "NativeGameplayTags.h"
#include "Pawns/FortPlayerPawn.h"
#include "Player/FortPlayerController.h"
#include "UObject/UnrealType.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "Weapons/FortWeapon.h"

UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Cosmetics_Pickaxe_DualWield, "Cosmetics.Pickaxe.DualWield");
UE_DEFINE_GAMEPLAY_TAG_STATIC(TAG_Cosmetics_Pickaxe_OneHanded, "Cosmetics.Pickaxe.OneHanded");

#if WITH_EDITOR
bool UFortAnimNotifyState_SpawnPickaxe::CanEditChange(const FProperty* InProperty) const
{
	if (InProperty && (InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFortAnimNotifyState_SpawnPickaxe, ActorProp) || InProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFortAnimNotifyState_SpawnPickaxe, StaticMeshProp)))
	{
		return false;
	}

	return Super::CanEditChange(InProperty);
}
#endif

void UFortAnimNotifyState_SpawnPickaxe::GetActorPropOverride(AFortPawn* FortPawn, TSubclassOf<AActor>& InOutActorProp, USkeletalMesh*& InOutSkeletalMeshProp, UFortItemDefinition*& OutActorPropItemDefinition)
{
	InOutActorProp = nullptr;
	InOutSkeletalMeshProp = (!FortPawn || FortPawn->GetLocalRole() == ROLE_Authority) ? SkeletalMeshProp.Get() : nullptr;

	AFortPlayerPawn* FortPlayerPawn = Cast<AFortPlayerPawn>(FortPawn);
	if (!FortPlayerPawn)
	{
		return;
	}

	UFortGameInstance* FortGameInstance = Cast<UFortGameInstance>(FortPlayerPawn->GetGameInstance());
	if (!FortGameInstance)
	{
		return;
	}

	UAthenaPickaxeItemDefinition* PickaxeItemDefinition = FortPlayerPawn->GetPawnCosmeticLoadout(false, true).Pickaxe;
	if (!PickaxeItemDefinition)
	{
		AFortPlayerController* FortPlayerController = Cast<AFortPlayerController>(FortGameInstance->GetFirstLocalPlayerController());
		if (!FortPlayerController)
		{
			return;
		}

		PickaxeItemDefinition = FortPlayerController->CosmeticLoadoutPC.Pickaxe;
		if (!PickaxeItemDefinition)
		{
			return;
		}
	}

	UFortWeaponMeleeItemDefinition* WeaponDefinition = PickaxeItemDefinition->WeaponDefinition;
	if (!WeaponDefinition)
	{
		return;
	}

	FGameplayTagContainer WeaponDefinitionTags;
	WeaponDefinition->GetOwnedGameplayTags(WeaponDefinitionTags);

	if (WeaponDefinitionTags.HasTag(TAG_Cosmetics_Pickaxe_DualWield) || WeaponDefinitionTags.HasTag(TAG_Cosmetics_Pickaxe_OneHanded))
	{
		UFortAssetManager* FortAssetManager = Cast<UFortAssetManager>(&UAssetManager::Get());
		UGameDataCosmetics* GameDataCosmetics = FortAssetManager->GameDataCosmetics;

		UAthenaPickaxeItemDefinition* FallbackPickaxe = GameDataCosmetics->FallbackPickaxe.LoadSynchronous();
		ensureMsgf(FallbackPickaxe, TEXT("Failed to load asset pointer %s"), *GameDataCosmetics->FallbackPickaxe.ToString());

		WeaponDefinition = FallbackPickaxe->WeaponDefinition;
	}
	else if (FortPawn->CurrentWeapon && FortPawn->CurrentWeapon->GetWeaponDataItemType() == EFortItemType::WeaponHarvest)
	{
		return;
	}

	OutActorPropItemDefinition = WeaponDefinition;
	InOutActorProp = WeaponDefinition->GetWeaponActorClass();
}

void UFortAnimNotifyState_SpawnPickaxe::OnActorPropSpawned(AActor* ActorPropInstance, UFortItemDefinition* ActorPropItemDefinition)
{
	if (!ActorPropInstance)
	{
		return;
	}

	AFortWeapon* PickaxeWeapon = Cast<AFortWeapon>(ActorPropInstance);
	UFortWeaponMeleeItemDefinition* MeleeItemDefinition = Cast<UFortWeaponMeleeItemDefinition>(ActorPropItemDefinition);
	if (PickaxeWeapon && MeleeItemDefinition)
	{
		PickaxeWeapon->SetWeaponData(MeleeItemDefinition);
	}

	ActorPropInstance->SetReplicates(false);
}
