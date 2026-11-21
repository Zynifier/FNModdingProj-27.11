// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "BuildingRoof.generated.h"

USTRUCT(BlueprintType)
struct FBuildingRoofActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingRoofActorClassData)
class ABuildingRoof : public ABuildingSMActor
{
	GENERATED_BODY()

};

