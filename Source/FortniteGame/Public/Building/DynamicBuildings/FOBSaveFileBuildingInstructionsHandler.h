// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/DynamicBuildings/FortSaveFileBuildingInstructionsHandler.h"
#include "FOBSaveFileBuildingInstructionsHandler.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AFOBSaveFileBuildingInstructionsHandler : public AFortSaveFileBuildingInstructionsHandler
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FOB")
	float BuildingPieceConstructionTime;

};

