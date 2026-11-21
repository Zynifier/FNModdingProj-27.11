// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/LevelInstance/BuildingLevelInstance.h"
#include "FortLevelInstancePrefab.generated.h"

UCLASS(MinimalAPI, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AFortLevelInstancePrefab : public ABuildingLevelInstance
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEGAME_API virtual void OnLevelShown();

private:
	UPROPERTY(EditDefaultsOnly, Category="Initialization")
	FScalableFloat NumberOfRandReservedValuesForBuildingInit;

};

