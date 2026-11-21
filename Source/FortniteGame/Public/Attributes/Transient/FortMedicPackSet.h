// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Attributes/FortAttributeSet.h"
#include "Attributes/Interface/FortAttributeFuelInterface.h"
#include "FortMedicPackSet.generated.h"

UCLASS(BlueprintType)
class UFortMedicPackSet : public UFortAttributeSet, public IFortAttributeFuelInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData MaxFuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData Fuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData ReserveMaxFuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData ReserveFuel;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData FuelBurnRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData FuelRegenRate;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData FuelRegenDelay;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData SelfReviveActive;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData SelfReviveTime;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData SelfReviveCost;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData DamageBreaksSelfRevive;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData Heal;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData HealRadius;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="MedicPack")
	FFortGameplayAttributeData HealPeriod;

};

