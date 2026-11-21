// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingTrapFloor.h"
#include "BuildingTrapLauncher.generated.h"

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingTrapActorClassData)
class ABuildingTrapLauncher : public ABuildingTrapFloor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Launch Pad")
	FScalableFloat LaunchStrength;

};

