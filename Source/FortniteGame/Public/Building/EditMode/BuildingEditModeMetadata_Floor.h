// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/EditMode/BuildingEditModeMetadata_BinaryToggle.h"
#include "BuildingEditModeMetadata_Floor.generated.h"

UENUM(BlueprintType)
enum class EFloorPatternType : uint8
{
	None = 0 UMETA(Hidden),
	//4 tiles selected

	DefaultPiece = 1,
	//3 tiles selected

	LPiece = 2,
	//2 tiles selected

	HalfPiece = 3,
	//2 tiles selected

	DiagonalPiece = 4,
	//1 tile selected

	CornerPiece = 5,
};

UCLASS(MinimalAPI)
class UBuildingEditModeMetadata_Floor : public UBuildingEditModeMetadata_BinaryToggle
{
	GENERATED_BODY()

};

