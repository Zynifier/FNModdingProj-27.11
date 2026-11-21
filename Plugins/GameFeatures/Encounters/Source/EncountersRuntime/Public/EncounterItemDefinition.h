// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueInterface.h"
#include "InstancedStruct.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "WorldConditionQuery.h"
#include "Items/FortItemDefinition.h"
#include "EncounterItemDefinition.generated.h"

class UStateTree;
class UWorld;

USTRUCT()
struct FEncounterRewardBehavior
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="EncounterRewardBehavior")
	FVector RewardOffset;

	UPROPERTY(EditAnywhere, Category="EncounterRewardBehavior")
	FVector RewardDirection;

	UPROPERTY(EditAnywhere, Category="EncounterRewardBehavior")
	float RewardConeAngle;

	UPROPERTY(EditAnywhere, Category="EncounterRewardBehavior")
	float RewardFlingMagnitude;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Prm", "FrontEnd", "Item", "FortItem", "Utilities", "Display", "Functionality", "FrontendPreview", "OwnedTags", "Tooltips", "Rating", "Series", "PreviewImage", "Event", "InventoryLimit", "FortItemDefinition"))
class UEncounterItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Encounter")
	bool bAutoHandleSuccessFailure;

	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftObjectPtr<UWorld> Level;

	UPROPERTY(EditAnywhere, Category="Encounter")
	TObjectPtr<UStateTree> StateTreeOverride;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayCueTag ProximityGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayCueTag ActorCleanupGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter Success")
	TArray<FName> SuccessRewards;

	UPROPERTY(EditAnywhere, Category="Encounter Success", meta=(DisplayName="Success Reward Motion"))
	FEncounterRewardBehavior SuccessRewardBehavior;

	UPROPERTY(EditAnywhere, Category="Encounter Success")
	FGameplayCueTag ActorSuccessGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter Success")
	FGameplayCueTag PlayerSuccessGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter Failure")
	TArray<FName> FailureRewards;

	UPROPERTY(EditAnywhere, Category="Encounter Failure", meta=(DisplayName="Failure Reward Motion"))
	FEncounterRewardBehavior FailureRewardBehavior;

	UPROPERTY(EditAnywhere, Category="Encounter Failure")
	FGameplayCueTag ActorFailureGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter Failure")
	FGameplayCueTag PlayerFailureGameplayCueTag;

	UPROPERTY(EditAnywhere, Category="Encounter Density")
	FScalableFloat LWMDensityWeight;

	UPROPERTY(EditAnywhere, Category="Encounter Density")
	FScalableFloat LWMDensityRange;

	UPROPERTY(EditAnywhere, Category="Encounter Variables", meta=(BaseStruct="/Script/EncountersRuntime.EncounterVariable", ExcludeBaseStruct))
	TArray<FInstancedStruct> Vars;

	UPROPERTY(EditAnywhere, Category="Encounter Variables", meta=(BaseStruct="/Script/EncountersRuntime.EncounterVariableSelections", ExcludeBaseStruct))
	TArray<FInstancedStruct> VariableSelections;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FWorldConditionQueryDefinition CanSpawnWorldConditionDefinition;

};

