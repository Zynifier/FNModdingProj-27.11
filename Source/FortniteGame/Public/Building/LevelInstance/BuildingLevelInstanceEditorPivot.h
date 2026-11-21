// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LevelInstance/LevelInstanceEditorPivotInterface.h"
#include "Building/BuildingActor.h"
#include "BuildingLevelInstanceEditorPivot.generated.h"

UCLASS(Transient, NotPlaceable, MinimalAPI, HideCategories=("Rendering", "Replication", "Collision", "Partition", "Input", "HLOD", "Actor", "Cooking", "Game|Damage"), SparseClassDataType=BuildingActorClassData)
class ABuildingLevelInstanceEditorPivot : public ABuildingActor, public ILevelInstanceEditorPivotInterface
{
	GENERATED_BODY()

};

