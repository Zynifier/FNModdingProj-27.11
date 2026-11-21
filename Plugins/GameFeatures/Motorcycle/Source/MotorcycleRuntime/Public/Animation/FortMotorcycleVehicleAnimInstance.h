// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortMotorcycleVehicle.h"
#include "FortMotorcycleVehicleAnimInstance.generated.h"

class AFortMotorcycleVehicle;
class UFortPlayerAnimInstance_MotorcycleDriver;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortMotorcycleVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Motorcycle|Nativized")
	MOTORCYCLERUNTIME_API void CollectConditionsFromDriver();

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMotorcycleVehicleAnimInstance")
	bool bIsInInventoryMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	TObjectPtr<UFortPlayerAnimInstance_MotorcycleDriver> DriverAnimInstance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsBikeParked;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsBikeOn;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsBikeStopping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsReversing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	float TotalSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsSurfaceWater;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	float AdditiveAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsRevving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	float AccelAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsThrottling;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsHonking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsSoloJumpTrickOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bIsJumpTrickNone;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	float BrakeLeverAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldExitFromLocomotion;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bStateRuleFromRevvingToThrottle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldPlayThrottleAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bStateTransitionRuleToMovingLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bEarlyOutFromMovingStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldReverse;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldReverseStop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized")
	bool bShouldStopThrottling;

	UPROPERTY(BlueprintReadWrite, Transient, Category="Motorcycle|Nativized")
	bool bIsFromJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bIsSoloJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bShouldJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bIsMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	EFortMotorcycleAirTrickType AirTrickType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bIsLandingInPlace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bStateRuleFallingToMoving;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	float JumpChargeFactor;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	float ForwardSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bStoppie;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bIsBraking;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bShouldBrake;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bEarlyOutBrakingOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bShouldJumpTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bStateTransitionRuleToReverseLoop;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle|Nativized|Driver")
	bool bIsReverseNoFeet;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPlayerPawn")
	TObjectPtr<AFortMotorcycleVehicle> MotorcycleVehicle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortMotorcycleVehicleAnimInstance")
	FRotator SwingArmRotation;

};

