// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/EditMode/BuildingEditModeSupport_BinaryToggle.h"
#include "BuildingEditModeSupport_Roof.generated.h"

USTRUCT()
struct FTileCompInterpData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector InitialTranslation;

	UPROPERTY(Transient)
	FVector DesiredTranslation;

};

UCLASS()
class UBuildingEditModeSupport_Roof : public UBuildingEditModeSupport_BinaryToggle
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FTileCompInterpData> TileInterpData;

};

