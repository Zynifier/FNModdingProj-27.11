// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pawns/FortPawnStats.h"
#include "FortPlayerPawnStats.generated.h"

USTRUCT()
struct FFortPlayerPawnStats : public FFortPawnStats
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPawnStats")
	float MaxJumpTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPawnStats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPawnStats")
	float StaminaRegenRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPawnStats")
	float StaminaRegenDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PlayerPawnStats")
	float SprintingStaminaExpenditureRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BaseFortPawnStats")
	FName PersonalVehicleFallingDamageTableRow;

};

