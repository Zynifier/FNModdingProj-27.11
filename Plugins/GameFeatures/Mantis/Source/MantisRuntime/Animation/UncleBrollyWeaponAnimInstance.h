// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Math/MathFwd.h"
#include "UncleBrollyWeaponAnimInstance.generated.h"

class UAnimInstance;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UUncleBrollyWeaponAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="UncleBrollyWeaponAnimInstance")
	TSubclassOf<UAnimInstance> UncleBrollyItemLayer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	FRotator UmbrellaRotation;

	UPROPERTY(Transient)
	float UmbrellaSpinSpeed;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	float BlockDeployEndPlayrate;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	float BlockDeployEndStartPosition;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsDodging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsPlayingMeleeAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsUmbrellaFailing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsMeleeGuarding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsInAir;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsDashing;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsSprinting;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsPredictingEnd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsDashCharging;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bIsDashPredictingEnd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bInAirAndMeleeGuarding;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bTransition_Default_to_DeployStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bTransition_DeployStart_to_Default;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bTransition_Fail_to_FailToDeploy;

	UPROPERTY(BlueprintReadOnly, Transient, Category="UncleBrollyWeaponAnimInstance")
	bool bTransition_FailLoop_to_DeployEnd;

};

