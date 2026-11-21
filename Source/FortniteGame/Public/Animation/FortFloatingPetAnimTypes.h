// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortFloatingPetAnimTypes.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetAnimInstanceControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Backpack Target Vector")
	FVector BackpackTargetVectorTransformDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Backpack Target Vector")
	FName BackpackTargetVectorLocationSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Backpack Target Vector")
	FName BackpackTargetVectorTransformSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Skydiving")
	float SkydivingYawDefinedHoverOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Skydiving")
	float SkydivingSpringStiffnessInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Skydiving")
	float SkydivingBaseAimPitchSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Skydiving")
	float SkydivingBaseAimPitchSmoothWhileDiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Regular Gameplay")
	float BaseAimPitchSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Regular Gameplay")
	float SpringStiffnessInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Regular Gameplay")
	float YawDefinedHoverOffsetWhileEmoting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Spring Inputs | Regular Gameplay")
	FName YawDefinedHoverOffsetTransformSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Spring Stiffness Interp Speed")
	float SpringStiffnessInterpSpeedSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaSmoothTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaSmoothTargetWhilePlayingEmote;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaSmoothTargetWhileSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Backpack Target Vector Alpha")
	FRotator RotationYawDefinedHoverOffsetSmoothTargetWhileEmoting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Backpack Target Vector Alpha")
	float RotationYawDefinedHoverOffsetSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Carrier Offset Total")
	FVector CarrierOffsetTotalTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Carrier Offset Total")
	FVector CarrierOffsetTotalTargetWhileEmoting;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Carrier Offset Total")
	FVector CarrierOffsetTotalTargetWhileSkydiving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Frontend | Smoothing Spring Values | Carrier Offset Total")
	float CarrierOffsetTotalInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Gameplay| Root Yaw Offset")
	float RootYawOffsetMultiplier;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetBackpackTargetCalculationControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector")
	FVector BackpackTargetVectorTransformDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector")
	FName BackpackTargetVectorLocationSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector")
	FName BackpackTargetVectorTransformSocket;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaRecentlyFired;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaWhilePlayingMeleeAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Backpack Target Vector Alpha")
	float BackpackTargetVectorAlphaWhileMoving;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetOffsetCalculationControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Root Yaw Offset")
	float RootYawOffsetTurnInPlaceSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Parachute Just Opened Offset")
	FVector ParachuteJustOpenedOffsetTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Parachute Just Opened Offset")
	FVector ParachuteJustOpenedOffsetTargetWhenParachuteJustOpened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Parachute Just Opened Offset")
	float ParachuteJustOpenedOffsetInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Parachute Just Opened Offset")
	float ParachuteJustOpenedOffsetInterpSpeedWhenParachuteJustOpened;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump Up Offset")
	FVector JumpUpOffsetSmoothTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump Up Offset")
	FVector JumpUpOffsetSmoothTargetWhenJumping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Jump Up Offset")
	float JumpUpOffsetSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Skydiving Rotation Offset")
	float SkydivingRotationOffsetBaseAimPitchSmoothMultiplier;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetSpringCalculationControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Smooth Stiffness Values")
	float SpringStiffnessInterpSpeedSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityX_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityX_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityX_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityY_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityY_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityY_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityZ_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityZ_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetLocalVelocityZ_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalTargetMeleeTwistCurveMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Total Spring")
	float CarrierOffsetTotalSpringMass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Root Rotation Melee Twist Spring")
	float RootRotationMeleeTwistSpringTargetMeleeTwistCurveMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Root Rotation Melee Twist Spring")
	float RootRotationMeleeTwistSpringMass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Yaw Defined Hover Offset Spring")
	float YawDefinedHoverOffsetSpringMass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRateSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionX_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionX_MultiplierWhenPlayingMeleeAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionY_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionYZ_MultiplierWhenPlayingMeleeAnim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionZ_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionX_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionX_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionYZ_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionYZ_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Reaction")
	float CarrierOffsetRotationReactionSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float PlayerYawDeltaInterpInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float LocalVelocityInterpInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityX_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityX_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityX_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityY_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityY_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityY_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityZ_ClampMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity")
	float CarrierOffsetRotationVelocityZ_ClampMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Carrier Offset Rotation Velocity Alpha")
	FName CancelVelocityRotationCurve;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetAdvancedControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Advanced Controls")
	float PawnBaseAimPitchSmoothInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Advanced Control Structs")
	FFortFloatingPetAnimInstanceControls AnimInstanceControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Advanced Control Structs")
	FFortFloatingPetOffsetCalculationControls OffsetCalculationControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Advanced Control Structs")
	FFortFloatingPetSpringCalculationControls SpringCalculationControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Advanced Control Structs")
	FFortFloatingPetBackpackTargetCalculationControls BackpackTargetCalculationControls;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetRotationStateOffsets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Rotation States")
	float YawDefaultIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Rotation States")
	float YawDefaultSkydive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Rotation States")
	float YawEmotePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Rotation States")
	float YawDBNO;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetSimpleControls
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringStiffness;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringStiffnessSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringStiffnessInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringStiffnessInterpSpeedSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringCriticalDampingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float SpringCriticalDampingFactorSmooth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float YawDefinedHoverOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Spring Simple Controls")
	float BaseAimPitchSmooth;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortFloatingPetTranslationStateOffsets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Default")
	FVector DefaultIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Default")
	FVector DefaultDownsights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Default")
	FVector DBNOIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Default")
	FVector MeleePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Default")
	FVector EmotePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation State | Default")
	FVector IsOperatingTurret;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Crouching")
	FVector CrouchTurning;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Crouching")
	FVector CrouchIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Crouching")
	FVector CrouchDownsights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Crouching")
	FVector CrouchMeleePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Skydiving")
	FVector DefaultSkydive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Skydiving")
	FVector ParachuteOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Skydiving")
	FVector DivingSkydive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Swimming")
	FVector SurfaceSwimmingIdle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Swimming")
	FVector SurfaceSwimmingDownsights;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Swimming")
	FVector SurfaceSwimmingMeleePlaying;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Swimming")
	FVector SurfaceSwimmingSprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Translation States | Swimming")
	FVector DiveJumping;

};

