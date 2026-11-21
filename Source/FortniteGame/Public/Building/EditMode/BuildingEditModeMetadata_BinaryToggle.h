// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/EditMode/BuildingEditModeMetadata.h"
#include "BuildingEditModeMetadata_BinaryToggle.generated.h"

UENUM()
enum EBinaryToggleValues
{
	BTV_Active = 0,
	BTV_Inactive = 1,
	// Special case that matches against either active or inactive

	BTV_Either = 2,
};

UCLASS(Abstract)
class UBuildingEditModeMetadata_BinaryToggle : public UBuildingEditModeMetadata
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="Pattern")
	TArray<TEnumAsByte<EBinaryToggleValues>> TileData;

};

