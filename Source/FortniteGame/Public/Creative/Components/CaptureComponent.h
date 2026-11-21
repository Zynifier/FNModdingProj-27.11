// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CaptureComponent.generated.h"

enum class ECaptureState : uint8;

UENUM(BlueprintType)
enum class ECaptureState : uint8
{
	/** Zone is uncaptured */
	Neutral = 0,
	/** Zone is actively being captured */
	Capturing = 1,
	/** Zone is contested (members from multiple teams are in the zone) */
	Contested = 2,
	/** Zone is disabled */
	Disabled = 3,
	/** An uncaptured zone's capture progress is winding back down to zero */
	Decapturing = 4,
	/** A captured zone's progress is being depleted by another team */
	Neutralizing = 5,
	/** Zone was previously neutralized but is now recovering back to fully captured */
	Deneutralizing = 6,
	/** Zone is captured by a team */
	Captured = 7,
};

UENUM()
enum class ESmoothProgressState : uint8
{
	Enabled = 0,
	DisabledByState = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCaptureProgressUpdate, float, NewProgress);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCaptureStateChangedEvent, ECaptureState, NewCaptureState, ECaptureState, PreviousCaptureState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOwningTeamChanged, uint8, OwningTeam, uint8, PreviousOwningTeam);

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UCaptureComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void ForceCaptureProgress(float NewCaptureProgress);

	UFUNCTION(BlueprintPure, Category="CaptureComponent")
	ECaptureState GetCaptureState() const;

	UFUNCTION(BlueprintPure, Category="CaptureComponent")
	uint8 GetCaptureStateOwner() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void SetCaptureSpeedBoost(float NewCaptureSpeedBoost);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void SetCaptureSpeedBoostEmoting(float NewCaptureSpeedBoostEmoting);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void SetCaptureState(ECaptureState NewCaptureState, uint8 TriggerTeamIndex);

	UFUNCTION(BlueprintCallable, Category="CaptureComponent")
	void SetCaptureTime(float NewCaptureTime);

	UFUNCTION(BlueprintCallable, Category="CaptureComponent")
	void SetNeutralizingTime(int32 NewNeutralizingSpeed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void SetProgressDecaySpeed(float NewProgressDecaySpeed);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void UpdateCaptureSpeed(int32 NumOfPlayers, int32 NumOfEmotingPlayers);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="CaptureComponent")
	void UpdateProgressReverseSpeed(int32 NumOfPlayers, int32 NumOfEmotingPlayers);

private:
	UFUNCTION()
	void OnRep_CaptureProgress();

	UFUNCTION()
	void OnRep_CaptureState(ECaptureState OldCaptureState);

	UFUNCTION()
	void OnRep_OwningTeam(const uint8 PreviousOwningTeam);

	UFUNCTION()
	void OnRep_SmoothProgressState();

	UFUNCTION()
	void UpdateSmoothProgressStateByCaptureState();

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnCaptureStateChangedEvent OnCaptureStateChanged;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnCaptureProgressUpdate OnCaptureProgressUpdate;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnOwningTeamChanged OnOwningTeamChanged;

	UPROPERTY(Transient)
	float OldSmoothedProgress;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	float SmoothedProgress;

	UPROPERTY(Transient)
	float SmoothProgressTimer;

	UPROPERTY(Transient)
	float ProgressDecaySpeed;

	UPROPERTY(Transient)
	float ProgressReverseSpeed;

	UPROPERTY(Transient)
	int32 CurrentCaptureSpeed;

	UPROPERTY(Transient)
	float CaptureSpeedBoost;

	UPROPERTY(Transient)
	float CaptureSpeedBoostEmoting;

	UPROPERTY(Transient)
	int32 NeutralizingTime;

	UPROPERTY(Transient)
	int32 DeneutralizingSpeed;

	UPROPERTY(Transient)
	float CaptureTime;

	UPROPERTY(Transient)
	float CaptureTimeCurrent;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	ECaptureState PreviousCaptureState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	uint8 CapturingStateOwner;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	uint8 NeutralizingStateOwner;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	uint8 StateOwner;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_OwningTeam, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	uint8 OwningTeam;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CaptureState)
	ECaptureState CaptureState;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CaptureProgress, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	float CaptureProgress;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_SmoothProgressState, Category="CaptureComponent", meta=(AllowPrivateAccess="true"))
	ESmoothProgressState SmoothProgressState;

};

