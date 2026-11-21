// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingWall.h"
#include "InteractableBuildingWall.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingWallActorClassData)
class AInteractableBuildingWall : public ABuildingWall
{
	GENERATED_BODY()

};

