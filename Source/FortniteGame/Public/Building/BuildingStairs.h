// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/FortAITypes.h"
#include "Building/BuildingFloor.h"
#include "BuildingStairs.generated.h"

USTRUCT(BlueprintType)
struct FBuildingStairsActorClassData : public FBuildingFloorActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingStairsActorClassData)
class ABuildingStairs : public ABuildingFloor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Navigation")
	TEnumAsByte<EBuildingStairsRailing::Type> RailingType;

};

