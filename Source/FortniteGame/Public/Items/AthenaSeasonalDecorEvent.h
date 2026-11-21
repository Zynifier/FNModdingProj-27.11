// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortGameModeAthena.h"
#include "Items/FortEventItemDefinitionBase.h"
#include "AthenaSeasonalDecorEvent.generated.h"

class AFortAthenaSupplyDrop;
class UAthenaBattleBusItemDefinition;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level"))
class UAthenaSeasonalDecorEvent : public UFortEventItemDefinitionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Event")
	TSoftClassPtr<AFortAthenaSupplyDrop> SupplyDropOverride;

	UPROPERTY(EditAnywhere, Category="Event")
	TArray<FAthenaVehicleOverride> VehicleOverrides;

	UPROPERTY(EditAnywhere, Category="Event")
	bool bForceBattleBusOverrideEvenIfCosmeticSlotted;

	UPROPERTY(EditAnywhere, Category="Event")
	TObjectPtr<UAthenaBattleBusItemDefinition> BattleBusOverride;

};

