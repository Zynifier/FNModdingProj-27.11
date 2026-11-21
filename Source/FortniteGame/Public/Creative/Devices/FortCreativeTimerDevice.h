// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Creative/FortCreativeDeviceProp.h"
#include "Creative/FortTimeWidgetInterface.h"
#include "FortCreativeTimerDevice.generated.h"

class AController;
class AFortGameState;
class AFortVolume;
enum class ETimerDeviceState : uint8;

UENUM(BlueprintType)
enum class ETimerDeviceState : uint8
{
	/** Idle, awaiting activation to start timer */
	Enabled = 0,
	/** Timer running */
	Activated = 1,
	/** Timer paused */
	Paused = 2,
	/** Completed and awaiting reset/restart */
	Completed = 3,
	/** Ongoing timer paused and ignore all commands other than enable */
	Disabled = 4,
	MAX = 5 UMETA(Hidden),
};

USTRUCT()
struct FTimerDeviceTrackedTimer
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeTimerDevice : public AFortCreativeDeviceProp, public IFortTimeWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void AddTimerDeviceToVolume();

	UFUNCTION(BlueprintCallable)
	void BroadcastUpdateToHUD();

	UFUNCTION(BlueprintImplementableEvent)
	void ClearDisplay();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ClearTrackedTimers();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void CreateTrackedTimer(AController* PlayerController, ETimerDeviceState StartingState = ETimerDeviceState::Enabled);

	UFUNCTION(BlueprintImplementableEvent)
	void DisplayUpdate(uint8 CurrentState, float ServerTimeFinished);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float GetTimerRemaining(AController* TrackedPlayer) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool GetTimerState(AController* TrackedPlayer, ETimerDeviceState& OutState) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	int32 GetTrackedPlayers(TArray<AController*>& OutTrackedPlayers) const;

	UFUNCTION()
	void OnGameStateSet(AFortGameState* GameState);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnServerDisplayUpdateTimerCompleted(AController* TrackedPlayer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnTimerCompleted(AController* TrackedPlayer);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnTimerStateChanged(AController* TrackedPlayer, const FTimerHandle& TimerHandle, ETimerDeviceState CurrentState, ETimerDeviceState PreviousState, bool bLoadingFromSave);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly)
	void OnUrgencyTimeReached(AController* TrackedPlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveTrackedTimer(AController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ServerRequestClearDisplay(const TArray<AController*>& PlayersToUpdate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ServerRequestDisplayUpdate(AController* TrackedPlayer, const TArray<AController*>& PlayersToUpdate);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TimerClearHandles(AController* TrackedPlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TimerPause(AController* TrackedPlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TimerResume(AController* TrackedPlayer);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TimerSetState(AController* TrackedPlayer, ETimerDeviceState NewState, bool bLoadingFromSave = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TimerStart(AController* TrackedPlayer, float Duration, float TimeUntilUrgency);

protected:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeTimerDevice")
	ETimerDeviceState ClientCurrentState;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeTimerDevice")
	FString ClientCurrentSecondaryText;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeTimerDevice")
	FName ClientTimerTextStyle;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeTimerDevice")
	bool bClientShowOnHud;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortCreativeTimerDevice")
	int32 ClientCurrentTime;

	UPROPERTY(BlueprintReadWrite, Category="FortCreativeTimerDevice")
	float ServerDisplayUpdateRate;

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> Volume;

};

