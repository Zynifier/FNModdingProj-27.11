// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/CachedAnimData.h"
#include "Animation/FortPlayerAnimInstance_MotorcycleRider.h"
#include "FortPlayerAnimInstance_MotorcyclePassenger.generated.h"

class UFortPlayerAnimInstance_MotorcycleDriver;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_MotorcyclePassenger : public UFortPlayerAnimInstance_MotorcycleRider
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger")
	TObjectPtr<UFortPlayerAnimInstance_MotorcycleDriver> DriverAnimInstance;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bHasDriver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bIsDriverJumping;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bIsDriverInventoryMode;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bIsSeatedAction;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bIsThrowingConsumable;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bEarlyOutStoppieOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float RunForwardAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bAimFWD;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bAimBWD;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bAimLFT;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bAimRGT;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bShouldJump;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bShouldApplySlopeCorrection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	bool bShouldExitFromLocomotion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Motorcycle Passenger|Nativized")
	FCachedAnimRelevancyData JumpIntroCachedTime;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Motorcycle Passenger|Nativized")
	float CachedJumpIntroTime;

};

