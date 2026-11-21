// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Animation/InputScaleBias.h"
#include "Engine/SpringInterpolator.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimTypes.h"
#include "Athena/FortAthenaSKPushVehicleCoastState.h"
#include "FortAnimInputs.generated.h"

class UAnimSequence;
class UCurveFloat;
class USkeletalMeshComponent;

UENUM(BlueprintType)
namespace ESkydivingDirection
{
	enum Type
	{
		Center = 0,
		Right = 1,
		Left = 2,
		Forward = 3,
		Back = 4,
	};
}

USTRUCT(BlueprintType)
struct FFortAnimInput_BowWeapon
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	TObjectPtr<UCurveFloat> BowChargeSpeedModifierCurve;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	FTransform RightHandIKExtraOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	FVector RightHandIKOffsetLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	FRotator RightHandIKOffsetRotation;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	FName WeaponAttachmentSocketName;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	FName ArrowNockSocketName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	float BowAimYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	float BowAimPitch;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	float ChargeBlendSpaceCrouchSpeed;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	float ChargeBlendSpaceCrouchSpeedInterpRate;

	UPROPERTY(Transient)
	float ChargeBlendSpaceCrouchSpeedTarget;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	float ChargePlayRate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	float ChargeBlendInTime;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	float FastChargeThreshold;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	float ChargeBlendInTimeDefault;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	float ChargeBlendInTimeFastCharge;

	UPROPERTY(EditDefaultsOnly, Category="BowWeaponSettings")
	float WeaponRaisedAdditiveLeanMultiplier;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsBowEquipped : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsBowCharging : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bIsBowAtMaxCharge : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BowWeapon")
	uint8 bEnableRightHandIK : 1;

	UPROPERTY(Transient)
	int32 DisableIkFrameCounter;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_CommonVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bIsUsingVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bIsJumpingVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bCanChargeJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bIsChargingJump : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bIsJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bIsOnGround : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CommonVehicle")
	uint8 bCanDriverAimWeapon : 1;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_FerretVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsUsingFerretVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBackLeftPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBackRightPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsFrontPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBackPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsDrifting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsLeaningOrBouncing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBounceCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBounceCrouched : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBounceJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsBounceRecoiling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsSteeringRight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsSteeringLeft;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsShooting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bIsFerretPassengerRotating;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float BounceCompression;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	FVector LeanPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float LeanPositionX;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float LeanPositionY;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float LeanPositionZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bAimFWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bAimBWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bAimLFT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bAimRGT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Biplane")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	float SlopeRollDegreeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Biplane")
	float SteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Biplane")
	FVector SeatSwitchDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	uint8 bWasUp : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	FVector PrevPlayerYAxis;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Biplane")
	FVector PrevPlayerZAxis;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_GolfCart
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsUsingGolfCart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBackLeftPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBackRightPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsFrontPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBackPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsDrifting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsEBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsPowerSliding : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsLeaningOrBouncing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBounceCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBounceCrouched : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBounceJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsBounceRecoiling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsSteeringRight : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bIsSteeringLeft : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float BounceCompression;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	FVector LeanPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float LeanPositionX;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float LeanPositionY;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float LeanPositionZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bAimFWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bAimBWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bAimLFT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	uint8 bAimRGT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="GolfCart")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="GolfCart")
	float SlopeRollDegreeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="GolfCart")
	float SteerAngle;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_HandIK
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAnimInput_HandIK")
	float IKAlphaOverrideInterpSpeed;

	UPROPERTY(EditDefaultsOnly, Category="FortAnimInput_HandIK")
	float IKSpaceSwitchOverrideInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_HandIK")
	float HandIKRetargetingWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_HandIK")
	float HandsInRootSpaceAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_HandIK")
	float LeftHandIKAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_HandIK")
	float RightHandIKAlpha;

	UPROPERTY(Transient)
	EFortHandIKOverrideType LeftHandIKOverrideType;

	UPROPERTY(Transient)
	EFortHandIKOverrideType RightHandIKOverrideType;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_VelocityImpact
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector LastVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FVector DeltaVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FVector ImpactScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FInputRange ImpactLimitX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FInputRange ImpactLimitY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FInputRange ImpactLimitZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FFloatRK4SpringInterpolator SpringInterpolatorX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FFloatRK4SpringInterpolator SpringInterpolatorY;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FFloatRK4SpringInterpolator SpringInterpolatorZ;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="VelocityImpact", meta=(ScriptName="TestVelocityValue"))
	uint8 bTestVelocity : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	FVector TestVelocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsForwardImpact : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsBackwardImpact : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsLeftImpact : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsRightImpact : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsUpImpact : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VelocityImpact")
	uint8 bIsDownImpact : 1;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_JackalVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsUsingJackalVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsSteeringLeft : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsSteeringRight : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float SteerAngleDeadZoneDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	float SteerAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float LeanYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	float QuantizedSteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	float SteerAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float SlopeRollDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float DistanceFromGround;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float PivotPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsBraking : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsMoving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsMovingForward : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsFalling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsRelaxed : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bHasReachedJumpChargeStartThreshold : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bHasReachedJumpChargeMidThreshold : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bHasReachedJumpChargeFullThreshold : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bAdjustRootForFemaleRider : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsPlayingEmoteOnHoverboard : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bShouldApplyAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayPivotOnGroundAndNotBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIsOnLowerHill : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bLowerBodyIdleToLoopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bInterruptHoverboardFullybody : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bEnterFullBodyHoverboardState : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bDefaultToJumpStartTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bLocomotionPoseToJumpTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bBoostingToBoostingJumpTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bJumpToLocomotionPoseTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bJumpApexToJumpFallTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIdleToMovementStartTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIdleToMovementLoopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bMovementLoopToMovementStopTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bMovementLoopToPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bMovementLoopToIdleTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIdleAdditiveToCollisionNTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bSplitBodyToHoverboardBRTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bHoverboardBRToSplitBodyTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bHoverboardBRMovementToJumpChargeTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bIdlesToJackalVehicleTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayAdditiveLeans : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayBalloonLeans : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayJumpTrickVertical : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayJumpTrick : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayMovingFast : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayHipAdjustmentAdditive : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayDriveSouth : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlayHeadAimOffset : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bPlaySlopeAimOffset : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float JumpCombatAdditiveWeight;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float MeleeTwistIdle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float MeleeTwistLocomotionLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="JackalVehicle")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FVector ImpactDisplacement;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	float SteerYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FVector EmoteHoverboardPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FRotator EmoteHoverboardRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	uint8 bShouldAttachFeetToHoverboard : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FVector FootLeftLocationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FRotator FootLeftRotationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FVector FootRightLocationOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="JackalVehicle")
	FRotator FootRightRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float StoppedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float MovingForwardThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float MovingFowardFastThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float DefaultToJumpStartTransitionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float JumpTrickAngularVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicle")
	float JumpDistanceFromGroundThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float VelocityStartThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float MovingFastThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float RelaxedSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float JumpChargeStartThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float JumpChargeMidThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float JumpChargeFullThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float RotatingAngularVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float IdleToLoopTransitionSpeedThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float IdleToMovementLoopTransitionThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float MeleeTwistIdleMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float MeleeTwistLocomotionLoopMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float LeanYawForMaxPivotPlayRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="JackalVehicleTunables")
	float SteerAlphaForMaxPivotPlayRate;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_Motorcycle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsUsingMotorcycle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsBackPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bHasPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsBackPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsDrifting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsSteeringRight : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bIsSteeringLeft : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float VerticalVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float VerticalAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bAimFWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bAimBWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bAimLFT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	uint8 bAimRGT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle")
	float SlopeRollDegreeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float SteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float SteerAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Motorcycle")
	float SteerAngleDeadZoneDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float SteeringRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float VehiclePitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Motorcycle")
	float VehicleRoll;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_PelvisAdjustment
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAnimInput_PelvisAdjustment", meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> PawnMesh;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_PelvisAdjustment")
	float DistanceToFeet;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAnimInput_PelvisAdjustment")
	float LegLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PelvisTunable")
	float DesiredLegLengthTreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PelvisTunable")
	float DotProductBetweenUpVectorsTreshold;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="PelvisTunable")
	float PelvisInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	float EmotePelvisOffsetInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Emote")
	float EmotePelvisOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Category="Emote")
	FVector CurrentEmotePelvisOffset;

	UPROPERTY(Transient)
	int32 PelvisBoneIndex;

	UPROPERTY(Transient)
	int32 FootLeftBoneIndex;

	UPROPERTY(Transient)
	int32 FootRightBoneIndex;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_Quad
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsUsingQuad : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsDriver : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsFrontPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBackPassenger : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBackPassengerAndLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsDrifting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBoosting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsLeaning : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsLeaningOrBouncing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBounceCrouching : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBounceCrouched : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBounceJumping : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsBounceRecoiling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsSteeringRight : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bIsSteeringLeft : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float BounceCompression;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	FVector LeanPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float LeanPositionX;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float LeanPositionY;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float LeanPositionZ;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float VerticalVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float VerticalAcceleration;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bAimFWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bAimBWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bAimLFT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	uint8 bAimRGT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="QuadBike")
	float SlopeRollDegreeAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="QuadBike")
	float SteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="QuadBike")
	float SteerAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="QuadBike")
	float SteerAngleDeadZoneDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="QuadBike")
	float SteeringRotation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="QuadBike")
	float VehiclePitch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="QuadBike")
	float VehicleRoll;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_ShoppingCart
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsUsingShoppingCart : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsUsingVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	ECoastState CoastState;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastStatePedaling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastStateCoasting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastStateDismount : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastStateIdle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsInAir : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoasting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsPedaling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart", meta=(ScriptName="IsReadyToPedalValue"))
	uint8 bIsReadyToPedal : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float IsReadyToPedal;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bWantsToCoast : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastIdling : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsStartCoasting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsEndCoasting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsDismountingFromCoast : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsCoastingOrDismountingFromCoast : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsStandingInPlace : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsSprintingAndMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsMovingForwardNotSprinting : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsBraking : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsMoving : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsMovingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsMovingBackwards : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsMovingOrTurningInPlace : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsInAirSteady : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsOnSlope : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bAimFWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bAimBWD : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bAimLFT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bAimRGT : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float ForwardVelocity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float ForwardSpeedKmH;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float CurrentBrakeForce;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsAcceleratingForward : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	uint8 bIsAccelBreakingOrReversing : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float SteerAngle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float SteerAngleInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float CoastSteerAngleInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float IsReadyToPedalInterpSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float StandingInPlaceSteerAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float SlopePitchDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float SlopeRollDegreeAngle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCart")
	float PawnToVehicleDeltaYawAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimCardDirDeadZoneAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimCardDirAngleOffsetDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ShoppingCart")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(Transient)
	int32 LastCardDirIndex;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_Skydiving
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	FVector ParaGilderRootOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	FRotator ParaGliderRootRotationOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bUseParaGlideRootModifier : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsSkydivingFromLaunchPad : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsSkydivingFromBus : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsInVortex : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsUsingUmbrella : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsActivelyStrafingInAir : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsDiving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsDivingUpInVortex : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsParachuteOpen : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsSkydiving : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydiving")
	uint8 bIsParachuteLeaning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsSkydiveLeaning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsLeaning : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsSkydiveDiveMode : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bParachuteLeanTransition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bPlayedParachuteLeanTransition : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bPlaySkydiveDrift : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bSkydiveDriftDelayActive : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bSkydiveDriftAnimAllowed : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsGliderRight : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsGliderCenter : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsGliderLeft : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsGliderForward : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	uint8 bIsGliderBack : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float LocalAccelForward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float LocalAccelRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float LocalVelocityRight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveAimPitch;

	UPROPERTY(EditAnywhere, Category="Skydiving")
	float SkydiveAimPitchInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveAimYaw;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float DeployChuteAnimRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveDriftAnimRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveDriftAnimRateCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveFidgetAnimRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveFidgetAnimRateCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveAdditiveAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	float SkydiveDriftDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	int32 SkydiveDriftAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	int32 SkydiveDriftAnimMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	int32 LaunchpadAnim;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	TEnumAsByte<ESkydivingDirection::Type> LocalAccelDir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	TEnumAsByte<ESkydivingDirection::Type> DirectionLast;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Skydiving")
	UAnimSequence* PoseAdditive;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_SkydivingExternalForce
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ClothGravity")
	bool bUseSkydivingVectorForce;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ExternalForce")
	FVector SkydivingVectorForce;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ExternalForce")
	FVector HeadToPelvisDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector FloatingMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector FloatingAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector DivingMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector DivingAdditive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector ParachutingMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ExternalForce")
	FVector ParachutingAdditive;

	UPROPERTY()
	bool bUseNoisyClothGravity;

	UPROPERTY()
	bool bApplyNoiseInActorSpace;

	UPROPERTY()
	float PerlinRangedOutMinX;

	UPROPERTY()
	float PerlinRangedOutMaxX;

	UPROPERTY()
	float PerlinRangedOutMinY;

	UPROPERTY()
	float PerlinRangedOutMaxY;

	UPROPERTY()
	float PerlinRangedOutMinZ;

	UPROPERTY()
	float PerlinRangedOutMaxZ;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_SocketBasedIKTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="SocketBasedIKTarget")
	FName SocketName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="SocketBasedIKTarget")
	FName AlphaCurveName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SocketBasedIKTarget")
	FRotator TargetRotation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SocketBasedIKTarget")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SocketBasedIKTarget")
	float Alpha;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_SpaghettiVehicle
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Octopus")
	uint8 bIsUsingSpaghettiVehicle : 1;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_SpeedWarping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SpeedWarping")
	TObjectPtr<UCurveFloat> PlayRateAdjustmentCurve;

	UPROPERTY(EditAnywhere, Category="SpeedWarping")
	FVector2D SpeedWarpingLimits;

	UPROPERTY(EditAnywhere, Category="SpeedWarping")
	FVector2D SpeedWarpingLimitsAddlRateScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SpeedWarping")
	float SpeedWarpingAmount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="SpeedWarping")
	float PlayRate;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_TurnInPlace
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnInitiatingStates;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FCachedAnimStateArray TurnTransitionStates;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FName TurnRotationAmountCurveName;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FName AllowTurnInPlaceCurveName;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	float TurnThreshold90;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	float MaxAllowedRootYawOffset;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	float InitialTurnCurveValue;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FVector2D EmoteYawOffsetSofteningInputRange;

	UPROPERTY(EditDefaultsOnly, Category="TurnInPlace")
	FVector2D EmoteYawOffsetSofteningOutputRange;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	float RootYawOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	float RootYawOffsetAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	uint8 bWantsToTurn : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	uint8 bWantsToTurnInVehicle : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	uint8 bWantsToTurnAgain : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="TurnInPlace")
	uint8 bTurningLeft : 1;

	UPROPERTY(Transient)
	float LastTurnRotationAmount;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Loop")
	float LoopRotationSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Loop")
	uint8 bPlayOutro : 1;

	UPROPERTY(EditDefaultsOnly, Transient, Category="Loop")
	float OutroTurnAmount;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Loop")
	float TurnPlayRate;

	UPROPERTY(Transient)
	float PreviousSpeedAlpha;

	UPROPERTY(Transient)
	float MinRotationSpeedAlpha;

	UPROPERTY(Transient)
	float MaxRotationSpeedAlpha;

};

USTRUCT(BlueprintType)
struct FFortAnimInput_Zipline
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	uint8 bIsZiplining : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	uint8 bShouldPlayPivotTransition : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	float LeanYaw;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	float PivotBlendDelayRemaining;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="Zipline")
	float PivotBlendDelay;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	EFortCardinalDirection PivotCardinalDirection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Zipline")
	FVector WorldVelocityLastTick;

	UPROPERTY(EditAnywhere, Transient, Category="Zipline")
	float LeanYawSmoothingSpeed;

};

