// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "KoalaHUDWidget.generated.h"

class AFortPawn;
class AFortPlayerStateAthena;
class UCommonActionWidget;
class UFortItemDefinition;
class USoundSubmix;
enum class EKoalaAvailability : uint8;
enum class EKoalaClipStatus : uint8;
enum class EKoalaConnectionStatus : uint8;
enum class EKoalaRecording : uint8;

UENUM(BlueprintType)
enum class EKoalaAvailability : uint8
{
	Pending = 0,
	NotAvailable = 1,
	Available = 2,
	COUNT = 3 UMETA(Hidden),
};

UENUM()
enum class EKoalaClipEventType : uint8
{
	Manual = 0,
	Elimination = 1,
	VictoryRoyale = 2,
	Emote = 3,
	COUNT = 4 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EKoalaClipStatus : uint8
{
	None = 0,
	Creating = 1,
	Uploading = 2,
	Completed = 3,
	Failed = 4,
	COUNT = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EKoalaConnectionStatus : uint8
{
	Pending = 0,
	NotConnected = 1,
	Connected = 2,
	COUNT = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EKoalaMockClipMode : uint8
{
	None = 0,
	ShortSuccess = 1,
	ShortFailure = 2,
	LongSuccess = 3,
	LongFailure = 4,
	COUNT = 5 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EKoalaRecording : uint8
{
	Pending = 0,
	NotRecording = 1,
	Recording = 2,
	COUNT = 3 UMETA(Hidden),
};

USTRUCT(BlueprintType)
struct FKoalaClipInfo
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UKoalaHUDWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	int32 GetTrackedClipCount();

	UFUNCTION(BlueprintPure)
	int32 GetUploadingClipCount() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnAvailabilityChanged(EKoalaAvailability Availability);

	UFUNCTION(BlueprintImplementableEvent)
	void OnClipStatusChanged(int32 InClipID, EKoalaClipStatus InClipStatus, float InUploadProgress);

	UFUNCTION(BlueprintImplementableEvent)
	void OnConnectionChanged(EKoalaConnectionStatus InStatus);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInputProgress(float Progress);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRecordingStatusChanged(EKoalaRecording InRecordingStatus);

	UFUNCTION(BlueprintCallable)
	void OnReminderEnded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnReminderTimerStarted(float Time);

	UFUNCTION(BlueprintCallable)
	void OnTouchAreaMouseDown();

	UPROPERTY(EditDefaultsOnly, Category="KoalaHUDWidget")
	float ClipDebounceTime;

	UPROPERTY(EditDefaultsOnly, Category="Clip Reminders")
	float PlayerKilledPlayerReminderTime;

	UPROPERTY(EditDefaultsOnly, Category="Clip Reminders")
	float MatchEndedReminderTime;

	UPROPERTY(EditDefaultsOnly, Category="Clip Reminders")
	float ClipReminderCooldownTime;

	UPROPERTY(EditDefaultsOnly, Category="Clip Reminders")
	float EliminationClipReminderDelayTime;

	UPROPERTY(EditDefaultsOnly, Category="Sanitization")
	TObjectPtr<USoundSubmix> ClipAudioSubmix;

private:
	UFUNCTION()
	void HandleLocalPlayerKilledPlayer(const AFortPlayerStateAthena* Player);

	UFUNCTION()
	void HandlePlayerMatchWon();

	UFUNCTION()
	void HandlePlayerPawnEmoteStopped(const UFortItemDefinition* MontageItemDef, AFortPawn* PawnEmoting);

	UFUNCTION()
	void RegisterClipButtonInput();

	UFUNCTION()
	void UnregisterClipButtonInput();

	UPROPERTY(BlueprintReadOnly, Export, Category="KoalaHUDWidget", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ClipActionWidget;

	UPROPERTY(EditAnywhere, Category="KoalaHUDWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClipObjectInputAction;

	UPROPERTY()
	TMap<int32, FKoalaClipInfo> ClipTracker;

	UPROPERTY(meta=(AllowPrivateAccess="TRUE"))
	int32 LastClipID;

	UPROPERTY(EditDefaultsOnly, Category="Mock Clip Behavior", meta=(AllowPrivateAccess="TRUE"))
	EKoalaMockClipMode MockClipMode;

	UPROPERTY(EditDefaultsOnly, Category="Mock Clip Behavior", meta=(AllowPrivateAccess="TRUE"))
	int32 MockClipUploadShortTime;

	UPROPERTY(EditDefaultsOnly, Category="Mock Clip Behavior", meta=(AllowPrivateAccess="TRUE"))
	int32 MockClipUploadLongTime;

	UPROPERTY(EditDefaultsOnly, Category="Mock Clip Behavior", meta=(AllowPrivateAccess="TRUE"))
	int32 MockClipCreateShortTime;

	UPROPERTY(EditDefaultsOnly, Category="Mock Clip Behavior", meta=(AllowPrivateAccess="TRUE"))
	int32 MockClipCreateLongTime;

};

