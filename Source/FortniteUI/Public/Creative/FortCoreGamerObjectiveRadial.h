// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Minigame/FortMinigameObjectiveTrackerComponent.h"
#include "FortCoreGamerObjectiveRadial.generated.h"

class AFortMinigame;
class UFortMinigameObjectiveTrackerComponent;
enum class ECaptureState : uint8;
enum class EFortMinigameState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCoreGamerObjectiveRadial : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCoreGamerObjectiveRadial(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	float GetNormalizedDistanceFromScreenCenter();

	UFUNCTION(BlueprintPure, Category="InWorldIcon")
	bool IsUsingGameCamera() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnMinigameStateChanged(const EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveBecameNeutral();

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveBeingCaptured(const uint8 CapturingTeam, const float Percentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveBeingDecaptured(const uint8 DecapturingTeam, const float Percentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveBeingDeneutralized(const uint8 DeneutralizingTeam, const float Percentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveBeingNeutralized(const uint8 NeutralizingTeam, const float Percentage);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveCaptured(const uint8 OwningTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveContested();

	UFUNCTION(BlueprintImplementableEvent)
	void OnObjectiveDisabled();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnObjectiveOwningTeamChanged(const uint8 NewTeam, const uint8 OldTeam, const bool bForceUpdate = false);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTrackedObjectiveSet(const FTrackedObjective& NewTrackedObjective);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTrackedObjectiveUpdated(const FTrackedObjective& CurrentTrackedObjective);

protected:
	UFUNCTION(BlueprintPure)
	AFortMinigame* GetMinigame() const;

	UFUNCTION(BlueprintPure)
	UFortMinigameObjectiveTrackerComponent* GetObjectiveTracker() const;

	UFUNCTION()
	void HandleTrackedObjectiveTeamUpdated(int32 InTrackedIndex);

	UFUNCTION()
	void HandleTrackedObjectiveUpdated(int32 InTrackedIndex);

	UFUNCTION(BlueprintCallable)
	void UpdateCaptureState(const ECaptureState NewCaptureState, const ECaptureState OldCaptureState, const uint8 TrackedStateOwnerTeam, const float Progress);

	UPROPERTY(BlueprintReadOnly, Category="FortCoreGamerObjectiveRadial")
	int32 TrackedIndex;

};

