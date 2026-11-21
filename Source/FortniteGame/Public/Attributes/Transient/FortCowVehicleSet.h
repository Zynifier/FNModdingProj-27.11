// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortCowVehicleSet.generated.h"

UCLASS(BlueprintType)
class UFortCowVehicleSet : public UFortAttributeSet, public IFortAttributeFuelInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_Fuel(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Fuel")
	FFortGameplayAttributeData MaxFuel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Fuel, Category="Fuel")
	FFortGameplayAttributeData Fuel;

};

