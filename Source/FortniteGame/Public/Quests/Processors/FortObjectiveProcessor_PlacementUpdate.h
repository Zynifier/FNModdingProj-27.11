// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessor.h"
#include "FortObjectiveProcessor_PlacementUpdate.generated.h"

USTRUCT(meta=(DisplayName="Placement Update"))
struct FFortObjectiveFilter_PlacementUpdate : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate", meta=(EditCondition="bUseCurrentPlacement", UIMin="0"))
	FInt32Range CurrentPlacement;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate", meta=(InlineEditConditionToggle))
	uint8 bUseCurrentPlacement : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate", meta=(InlineEditConditionToggle))
	uint8 bUsePlayersAlive : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate")
	uint8 bRequirePlacementSetByAuthor : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate", meta=(EditCondition="bUsePlayersAlive", UIMin="0"))
	FInt32Range PlayersAlive;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlacementUpdate")
	FObjectiveSubjectTags PlayerThatSetPlacement;

};

UCLASS()
class UFortObjectiveProcessor_PlacementUpdate : public UFortObjectiveProcessor
{
	GENERATED_BODY()

};

