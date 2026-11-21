// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_BlackWidow_F.generated.h"

USTRUCT(BlueprintType)
struct FBlackWidowLegSinAnimationScalar
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation")
	bool bUseConstantValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation", meta=(EditCondition="bUseConstantValue"))
	float ConstantValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation", meta=(EditCondition="!bUseConstantValue"))
	float TimeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation", meta=(EditCondition="!bUseConstantValue"))
	float FrequencyOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation", meta=(EditCondition="!bUseConstantValue"))
	float SinOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation", meta=(EditCondition="!bUseConstantValue"))
	float ResultMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SinAnimation", meta=(EditCondition="!bUseConstantValue"))
	FVector2D MappedRangeOutput;

};

USTRUCT(BlueprintType)
struct FBlackWidowLegSinAnimationRotator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation")
	FBlackWidowLegSinAnimationScalar RollAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation")
	FBlackWidowLegSinAnimationScalar PitchAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SinAnimation")
	FBlackWidowLegSinAnimationScalar YawAnimation;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_BlackWidow_F : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="BackpackRotator")
	FRotator BackpackRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBoneName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FName BackpackRotatorBaseName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BackpackRotator")
	FVector2D BackpackRotatorMapOutputRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="SpeedRange")
	float PawnSpeedRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpeedRange")
	FVector2D PawnSpeedMapInputRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpeedRange")
	FVector2D PawnSpeedMapOutputRange;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="FallingAnimDynamics")
	FVector FallingAnimDynamicsUpForce;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingAnimDynamics")
	FVector2D FallingAnimDynamicsPerlinNoiseMapRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingAnimDynamics")
	float FallingAnimDynamicsForceGliderMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FallingAnimDynamics")
	float FallingAnimDynamicsForceGlobalMultiplier;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegTop01Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegTop02Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegTop03Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegTop04Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegMid01Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegMid03Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegMid04Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegBot01Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegBot02Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	FRotator LegBot03Rotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float LegRotationScaleDownRateADS;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	float Legs01PoseTargetAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	float Legs02PoseTargetAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	float Legs03PoseTargetAlpha;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="LegMovement")
	float Legs04PoseTargetAlpha;

	UPROPERTY(Transient)
	float CollapseLegsTimeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float CollapsingLegs01PoseFullAlphaDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float CollapsingLegs02PoseFullAlphaDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float CollapsingLegs03PoseFullAlphaDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float CollapsingLegs04PoseFullAlphaDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float TopLegsAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float MidLegsAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float BotLegsAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	float LegSinAnimationFrequency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegTop01SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegTop02SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegTop03SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegTop04SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegMid01SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegMid03SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegMid04SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegBot01SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegBot02SinAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="LegMovement")
	FBlackWidowLegSinAnimationRotator LegBot03SinAnimation;

};

