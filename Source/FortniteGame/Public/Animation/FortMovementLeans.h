// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonAnimationTypes.h"
#include "FortMovementLeans.generated.h"

UENUM()
enum class EMovementLeanState : uint8
{
	None = 0,
	BlendingIn = 1,
	BlendingOut = 2,
	SettleDelay = 3,
	Settling = 4,
	Idle = 5,
};

USTRUCT()
struct FFortMovementLeans
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	EMovementLeanState LeanState;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float BlendInTime;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	EEasingFuncType BlendInType;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float BlendOutTime;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	EEasingFuncType BlendOutType;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float SettleBlendTime;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	EEasingFuncType SettleBlendType;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float SettleDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float SettlePercentage;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float MinVerticalFalloffAngle;

	UPROPERTY(EditDefaultsOnly, Category="FortMovementLeans")
	float MaxVerticalFalloffAngle;

	UPROPERTY(Transient)
	float LeanDirection;

	UPROPERTY(Transient)
	float BlendOutLeanDirection;

	UPROPERTY(Transient)
	float BlendedWeight;

	UPROPERTY(Transient)
	float ModulatedBlendedWeight;

	UPROPERTY(Transient)
	float SettleStartTime;

	UPROPERTY(Transient)
	float BlendOutVelocityYawAngle;

	UPROPERTY(Transient)
	float PreviousEffectiveYawAngle;

};

