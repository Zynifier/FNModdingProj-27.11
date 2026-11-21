// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/FortAIAnimInstance.h"
#include "Animation/FortAnimInstance.h"
#include "FortAIFaunaAnimInstance.generated.h"

USTRUCT(BlueprintType)
struct FRidingAnimationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsRidden;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsTurningInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsBeingPetted;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	bool bIsMovingBackwards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float TurnInPlaceRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float TurnInPlaceAngleDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	float RiderReferentialYaw;

};

UCLASS(NonTransient, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class IRWINRUNTIME_API UFortAIFaunaAnimInstance : public UFortAIAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CalculateLookAtAlpha(bool bForceDisableLookAt, float DeltaSeconds);

	UFUNCTION(BlueprintNativeEvent)
	void FinishFootPhaseStopUpdate();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBackwardsPlayRate();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBackwardVelocity();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBodyRoll();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateBoostPlayRate();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateFootPhaseStop();

	UFUNCTION(BlueprintNativeEvent)
	void UpdatePlayLandAdditive();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateRidingMovePlayRate();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateSwimmingYaw();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateTurnAngleStored();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	float AverageSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna", meta=(ClampMin="0.0"))
	float AverageSpeedTimeFrame;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	bool bHasValidAimTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna", meta=(ClampMin="0.0"))
	float AimTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	FVector AimTargetLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsSurfaceSwimming;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsMovingOnGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsInTornado;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Fauna")
	float LookAtAlpha;

	UPROPERTY(EditAnywhere, Category="Fauna")
	float MaxDistanceToPlayerForLookAt;

	UPROPERTY(EditAnywhere, Category="Fauna")
	float LookAtTooFarFromPlayerTimeOut;

	UPROPERTY(EditAnywhere, Category="Fauna")
	bool bDisableLookAtDuringMontage;

	UPROPERTY(EditAnywhere, Category="Fauna")
	FName DisableHeadTrackingCurveName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding")
	FRidingAnimationData RidingAnimationData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	bool bIsSlopeSliding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingPitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SlopeSliding")
	float SlopeSlidingRoll;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	float RidingMovePlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bJustGotPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsBoosting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsTurningInPlace;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float TurnInPlaceRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float TurnInPlaceAngleDelta;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bIsMovingBackwards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float RiderReferentialYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float BoostPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Riding")
	bool bIsTurnInPlaceAngleDeltaPositive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding")
	bool bPlayLandAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float BackwardVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bShouldPlayStopBackwards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float SwimmingYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float BackwardsPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float BodyRoll;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	float TurnAngleStored;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Riding")
	bool bWasTurningRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase")
	ERidingFootPhase FootPhase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_FeetInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_FrontFeetPlanted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_BackFeetPlanted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_LeftBackFeetForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_RightBackFeetForward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_LeftPlantedRightPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Riding|Foot Phase|Conduit Values")
	bool bIsFootPhase_RightPlantedLeftPass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna|Gameplay Tags")
	FGameplayTagContainer SlipstreamTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsInSlipstream;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna|Gameplay Tags")
	FGameplayTagContainer SkydivingTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna|Gameplay Tags")
	bool bMovementMode_Skydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna|Gameplay Tags")
	FGameplayTagContainer SkytubingTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna|Gameplay Tags")
	bool bGameplay_Status_Skytubing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsAbducted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fauna|Gameplay Tags")
	FGameplayTagContainer TractorBeamTags;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna|Gameplay Tags")
	bool bIsInTractorBeam;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Fauna")
	bool bIsFloating;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Settings")
	float JustGotPlayerInitialDelaySec;

protected:
	UPROPERTY(EditDefaultsOnly, Category="AI")
	float FallAsleepAnimDuration;

	UPROPERTY(EditDefaultsOnly, Category="AI")
	float WakeUpAnimDuration;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(ClampMin="0.0"))
	float FallAsleepToSleepingCrossfade;

	UPROPERTY(EditDefaultsOnly, Category="AI", meta=(ClampMin="0.0"))
	float WakeUpToIdleCrossfade;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_FallAsleepToSleeping : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_SleepingToWakeUp : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_WakeUpToIdle : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Transitions")
	uint8 StateTransition_IdleToFallAsleep : 1;

};

