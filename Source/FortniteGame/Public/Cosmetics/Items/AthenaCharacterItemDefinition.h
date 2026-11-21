// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PreviewCollectionInterface.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortCustomPartTypeEnum.h"
#include "FortGender.h"
#include "AthenaCharacterItemDefinition.generated.h"

class UAssembledMeshSchema;
class UAthenaBackpackItemDefinition;
class UAthenaCosmeticItemDefinition;
class UCustomCharacterPart;
class UFortFeedbackBank;
class UFortHeroType;
class UMarshalledVFX_AuthoredDataConfig;
class UObject;

USTRUCT()
struct FAthenaCharacterTaggedPartsList
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaCharacterTaggedPartsList")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> Parts;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaCharacterItemDefinition : public UAthenaCosmeticItemDefinition, public IPreviewCollectionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(DisplayName="Find Body Type"))
	bool FindBodyType_BP(const TArray<FMcpVariantChannelInfo>& InCharacterVariantChannels, TEnumAsByte<EFortCustomBodyType::Type>& OutBodyType) const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Character Gender"))
	EFortCustomGender::Type GetCharacterGender_BP(const FFortAthenaLoadout& Loadout) const;

	UPROPERTY(EditAnywhere, Category="Character")
	TMap<FName, TSubclassOf<UObject>> RequestedDataStores;

	UPROPERTY(NoClear, Instanced)
	TMap<TEnumAsByte<EFortCustomPartType::Type>, TObjectPtr<UMarshalledVFX_AuthoredDataConfig>> AuthoredVFXData_ByPart_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroType", meta=(AssetBundles="MenuAthena,ServerAthena"))
	TArray<TSoftObjectPtr<UCustomCharacterPart>> BaseCharacterParts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroType")
	TObjectPtr<UFortHeroType> HeroDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroType")
	TObjectPtr<UAthenaBackpackItemDefinition> DefaultBackpack;

	UPROPERTY(EditDefaultsOnly, Category="Character")
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> RequiredCosmeticItems;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAssembledMeshSchema>> AssembledMeshSchemas;

	virtual void GetPreviewSkeletalMeshes(TArray<USkeletalMesh*>& OutList, TArray<TSubclassOf<UAnimInstance>>& OutAnimBP) const override;
	virtual USkeletalMesh* GetPreviewBaseMesh() const override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif

protected:
#if WITH_EDITOR
	UFUNCTION(Exec, Category="HeroType", meta=(CallInEditor="true"))
	void MigratePartsFromHID();
#endif

	UPROPERTY(EditDefaultsOnly, Category="FrontendPreview", meta=(DisplayAfter="PreviewPawnRotationOffset"))
	float PreviewPawnScale;

private:
	UPROPERTY(EditDefaultsOnly, Category="Character")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<UFortFeedbackBank> FeedbackBank;

	UPROPERTY(EditDefaultsOnly, Category="Character", meta=(Categories="Cosmetics.MetaTags.Theme"))
	TMap<FGameplayTag, FAthenaCharacterTaggedPartsList> TaggedPartsOverride;

};

