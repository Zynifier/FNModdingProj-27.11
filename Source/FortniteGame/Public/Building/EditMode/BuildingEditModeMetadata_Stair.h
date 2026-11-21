// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/EditMode/BuildingEditModeMetadata.h"
#include "BuildingEditModeMetadata_Stair.generated.h"

UCLASS(MinimalAPI)
class UBuildingEditModeMetadata_Stair : public UBuildingEditModeMetadata
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="Pattern")
	TArray<int32> TileData;

};

