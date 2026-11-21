// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "SupplyDropSpawner.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ASupplyDropSpawner : public ABuildingProp
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Param Overrides")
	float MinSpawnHeightOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Spawn Param Overrides")
	float MaxSpawnHeightOverride;

};

