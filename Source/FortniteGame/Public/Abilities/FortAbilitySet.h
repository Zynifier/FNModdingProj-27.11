// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagAssetInterface.h"
#include "GameplayTagContainer.h"
#include "Abilities/GameplayEffectApplicationInfo.h"
#include "FortAbilitySet.generated.h"

class UFortGameplayAbility;
class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FAbilityActivatedByInputData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AbilityActivatedByInputData")
	TSubclassOf<UFortGameplayAbility> Ability;

	UPROPERTY(EditDefaultsOnly, Category="AbilityActivatedByInputData")
	FGameplayTagQuery ActivationTagQuery;

};

UCLASS(MinimalAPI)
class UFortAbilitySet : public UPrimaryDataAsset, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability Set | Defaults", meta=(AssetBundles="ItemDetails"))
	TArray<TSubclassOf<UFortGameplayAbility>> GameplayAbilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Defaults")
	TArray<FGameplayEffectApplicationInfoHard> GrantedGameplayEffects;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input")
	uint8 bUsePrimaryInputComponent : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input")
	bool bShouldHotbarKeysForceExitBuildMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ability Set | Input", meta=(DisplayName="Unique Key Tag"))
	FGameplayTag AbilityActivatedByInputKeyTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input", meta=(DisplayName="Action Tag"))
	FGameplayTag AbilityActivatedByInputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input", meta=(DisplayName="Cooldown Tag"))
	FGameplayTag AbilityActivatedByInputCooldownTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input")
	TArray<FAbilityActivatedByInputData> AbilitiesActivatedByInput;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Ability Set | Input")
	TArray<TObjectPtr<UFortItemDefinition>> AdditionalItemsToAdd;

	UPROPERTY(EditDefaultsOnly, Category="Ability Set | Analytics")
	FGameplayTagContainer AnalyticsTags;

private:
	UPROPERTY()
	TArray<FGameplayEffectApplicationInfo> PassiveGameplayEffects;

};

