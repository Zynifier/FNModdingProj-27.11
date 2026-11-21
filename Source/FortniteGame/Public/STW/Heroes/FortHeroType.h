// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/PreviewCollectionInterface.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "Attributes/FortAttributeInitializationKey.h"
#include "Items/FortReplenishmentType.h"
#include "STW/Heroes/FortWorkerType.h"
#include "FortHeroType.generated.h"

class AFortPlayerPawn;
class UAnimMontage;
class UAthenaBackpackItemDefinition;
class UAthenaCharacterItemDefinition;
class UFortAbilityKit;
class UFortFeedbackBank;
class UFortHeroGameplayDefinition;
class UFortHeroSpecialization;
class UFortMontageLookupTable;
class UFortWorldItemDefinition;
class UFrontendAnimInstance;

USTRUCT(BlueprintType)
struct FHeroAbilityKit
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InherentAbilities")
	TSoftObjectPtr<UFortAbilityKit> InherentAbilityKit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InherentAbilities")
	FGameplayTagContainer RequiredGPTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="InherentAbilities")
	bool bShowInAbilityScreen;

};

USTRUCT(BlueprintType)
struct FHeroItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	TSoftObjectPtr<UFortWorldItemDefinition> Item;

	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	int32 Quantity;

	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	TEnumAsByte<EFortReplenishmentType::Type> Replenishment;

	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	FGameplayTagContainer RequiredGPTags;

	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	FGameplayTagContainer SwapTag;

	UPROPERTY(EditAnywhere, Category="ForcedInventory")
	bool bShowInAbilityScreen;

};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortHeroType : public UFortWorkerType, public IPreviewCollectionInterface
{
	GENERATED_BODY()

	friend class UAthenaCharacterItemDefinition;

public:
	UFUNCTION(BlueprintPure, Category="HeroType")
	TSubclassOf<UFrontendAnimInstance> GetFrontendAnimClass() const;

	UFUNCTION(BlueprintPure, Category="HeroType")
	UAnimMontage* GetFrontendAnimMontageIdleOverride() const;

	UFUNCTION(BlueprintPure, Category="HeroType")
	UFortHeroGameplayDefinition* GetHeroGameplayDefinition();

	UFUNCTION(BlueprintPure, Category="HeroType")
	void GetSpecializations(TArray<UFortHeroSpecialization*>& OutSpecializations) const;

	UFUNCTION(BlueprintPure, Category="HeroType")
	FText GetSubType() const;

	virtual void GetPreviewSkeletalMeshes(TArray<USkeletalMesh*>& OutList, TArray<TSubclassOf<UAnimInstance>>& OutAnimBP) const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="CharacterParts")
	uint8 bForceShowHeadAccessory : 1;

	UPROPERTY(EditDefaultsOnly, Category="CharacterParts")
	uint8 bForceShowBackpack : 1;

	UPROPERTY(EditAnywhere, Category="Pawn")
	float FrontEndBackPreviewRotationOffset;

	UPROPERTY(EditDefaultsOnly, Category="Specialization", meta=(AssetBundles="ItemDetails,AvatarDisplay"))
	TArray<TSoftObjectPtr<UFortHeroSpecialization>> Specializations;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSoftObjectPtr<UFortMontageLookupTable> DefaultMontageLookupTable;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSoftObjectPtr<UFortMontageLookupTable> OverrideMontageLookupTable;

	UPROPERTY(EditDefaultsOnly, Category="CombinedStats", meta=(AssetBundles="ItemDetails"))
	TArray<FGameplayEffectApplicationInfo> CombinedStatGEs;

	UPROPERTY(EditAnywhere, Category="Requirements")
	FGameplayTagContainer RequiredGPTags;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<UFortFeedbackBank> MaleOverrideFeedback;

	UPROPERTY(EditAnywhere, Category="Feedback")
	TSoftObjectPtr<UFortFeedbackBank> FemaleOverrideFeedback;

	UPROPERTY(EditAnywhere, Category="Pawn")
	TSoftClassPtr<AFortPlayerPawn> OverridePawnClass;

	UPROPERTY(EditAnywhere, Category="HeroGameplay", meta=(IncludeAssetBundles))
	TObjectPtr<UFortHeroGameplayDefinition> HeroGameplayDefinition;

	UPROPERTY(EditAnywhere, Category="HeroGameplay", meta=(IncludeAssetBundles))
	TObjectPtr<UAthenaCharacterItemDefinition> HeroCosmeticOutfitDefinition;

	UPROPERTY(EditAnywhere, Category="HeroGameplay", meta=(IncludeAssetBundles))
	TObjectPtr<UAthenaBackpackItemDefinition> HeroCosmeticBackblingDefinition;

	UPROPERTY(EditAnywhere, Category="Pawn")
	TSoftClassPtr<UFrontendAnimInstance> FrontendAnimClass;

	UPROPERTY(EditAnywhere, Category="Pawn", meta=(AssetBundles="ItemDetails,AvatarDisplay,Menu"))
	TSoftObjectPtr<UAnimMontage> FrontendAnimMontageIdleOverride;

	UPROPERTY(EditAnywhere, Category="Display")
	FText SubType;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FFortAttributeInitializationKey AttributeInitKey;

	UPROPERTY(EditDefaultsOnly, Category="Attributes")
	FDataTableRowHandle LegacyStatHandle;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Male;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Female;

};

