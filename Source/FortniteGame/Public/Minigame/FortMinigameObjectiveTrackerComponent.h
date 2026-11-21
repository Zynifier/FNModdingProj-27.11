// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortMinigameObjectiveTrackerComponent.generated.h"

class UFortMinigameObjectiveComponent;
enum class ETrackedObjectiveQuery : uint8;

UENUM(BlueprintType)
enum class ETrackedObjectiveQuery : uint8
{
	All = 0,
	ExactTeam = 1,
	Friendly = 2,
	Neutral = 3,
	Hostile = 4,
	NotFriendly = 5,
	MAX = 6 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameTrackedObjectiveUpdated, int32, TrackedIndex);

USTRUCT(BlueprintType)
struct FTrackedObjective : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	int32 TrackedIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 TeamIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 OldTeamIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	int32 IndicatorPresetIndex;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	int32 ObjectiveSortOrder;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	float ProgressPercentage;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 TrackedState;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 TrackedStateOwnerTeam;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 OldTrackedState;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	uint8 ObjectiveType;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	bool bIsInteractionAllowed;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="TrackedObjective")
	bool bOldIsInteractionAllowed;

};

USTRUCT()
struct FTrackedObjectiveArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleInstanceOnly, Transient, Category="TrackedObjectiveArray")
	TArray<FTrackedObjective> Objectives;

	UPROPERTY(Transient)
	int32 NextTrackedIndex;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameObjectiveTrackerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void ClearTrackedObjectives();

	UFUNCTION(BlueprintPure, Category="Minigame | Objective")
	bool GetTrackedObjective(int32 TrackedIndex, FTrackedObjective& TrackedObjective) const;

	UFUNCTION(BlueprintPure, Category="Minigame | Objective")
	bool GetTrackedObjectivesByQuery(TArray<FTrackedObjective>& TrackedObjectives, uint8 TeamIndex, ETrackedObjectiveQuery QueryType) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	int32 StartTrackingObjective(UFortMinigameObjectiveComponent* Objective, int32 IndicatorPresetIndex);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void StopTrackingObjective(UFortMinigameObjectiveComponent* Objective, bool bPurgeHistory);

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveAdded;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveRemoved;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveAllowedInteractionChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameTrackedObjectiveUpdated OnTrackedObjectiveTeamUpdated;

protected:
	UFUNCTION()
	void HandleMinigameEnded();

	UFUNCTION()
	void SetIsInteractionAllowed(UFortMinigameObjectiveComponent* Objective);

	UFUNCTION()
	void SetTrackedState(UFortMinigameObjectiveComponent* Objective);

	UFUNCTION()
	void UpdateTrackedProgress(UFortMinigameObjectiveComponent* Objective);

	UPROPERTY(VisibleInstanceOnly, Transient, Replicated, Category="FortMinigameObjectiveTrackerComponent")
	FTrackedObjectiveArray ObjectiveArray;

};

