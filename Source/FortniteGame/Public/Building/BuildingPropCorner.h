// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingCorner.h"
#include "Building/BuildingSMActor.h"
#include "BuildingPropCorner.generated.h"

USTRUCT(BlueprintType)
struct FBuildingPropCornerActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropCornerActorClassData)
class ABuildingPropCorner : public ABuildingCorner
{
	GENERATED_BODY()

};

