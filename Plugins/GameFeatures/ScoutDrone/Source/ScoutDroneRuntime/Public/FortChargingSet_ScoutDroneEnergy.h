// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Transient/FortChargingSet_Base.h"
#include "FortChargingSet_ScoutDroneEnergy.generated.h"

UCLASS(BlueprintType)
class SCOUTDRONERUNTIME_API UFortChargingSet_ScoutDroneEnergy : public UFortChargingSet_Base
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_Energy(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Energy, Category="Energy")
	FFortGameplayAttributeData Energy;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Energy")
	FFortGameplayAttributeData MaxEnergy;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Energy")
	FFortGameplayAttributeData EnergyChargeRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Energy", meta=(HideFromModifiers))
	FFortGameplayAttributeData ServerTimeEnergyIncrements;

};

