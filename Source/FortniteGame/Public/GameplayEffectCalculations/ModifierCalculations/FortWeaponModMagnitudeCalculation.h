// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayEffectCalculations/ModifierCalculations/FortGameplayModMagnitudeCalculation.h"
#include "FortWeaponModMagnitudeCalculation.generated.h"

class UDataTable;

USTRUCT()
struct FWeaponModMagnitudeCalculationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeaponModMagnitudeCalculationData")
	TObjectPtr<UDataTable> WeaponModDataTable;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModMagnitudeCalculationData")
	FGameplayTag RowLookupTag;

	UPROPERTY(EditDefaultsOnly, Category="WeaponModMagnitudeCalculationData")
	FGameplayAttribute Attribute;

};

UCLASS(HideCategories=("Attributes", "ExternalDependencies"))
class UFortWeaponModMagnitudeCalculation : public UFortGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Mod Data")
	FWeaponModMagnitudeCalculationData ModMagnitudeCalculationData;

};

UCLASS()
class UFortWeaponModMagnitudeSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

};

