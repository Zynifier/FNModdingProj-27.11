// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionConstantForce.h"
#include "GameFramework/RootMotionSource.h"
#include "Math/MathFwd.h"
#include "AbilityTask_ApplyRootMotion_RocketRam.generated.h"

class UAbilityTask_ApplyRootMotion_RocketRam;
class UCurveFloat;
class UCurveVector;
class UGameplayAbility;

USTRUCT()
struct FRootMotionSource_RocketRam : public FRootMotionSource
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector InitialDirection;

	UPROPERTY(NotReplicated)
	FVector EndingDirection;

	UPROPERTY()
	float MinSpeed;

	UPROPERTY()
	float MaxSpeed;

	UPROPERTY()
	TObjectPtr<UCurveFloat> SpeedCurve;

	UPROPERTY()
	float FloorTraceHeight;

	UPROPERTY()
	TObjectPtr<UCurveVector> PathOffsetCurve;

private:
	UPROPERTY()
	FVector PreviousEndLocationWithoutOffset;

};

UCLASS(MinimalAPI)
class UAbilityTask_ApplyRootMotion_RocketRam : public UAbilityTask_ApplyRootMotionConstantForce
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Ability|Tasks", meta=(BlueprintInternalUseOnly="true", DefaultToSelf="InOwningAbility", HidePin="InOwningAbility"))
	static UAbilityTask_ApplyRootMotion_RocketRam* ApplyRootMotion_RocketRam(UGameplayAbility* InOwningAbility, FName InTaskInstanceName, float InDuration, FVector InInitialDirection, FVector InEndingDirection, float InMinSpeed, float InMaxSpeed, UCurveFloat* InSpeedCurve, float InFloorTraceHeight, UCurveVector* InPathOffsetCurve, ERootMotionFinishVelocityMode InVelocityOnFinishMode, FVector InSetVelocityOnFinish, float InClampVelocityOnFinish);

private:
	UPROPERTY()
	FVector InitialDirection;

	UPROPERTY()
	FVector EndingDirection;

	UPROPERTY()
	float MinSpeed;

	UPROPERTY()
	float MaxSpeed;

	UPROPERTY()
	TObjectPtr<UCurveFloat> SpeedCurve;

	UPROPERTY()
	float FloorTraceHeight;

	UPROPERTY()
	TObjectPtr<UCurveVector> PathOffsetCurve;

};

