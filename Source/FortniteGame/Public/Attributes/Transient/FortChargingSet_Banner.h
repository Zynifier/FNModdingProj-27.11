// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Transient/FortChargingSet_Base.h"
#include "FortChargingSet_Banner.generated.h"

UCLASS(BlueprintType)
class UFortChargingSet_Banner : public UFortChargingSet_Base
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_Charge(const FFortGameplayAttributeData& OldValue);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_Charge, Category="Charge")
	FFortGameplayAttributeData Charge;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Charge")
	FFortGameplayAttributeData MaxCharge;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Charge")
	FFortGameplayAttributeData ChargeRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="Charge", meta=(HideFromModifiers))
	FFortGameplayAttributeData ServerTimeChargeIncrements;

};

