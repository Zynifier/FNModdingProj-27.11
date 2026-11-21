// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortMotorcycleVehicle.h"
#include "FortPlayerAnimInstance_MotorcycleRider.generated.h"

class AFortMotorcycleVehicle;
class AFortPlayerPawn;
class UFortMotorcycleVehicleAnimInstance;
enum class EFortMotorcycleAirTrickType : uint8;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_MotorcycleRider : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION()
	MOTORCYCLERUNTIME_API void AnimNotify_JumpEntered();

	UFUNCTION(BlueprintCallable, Category="Motorcycle Rider")
	MOTORCYCLERUNTIME_API void CalculateNoiseAlpha();

	UFUNCTION(BlueprintCallable, Category="Motorcycle Rider")
	MOTORCYCLERUNTIME_API void CollapsedAimYawSmoothed(float DeltaSeconds);

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleCancelChargingJump();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleChargingJump(const float InJumpChargeFactor);

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleFinishAirTrick();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleJump(const float InJumpChargeFactor);

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleReleaseStoppie();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleReleaseWheelie();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleStartAirTrick(const EFortMotorcycleAirTrickType TrickType);

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleStartChargingJump();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleStartStoppie();

	UFUNCTION()
	MOTORCYCLERUNTIME_API void HandleStartWheelie();

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	TObjectPtr<AFortMotorcycleVehicle> Motorcycle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	TObjectPtr<UFortMotorcycleVehicleAnimInstance> MotorcycleAnimInstance;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Motorcycle Rider")
	FFortAnimInput_Motorcycle MotorcycleInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	TObjectPtr<AFortPlayerPawn> FortPlayerPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	FVector WorldVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	FVector LocalVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	float RightHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	float Speed2D;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	EFortCardinalDirection LocomotionCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	EFortCardinalDirection PrePivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	uint8 bShouldPlayJogPivotTransition : 1;

	UPROPERTY(Transient)
	uint8 bPivotTransitionDoOnceTriggered : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	uint8 bIsJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_MotorcycleRider")
	uint8 bIsReloading : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FRotator RiderCatchupRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float RiderZDisplacement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderDisplacementDampUpFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderDisplacementDampDownFactor;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderDisplacementLandingFallDistanceThreshold;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderMinDisplacement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderMaxDisplacement;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderDisplacementRampPerSecond;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Motorcycle Rider")
	float RiderRotationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FVector ImpactDisplacement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float AbsSteerAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float LeanAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float FallDistanceValue;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FVector FootTraceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float FootTraceSideOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float MaxFootLocationDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle Rider")
	bool bHasFootTrace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsInRollAngleThreshold;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsDriveStarting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector LocalLeftOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FVector WorldPosLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FRotator LocalRotLeftOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FRotator WorldRotLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector LocalRightOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FVector WorldPosRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FRotator LocalRotRightOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	FRotator WorldRotRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsSteeringRotating;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsStopped;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsIdle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Rider")
	float IdleSpeedKmh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsSlowingDown;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsDrivingFast;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsTurningRightHard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsTurningLeftHard;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float JumpPlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsJumpFlipping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bShouldEnableAO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsBodyDragging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float FallDistanceJumpingThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float FallDistanceJumpTrickThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float RollAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float StartSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float SlowingSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float FastSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float BrakingDeltaThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float SteerHardAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float GroundTraceUpOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float GroundTraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector2D JumpPlayRateInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector2D JumpPlayRateOutRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float JumpChargeFactor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsChargingJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsMotorcycleJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bMotorcycleLaunchedJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bWheelie;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bStoppie;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	EFortMotorcycleAirTrickType AirTrickType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsJumpingAndNotRolling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsOnGroundAndNotRolling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsOnGroundAndBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bPlayPivotOnGroundAndNotBoosting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bIsPowerSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float PowerSlideSteeringAngleThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	float PowerSlideSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector2D LandStartPosInRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider")
	FVector2D LandStartPosOutRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	float LandStartPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider")
	bool bShouldPawnStandUp;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsSmoothingYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float AimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float AimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float AimYawLastFrame;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float AimYawSmoothed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float BodyAimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float NegativeBodyAimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float ForwardSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float PreviousForwardSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float TotalSpeed;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsReversing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsUsingConsumable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Rider|Nativized")
	FCachedAnimRelevancyData IntroCachedTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float StoppieLandTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bShouldPlayHitReact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsPlayingMontage;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float VehiclePitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float VehicleRoll;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	FRotator MeleeTwistRot;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bStateTransitionRuleToMovingLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float UpperBodyAdditiveAlpha;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Motorcycle Rider|Nativized")
	float UpperBodyAdditiveStrength;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	float MovingNoisePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Rider|Nativized")
	bool bIsFemale;

};

