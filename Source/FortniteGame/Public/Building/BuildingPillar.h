// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingAutoNav.h"
#include "Building/BuildingSMActor.h"
#include "BuildingPillar.generated.h"

USTRUCT(BlueprintType)
struct FBuildingPillarActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPillarActorClassData)
class ABuildingPillar : public ABuildingAutoNav
{
	GENERATED_BODY()

};

