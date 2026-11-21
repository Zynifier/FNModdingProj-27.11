// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortRechargingActionTimer.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortRechargingActionTimer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ChargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ActiveExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float PassiveExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float MinActiveDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float MinActivationCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ActiveCooldownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ChargeThreshold;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RechargingActionTimer")
	float Charge;

	UPROPERTY(BlueprintReadWrite, Category="RechargingActionTimer")
	bool bIsActive;

	UPROPERTY(BlueprintReadWrite, Category="RechargingActionTimer")
	bool bIsCharging;

	UPROPERTY(BlueprintReadWrite, Category="RechargingActionTimer")
	bool bIsPassive;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortRechargingActionTimerConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ChargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ActiveExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float PassiveExpenseRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float MinActiveDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float MinActivationCharge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ActiveCooldownTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RechargingActionTimer")
	float ChargeThreshold;

};

