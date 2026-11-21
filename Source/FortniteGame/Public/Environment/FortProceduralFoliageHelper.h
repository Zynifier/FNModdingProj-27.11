// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LandscapeGrassType.h"
#include "FortProceduralFoliageHelper.generated.h"

UCLASS(MinimalAPI)
class UFortProceduralFoliageBlueprintHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintPure, Category="Grass")
	static void GetInstanceWorldPositionOffsetDisableDistance(const FGrassVariety& InGrassVariety, int32& InstanceWorldPositionOffsetDisableDistance, bool& bFailed);

};

