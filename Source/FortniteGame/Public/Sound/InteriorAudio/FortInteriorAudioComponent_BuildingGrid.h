// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Sound/InteriorAudio/FortInteriorAudioComponent.h"
#include "Sound/InteriorAudio/FortInteriorAudioTypes.h"
#include "FortInteriorAudioComponent_BuildingGrid.generated.h"

class UBuildingStructuralSupportSystem;

UCLASS(BlueprintType, Blueprintable)
class UFortInteriorAudioComponent_BuildingGrid : public UFortInteriorAudioComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Building Dictionaries")
	TMap<EInteriorAudioBuildingType, FInteriorAudioDictionary> Dictionaries;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Building Grid Scan")
	int32 HorizontalScanDistance;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Building Grid Scan")
	int32 VerticalScanDistance;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Building Counts")
	int32 TotalCeilingCountRequiredAlongHorizontalScan;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Line Trace")
	int32 HorizontalLineTraceDistance;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Line Trace")
	int32 VerticalLineTraceDistance;

	UPROPERTY(EditDefaultsOnly, Category="Detection Properties | Line Trace")
	TEnumAsByte<ECollisionChannel> TraceCollisionChannel;

private:
	UPROPERTY(Transient)
	FInteriorAudioPlayerInfo Player;

	UPROPERTY(Transient)
	TObjectPtr<UBuildingStructuralSupportSystem> BuildingGrid;

};

