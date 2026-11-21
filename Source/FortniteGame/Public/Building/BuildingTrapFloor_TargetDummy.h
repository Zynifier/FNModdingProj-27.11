// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapFloor_TargetDummy.generated.h"

USTRUCT(BlueprintType)
struct FPointConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category="PointConfiguration")
	TArray<FVector> PointLocations;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapFloor_TargetDummy : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, SaveGame, Replicated, Category="Pathing")
	TArray<FVector> PathPointLocations;

};

