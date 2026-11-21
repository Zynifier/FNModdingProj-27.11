// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortWorldMultiItemDefinition.generated.h"

class UActorComponent;
class UFortItemDefinition;

USTRUCT()
struct FFortWorldMultiItemInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	uint8 bEnableXPLimitsPerLevel : 1;

	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Switching")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Switching", meta=(EditCondition="bEnableXPLimitsPerLevel", EditConditionHides, HideEditConditionToggle))
	TSubclassOf<UActorComponent> ComponentClassForXPLogic;

	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Switching", meta=(EditCondition="bEnableXPLimitsPerLevel", EditConditionHides, HideEditConditionToggle))
	FScalableFloat RequiredXPForNextLevel;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortWorldMultiItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Switching")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ValidItemsToBecome;

	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Switching")
	TArray<FFortWorldMultiItemInfo> ItemInfos;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortItemDefinition>> CachedItemDefinitionList;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	uint8 bDisplayCurrentItemRarity : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bSwitchItemOnTimer : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bSwitchItemAfterFiringEnds : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bSwitchItemInSequenceByPoweringUp : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules", meta=(EditCondition="bSwitchItemInSequenceByPoweringUp"))
	uint8 bManuallyFlushPendingPowerUp : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bPreventSwitchingWhileFiring : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bPreventSwitchingWhileCharging : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bPreventSwitchingWhileReloading : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bPreventSwitchingWhileAiming : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules")
	uint8 bPreventSwitchingWhileHidden : 1;

	UPROPERTY(EditDefaultsOnly, Category="Switching Rules", meta=(ClampMax="600.000000", ClampMin="0.000000", DisplayAfter="bSwitchItemOnTimer", EditCondition="bSwitchItemOnTimer", UIMax="600.000000", UIMin="0.000000"))
	float TimeBetweenSwitchingItems;

	UPROPERTY(EditDefaultsOnly, Category="Switching Cues", meta=(Categories="GameplayCue", DisplayName="Actor Tell Cues"))
	FGameplayTagContainer ItemActorSwitchingTellCues;

	UPROPERTY(EditDefaultsOnly, Category="Switching Cues", meta=(Categories="GameplayCue", DisplayName="Actor Switch Cues"))
	FGameplayTagContainer NewItemActorSwitchingCues;

	UPROPERTY(EditDefaultsOnly, Category="Switching Cues", meta=(ClampMax="60.000000", ClampMin="0.000000", UIMax="60.000000", UIMin="0.000000"))
	float TellDuration;

	UPROPERTY(EditDefaultsOnly, Category="Pickup Data")
	FGameplayTag GameplayTagKeyForCurrentSelectedItemIndex;

	UPROPERTY(EditDefaultsOnly, Category="Pickup Data", meta=(EditCondition="bSwitchItemInSequenceByPoweringUp"))
	FGameplayTag GameplayTagKeyForCurrentXP;

};

