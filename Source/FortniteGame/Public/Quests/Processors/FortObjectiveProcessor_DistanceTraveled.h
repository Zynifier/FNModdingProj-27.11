// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "FortObjectiveProcessor_DistanceTraveled.generated.h"

USTRUCT(meta=(DisplayName="Distance Traveled"))
struct FFortObjectiveFilter_DistanceTraveled : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DistanceTraveled")
	EDistanceTravelDirection TravelDirection;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DistanceTraveled", meta=(DisplayAfter="Vehicle"))
	uint8 bRequireVehicleInAir : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DistanceTraveled", meta=(Required))
	TArray<EDistanceTravelMode> AllowedTravelModes;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DistanceTraveled", meta=(DisplayAfter="Author"))
	FObjectiveSubjectTags Vehicle;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_DistanceTraveled", meta=(DisplayAfter="Vehicle"))
	TArray<EVehicleSurfaceType> AllowedVehicleSurfaces;

};

UCLASS()
class UFortObjectiveProcessor_DistanceTraveled : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

