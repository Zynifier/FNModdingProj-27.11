// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "FortAttributeSet_VehicleFuel.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortAttributeSet_VehicleFuel : public UFortAttributeSet
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_Fuel(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Fuel, Category="Fuel")
	FFortGameplayAttributeData Fuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelTankCapacity;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelPerSecondIdle;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelPerSecondDriving;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelPerSecondBoosting;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData MinFuelAtSpawn;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData MaxFuelAtSpawn;

};

