// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortPlayerAnimInstance_MotorcycleDriver.h"
#include "FortSportbikeDriverAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortSportbikeDriverAnimInstance : public UFortPlayerAnimInstance_MotorcycleDriver
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool SportbikeWheelieEarlyOut;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool StateRuleFromWheelieToGroundTrickOutro;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool EarlyExitFromGroundTrick;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool IsBoostingWithNoPassenger;

	UPROPERTY(BlueprintReadWrite, Transient, Category="SportbikeDriver|Nativized")
	int32 MotorcycleGear;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	int32 CurrentGear;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	int32 PreviousGear;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool IsChangingGear;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	float SuperSlideBlendAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	float SuperSlideBlendStart;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	float SuperSlideBlendEnd;

	UPROPERTY(BlueprintReadOnly, Transient, Category="SportbikeDriver|Nativized")
	bool IsSuperSliding;

};

