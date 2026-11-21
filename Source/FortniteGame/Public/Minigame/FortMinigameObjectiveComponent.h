// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Minigame/FortMinigameLogicComponent.h"
#include "FortMinigameObjectiveComponent.generated.h"

class UFortMinigameObjectiveComponent;
enum class EObjectiveType : uint8;

UENUM(BlueprintType)
enum class EObjectiveType : uint8
{
	DestructionObjective = 0,
	CaptureObjective = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameObjectiveUpdated, UFortMinigameObjectiveComponent*, Objective);

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Minigame"), meta=(BlueprintSpawnableComponent))
class UFortMinigameObjectiveComponent : public UFortMinigameLogicComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void SetIsInteractionAllowed(bool bInIsInteractionAllowed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void SetTrackedProgress(float Percentage);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void SetTrackedState(uint8 InState, uint8 InStateOwnerTeam);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void StartTracking(int32 IndicatorPresetIndex, float Percentage = 0.000000f, EObjectiveType Type = EObjectiveType::DestructionObjective, uint8 State = 0, uint8 StateOwnerTeam = 0, bool bInIsInteractionAllowed = true);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Minigame | Objective")
	void StopTracking(bool bPurgeHistory, float Percentage = 0.000000f);

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameObjectiveUpdated OnObjectiveUpdated;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameObjectiveUpdated OnObjectiveStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Minigame | Objective")
	FMinigameObjectiveUpdated OnObjectiveAllowedInteractionChanged;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	int32 TrackedIndex;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	float ProgressPercentage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	uint8 TrackedState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	uint8 TrackedStateOwnerTeam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	bool bIsInteractionAllowed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Minigame | Objective")
	EObjectiveType ObjectiveType;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Minigame | Objective")
	int32 ObjectiveSortOrder;

	UPROPERTY(EditDefaultsOnly, Category="Minigame | Objective")
	bool bPurgeTrackingHistoryOnRemoval;

};

