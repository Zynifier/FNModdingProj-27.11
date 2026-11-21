// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "FortObjectiveProcessor_Land.generated.h"

USTRUCT(meta=(DisplayName="Land"))
struct FFortObjectiveFilter_Land : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Land")
	FFortObjectiveFilterType_NearbyPlayers NearbyPlayersFilter;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Land")
	TSet<TEnumAsByte<EPhysicalSurface>> AllowedSurfaces;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_Land")
	TSet<TEnumAsByte<EPhysicalSurface>> ExcludedSurfaces;

};

UCLASS()
class UFortObjectiveProcessor_Land : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

