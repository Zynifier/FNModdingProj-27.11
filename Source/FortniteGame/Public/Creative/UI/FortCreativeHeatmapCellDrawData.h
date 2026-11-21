// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeHeatmapCellDrawData.generated.h"

class AFortInGameMapManagerCreative;
class UFortVolumeObjectTrackingComponent;
class UObject;

USTRUCT()
struct FFortCalculateHeatmapCellDrawData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<AFortInGameMapManagerCreative> MapManager;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortVolumeObjectTrackingComponent> ObjectTrackingComponent;

};

USTRUCT()
struct FFortCreativeHeatmapCellDrawData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> Icon;

};

