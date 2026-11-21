// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingSMActor.h"
#include "BuildingFloor.generated.h"

USTRUCT(BlueprintType)
struct FBuildingFloorActorClassData : public FBuildingSMActorClassData
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingFloorActorClassData)
class ABuildingFloor : public ABuildingSMActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Building")
	bool IsBalcony() const;

protected:
	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="Navigation")
	uint8 bShouldIgnoreForHorizontalHotspotSearch : 1;

};

