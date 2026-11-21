// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "AI/FortAITypes.h"
#include "Movement/FortCharacterMovementTypes.h"
#include "Pawns/FortPawnMovementOverridesSubsystem.h"
#include "FortMovementComp_Character.generated.h"

class AActor;
class AFortPawn;
class IFortAthenaAILODSettings;
class UCharacterMovementComponent;
class UCurveFloat;
class UFortMovementMode_BaseExtLogic;
class UFortSurfaceTrackingComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterMovementPreUpdateSignature, UCharacterMovementComponent*, CharMoveComp, float, DeltaSeconds);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPostPhysicsRotationDelegate, UCharacterMovementComponent*, CharMoveComp, float, DeltaSeconds);

USTRUCT(BlueprintType)
struct FAirControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat LateralFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxLateralSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat TerminalVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat UpwardTerminalVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams")
	FScalableFloat GravityScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat CustomGravityCeiling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AirControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat CustomGravityCeilingWidth;

};

USTRUCT(BlueprintType)
struct FFlyingRidableControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat AirFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat FluidFriction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat MaxAccelerationBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat BaseAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat BaseAccelerationBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat PitchForMaxBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat PitchForMinBoost;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FVector AscendingAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FVector IdleAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat MovingTurnRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FlyingRiddenControls")
	FScalableFloat IdleTurnRate;

};

USTRUCT(BlueprintType)
struct FGoopControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat DragHorizontalPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat DragVerticalPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat DragHorizontalFlat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat DragVerticalFlat;

};

USTRUCT(BlueprintType)
struct FRidableControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat GroundRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat SprintGroundRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat AirRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat SwimmingRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat TurnInPlaceRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat HalfDeadzone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat TurnInPlaceStartAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat TimeBeforeTurnInPlaceAllowed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat TimeBeforeInputsReleasedConsidered;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat BackwardsHalfDeadzone;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat MinimumInputAnalogModifier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat SprintStopSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RiddenControls")
	FScalableFloat MinimumJumpHoldTime;

};

USTRUCT()
struct FRidableControlRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FRotator RidingControllerRotation;

	UPROPERTY(Transient)
	float DesiredTurnInPlaceAngle;

	UPROPERTY(Transient)
	bool bDesiredTurnInPlaceAngleSet;

	UPROPERTY(Transient)
	bool bIsRidingSprinting;

	UPROPERTY(Transient)
	float PreviousControlYaw;

	UPROPERTY(Transient)
	bool bMovingBackwards;

	UPROPERTY(Transient)
	float RiderReferentialYaw;

	UPROPERTY(Transient)
	bool bAscending;

	UPROPERTY(Transient)
	bool bIsRidingPetting;

};

USTRUCT(BlueprintType)
struct FSlidingControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinAnalogSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BrakingDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WalkableFloorAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlidingIsEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinSpeedToStartSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat UphillSlideStartBoost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat LevelSlideStartBoost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat DownhillSlideStartBoost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMax="90", ClampMin="0", UIMax="90", UIMin="0"))
	FScalableFloat MaxSlidingSlopeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	FScalableFloat BoostUphillGroundFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	FScalableFloat BoostLevelGroundFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	FScalableFloat UphillGroundFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	FScalableFloat LevelGroundFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	FScalableFloat DownhillGroundFrictionMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxForwardSlidingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxLateralSlidingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinForwardSlidingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxForwardSlidingAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxLateralSlidingAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxBackwardSlidingAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlidingFatigueDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlidingFatigueMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat EnterSlideFromFallInputBuffer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat CrouchCooldownAfterSlideDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	bool bUncrouchAfterSlidingIfMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	float MinAccelerationSlidingAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinAngleForAdditionalMomentum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinAdditionalMomentum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxAdditionalMomentum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	bool bClampMaximumSpeedToEntryDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	bool bUsePhysicsSlidingDownSlopeImpulsion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FallingGracePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat LandingVelocityReductionRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	bool UseAccelerationRotateVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxRotationAngleOnAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat RotationAngleSpeedOnAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlopeUpAddedFrictionAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlopeUpAddedFrictionValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SlidingVerticalVelocityConvertedOnLanding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	TObjectPtr<UCurveFloat> SlidingLandingSpeedTransferRatioCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat SlidingUseSlopeAngleForVerticalVelocityTransferRatio;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams")
	TObjectPtr<UCurveFloat> SlidingSpeedAddedFrictionCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat SlidingRentryFromJumpPenalty;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat JumpSlideCapsuleRadiusDetectionRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat JumpSlideCapsuleHeightClearanceCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMax="90", ClampMin="0", ForceUnits="deg", UIMax="90", UIMin="0"))
	FScalableFloat JumpSlideAllowedSurfaceAngleDeviation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMin="0", ForceUnits="cm/s", UIMin="0"))
	FScalableFloat MinSpeedToStartJumpSliding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SlidingControlParams", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat JumpSlideSweepHeightShrinkCoefficient;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SlidingControlParams")
	uint8 SlidingFatigueMaxCount;

};

USTRUCT(BlueprintType)
struct FSwingingControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	TObjectPtr<UCurveFloat> ReelForceByRopeLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ReelingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ReelingSpeedGrounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ReelingSpeedGroundedAttachedVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxReelingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat InputAccelMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat InputAccelMultiplierAirbornUnattached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AirbornUnattachedInputFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat LengthForMaxReelForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxHorizontalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxHorizontalSpeedGrounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxHorizontalSpeedGroundedAttachedVehicle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat SwingGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat GravityMultiplierWhileAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedBraking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedCounterInput_MaxDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedCounterInput_MinDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedCounterInput_MaxDot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedGroundedCounterInput_MinDot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AttachedNoAccelFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AttachedNoAccelBraking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AttachedGroundedSwingingFriction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AttachedGroundedSwingingBraking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat UnattachedCancelSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MinTimeDetachedForExit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat AdditionalDownAccelWhileSwinging;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat VerticalDistanceToAttachPointToLeaveGround;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat JumpZVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat WaterMaxImmersionPercent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat WaterUpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat DefaultForwardInputAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat InitialAttachedSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat GroundTraceDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat DistanceThresholdForGrounded;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat SpeedForMaxInputAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MinInputAccelMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MinRopeLengthForAccel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ClampPosVerticalSpeedWhileAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxAttachedPosVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ClampNegVerticalSpeedWhileAttached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxAttachedNegVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ClampPosVerticalSpeedWhileUnattached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxUnattachedPosVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat ClampNegVerticalSpeedWhileUnattached;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat MaxUnattachedNegVerticalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Swinging")
	FScalableFloat bDisableGroundedSwingingCalculations;

};

USTRUCT(BlueprintType)
struct FWaterControlParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinImmersionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat TargetImmersionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxImmersionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat CancelCrouchImmersionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat DBNOSwimImmersionDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxAcceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxAccelerationSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BrakingDeceleration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxNormalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxSprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MinSprintJumpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMax="180", ClampMin="0", UIMax="180", UIMin="0"))
	FScalableFloat SprintJumpAirAccelAngleLimit;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SprintRetriggerDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat SprintDelayAfterFiring;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxTargetingSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BackwardsSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BackwardsSpeedCosAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat AngledSpeedMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat AngledSpeedCosAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat Friction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrictionSprinting;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="-1", UIMin="-1"))
	FScalableFloat FrictionDirectionChangeDot;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FrictionDirectionChangeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxSpeedUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxSpeedDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxHorizontalEntrySpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WaterForceMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WaterForceSecondMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxWaterForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WaterVelocityDepthForMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat WaterVelocityMinMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0.0333", UIMin="0.0333"))
	FScalableFloat WaterSimMaxTimeStep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0.0333", UIMin="0.0333"))
	FScalableFloat WaterSimSubStepTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingMaxForce;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingIdealDepthTolerance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingFrictionDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingExpDragDown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingFrictionDownSubmerged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingExpDragDownSubmerged;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingFrictionUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat BobbingExpDragUp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControlParams", meta=(ClampMin="1", UIMin="1"))
	FScalableFloat BoostDragMultiplier;

};

USTRUCT(BlueprintType)
struct FWaterJumpParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WaterJumpParams", meta=(ClampMin="-1000", UIMin="-1000"))
	FScalableFloat WaterJumpMinVelocityZ;

	UPROPERTY(EditAnywhere, Category="WaterJumpParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WaterJumpMaxVelocityZ;

	UPROPERTY(EditAnywhere, Category="WaterJumpParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat WaterJumpForceZ;

	UPROPERTY(EditAnywhere, Category="WaterJumpParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat JumpForceDuration;

};

USTRUCT(BlueprintType)
struct FWaterSprintBoostParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat RequiredDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat TriggerAboveDepth;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat TriggerAtVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat PreventAtVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat Duration;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoostParams", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat MaxSpeed;

};

UCLASS(MinimalAPI)
class UFortMovementComp_Character : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetFallingStartedZ() const;

	UFUNCTION(BlueprintPure, Category="Rotation")
	bool GetModifiedOrientRotationToMovement() const;

	UFUNCTION(BlueprintPure, Category="Rotation")
	bool GetModifiedUseControllerDesiredRotation() const;

	UFUNCTION(BlueprintPure, Category="Swimming")
	FVector GetPlayerRelativeVelocityToWater() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FSlidingControlParams GetSlidingControlParams() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool GetSwingAttached() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool GetSwingAttachedVehicle() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	const FSwingingControlParams& GetSwingingControlParameters() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	float GetSwingingDistanceToGround() const;

	UFUNCTION(BlueprintPure, Category="Swimming")
	float GetWaterImmersionDepth() const;

	UFUNCTION(BlueprintPure, Category="Swimming")
	FVector GetWaterSurfaceLocation() const;

	UFUNCTION(BlueprintPure, Category="Swimming")
	FVector GetWaterSurfaceNormal() const;

	UFUNCTION(BlueprintPure, Category="Swimming")
	FVector GetWaterVelocity() const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsActivelyParachuting() const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsActivelySkydiving(const bool bCheckMovementMode = true) const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsActivelySkydivingUpInVortex() const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsActivelyStrafingInAir(const bool bCheckMovementMode = true) const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsPassivelyParachuting() const;

	UFUNCTION(BlueprintPure, Category="AthenaAirControl")
	bool IsPassivelySkydiving() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool IsSwingingAir() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool IsSwingingGround() const;

	UFUNCTION(BlueprintCallable, Category="Swinging")
	bool SetActiveOverrideSwingingControlParameters(const FGameplayTag ControlParametersTag);

	UFUNCTION(BlueprintCallable, Category="Quest Cheats")
	void SetFromBusForTesting(const bool bInShouldBeFromBus);

	UFUNCTION(BlueprintCallable, Category="Acceleration")
	void SetHasReplicatedAcceleration(const bool bInHasReplicatedAcceleration);

	UFUNCTION(BlueprintCallable, meta=(BlueprintSetter))
	void SetSlidingControlParams(FSlidingControlParams NewSlidingControlParams);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="NetTolerance")
	void SetUseHighAccelerationTolerance(const bool bShouldUseHighTolerance, const FName UseHighToleranceId = NAME_None);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	float LandHardSoundFallSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	float LandSoundFallSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	TSubclassOf<AFortPawn> PushBumpedPawnClass;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	float NetworkSmoothingVisibilityThreshold;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	int32 NetworkSmoothingThrottleProxyUpdateForPawnLOD;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	float NetworkSmoothingViewAngleThreshold;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	float NetworkSmoothingViewAngleThresholdSmall;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	float NetworkSmoothingNoThrottleWithinDistanceInMeters;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	int32 PlayerLodRequiredForFloorCheckWhenRendered;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	EFortAILODLevel AILodRequiredForFloorCheckWhenRendered;

	UPROPERTY(BlueprintReadOnly, Category="Character Movement")
	bool bIsRidden;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Character Movement")
	FOverrideMovementCurveData OverrideMovementCurveData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	TObjectPtr<UCurveFloat> VelocityBasedStrafeCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	TObjectPtr<UCurveFloat> VelocityBasedTurnCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Character Movement")
	TObjectPtr<UCurveFloat> VelocityBasedBackupCurve;

	UPROPERTY()
	bool bWasUsingVelocityBasedTurnCurve;

	UPROPERTY()
	float RotationYawRateToRestore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding", meta=(ClampMax="90", ClampMin="0", UIMax="90", UIMin="0"))
	FScalableFloat FallingSlopeSafeSlideAngleScalable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding", meta=(ClampMin="0", UIMin="0"))
	FScalableFloat FallingSlopeSafeSlideMaxSpeedScalable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding", meta=(ClampMax="1", ClampMin="0", UIMax="1", UIMin="0"))
	FScalableFloat FallingSlopeDamageScalarMinScalable;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Character Movement")
	bool bWantsToSlide;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Character Movement")
	bool bSlideInputJustTurnedOff;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Character Movement")
	bool bJumpSlideAvailable;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Character Movement")
	bool bSlideCommandBuffered;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SkydivingControlParamsPassive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SkydivingControlParamsActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams ParachuteControlParamsSkydive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams ParachuteControlParamsJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams ParachuteControlParamsGliderRedeploy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams GoopAirControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FGoopControlParams GoopControlParams;

	UPROPERTY(EditAnywhere, Category="Swinging")
	FSwingingControlParams SwingingControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams BalloonControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams FloatingControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams VortexSkydivingControlParamsPassive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams VortexSkydivingControlParamsActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams VortexSkydivingControlParamsActiveUpward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams VortexParachuteControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams VortexVolumeSkydivingControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SpinningVortexSkydivingControlParamsPassive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SpinningVortexSkydivingControlParamsActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SpinningVortexSkydivingControlParamsActiveUpward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SpinningVortexParachuteControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SkyTubeSkydivingControlParamsPassive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SkyTubeSkydivingControlParamsActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FAirControlParams SkyTubeSkydivingControlParamsActiveUpward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat SkyTubeUpwardAccelerationScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	FScalableFloat SkyTubeDownwardAccelerationScalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControl")
	FWaterControlParams SurfaceSwimmingWaterControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControl")
	FWaterJumpParams WaterJumpParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControl")
	FWaterJumpParams WaterJumpParamsSprint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterControl")
	bool bComputeWaterSplineDataOnSimulatedMovement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="WaterSprintBoost")
	FWaterSprintBoostParams WaterSprintBoostParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding")
	FQuat CachedInitialFacingRotationForSliding;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="AthenaSliding")
	bool bInFallingGracePeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaSliding")
	bool bSlideBoostPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaSliding")
	FSynchedActionInfo SynchedActionInfo;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	bool bWantsToSwing;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	bool bSwingAttached;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	bool bSwingAttachedVehicle;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	bool bSwingInstantVelocity;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	FVector_NetQuantize100 SwingAttachLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Swinging Movement")
	FVector_NetQuantize100 SwingLaunch;

	UPROPERTY(Transient)
	bool bInitialAttach;

	UPROPERTY(Transient)
	bool bSwingFromMovingBase;

	UPROPERTY(Transient)
	float SwingingDistanceToGround;

	UPROPERTY(Transient)
	float FallingSlopeSafeSlideAngleCached;

	UPROPERTY(Transient)
	float FallingSlopeSafeSlideNormalZ;

	UPROPERTY(Transient)
	FRidableControlParams RidableControlParams;

	UPROPERTY(Transient)
	FRidableControlRuntimeData RidableRuntimeData;

	UPROPERTY(Transient)
	FFlyingRidableControlParams FlyingRidableControlParams;

	UPROPERTY(Transient)
	float MaxHalfAimingAngle;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetSlidingControlParams, BlueprintSetter=SetSlidingControlParams, Category="AthenaSliding")
	FSlidingControlParams SlidingControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaAirControl")
	float SkydivingMaxSmoothUpdateDistanceScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding", meta=(ClampMax="2", ClampMin="0", UIMax="2", UIMin="0"))
	float SlideTimeUntilReset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSliding", meta=(ClampMax="1000", ClampMin="-10000", UIMax="1000", UIMin="-10000"))
	float SlideIfVelocityLessThanZ;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Ballooning")
	int32 GravityCeilingRelation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortMovementComp_Character")
	FScalableFloat TacticalSprintBreakingSpeed;

	UPROPERTY(Transient)
	float CurrentZiplineVelocityDirection;

	UPROPERTY(Transient)
	float GracePeriodToConnectToZipline;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	TWeakObjectPtr<AActor> GrindBaseActor;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	FVector_NetQuantize100 GrindInputParams;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	float GrindDistanceOnSpline;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	bool bGrindFromInteraction;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	bool bWantsToGrind;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	bool bWantsToGrindSprint;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	bool bGrindRequestJump;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Grinding Movement")
	bool bGrindJustCorrected;

	UPROPERTY(Transient)
	float FallingStartedZ;

	UPROPERTY(Transient)
	FVector CustomFallingAcceleration;

	UPROPERTY(Transient)
	FVector ReplicatedAcceleration;

	UPROPERTY(Transient)
	uint8 bTriggeredFallingFeedbackSinceLanded : 1;

	UPROPERTY(Transient)
	TArray<FName> UseHighToleranceIds;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	uint8 bUpdatesFloorWhenNotInFullSimulation : 1;

	UPROPERTY(EditAnywhere, Category="Character Movement (Networking)")
	uint8 bUpdatesFloorWhenNotInFullSimulationOnlyOnNetUpdate : 1;

	UPROPERTY(EditAnywhere, Category="AI")
	uint8 bAvoidOvershootingDuringPathfollowing : 1;

	UPROPERTY(EditAnywhere, Category="AI", meta=(EditCondition="bAvoidOvershootingDuringPathfollowing == true", EditConditionHides))
	uint8 bIgnoreAccelerationWhenAvoidingOvershoot : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Character Movement: NavMesh Movement")
	uint8 bProjectNavMeshOnDestructibleChannel : 1;

	UPROPERTY(Transient)
	bool bAllowVerticalPawnRotation;

	UPROPERTY(Transient)
	TScriptInterface<IFortAthenaAILODSettings> CachedLODSettingsManager;

	UPROPERTY(Transient)
	float CustomMeshHeightAdjust;

	UPROPERTY(Transient)
	float CustomMeshHeightAdjustLerpTarget;

	UPROPERTY(Transient)
	float CustomMeshHeightAdjustLerpSpeed;

	UPROPERTY(Transient)
	float CustomMeshHeightAdjustTotalApplied;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="Character Movement")
	bool bWantsToSkate;

	UPROPERTY(Transient)
	TObjectPtr<UFortMovementMode_BaseExtLogic> ActiveMovementModeExtension;

private:
	UPROPERTY(EditAnywhere, Category="Character Movement: Walking", meta=(ClampMin="0", UIMin="0"))
	float TacticalSprintBrakingTimeThreshold;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortSurfaceTrackingComponent> SurfaceTrackingComponent;

	UPROPERTY(Transient)
	float SwingDetachTime;

	UPROPERTY(Transient)
	float SwingingVerticalDistThreshold;

};

