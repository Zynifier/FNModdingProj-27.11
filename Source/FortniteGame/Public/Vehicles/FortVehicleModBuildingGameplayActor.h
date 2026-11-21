// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingGameplayActor.h"
#include "Vehicles/FortVehicleModInterface.h"
#include "FortVehicleModBuildingGameplayActor.generated.h"

class UFortVehicleModConfig;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortVehicleModBuildingGameplayActor : public ABuildingGameplayActor, public IFortVehicleModInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	virtual const UFortVehicleModConfig* GetModConfig();

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortVehicleModConfig> ModConfig;

};

