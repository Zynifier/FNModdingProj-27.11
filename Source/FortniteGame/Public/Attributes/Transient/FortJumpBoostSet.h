// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortJumpBoostSet.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortJumpBoostSet : public UFortAttributeSet, public IFortAttributeFuelInterface
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_Fuel(const FFortGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ReserveFuel(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData BoostActive;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData MaxFuel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Fuel, Category="Fuel")
	FFortGameplayAttributeData Fuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData ReserveMaxFuel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ReserveFuel, Category="Fuel")
	FFortGameplayAttributeData ReserveFuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelBurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelRegenRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData FuelRegenDelay;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData BoostFuelCost;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData UpwardThrust;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData LateralThrust;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData UpwardAcceleration;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData LateralAcceleration;

};

