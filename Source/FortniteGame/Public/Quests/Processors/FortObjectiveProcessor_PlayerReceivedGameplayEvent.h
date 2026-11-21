// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Quests/Processors/EventProcessorTypes.h"
#include "Quests/Processors/FortObjectiveProcessorHelper.h"
#include "Quests/Processors/ObjectiveProcessor.h"
#include "FortObjectiveProcessor_PlayerReceivedGameplayEvent.generated.h"

USTRUCT(meta=(DisplayName="Player Received Gameplay Event"))
struct FFortObjectiveFilter_PlayerReceivedGameplayEvent : public FObjectiveFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerReceivedGameplayEvent")
	FGameplayTag GameplayEventTag;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerReceivedGameplayEvent")
	FEventPayloadFilter GameplayEventFilter;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerReceivedGameplayEvent", meta=(DisplayName="Require that the instigator is the Author"))
	uint8 bRequireAuthorInstigator : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerReceivedGameplayEvent", meta=(DisplayName="Require that the target is the Author"))
	uint8 bRequireAuthorTarget : 1;

	UPROPERTY(EditAnywhere, Category="FortObjectiveFilter_PlayerReceivedGameplayEvent", meta=(DisplayPriority="-1"))
	uint8 bIncrementByEventMagnitude : 1;

};

UCLASS()
class UFortObjectiveProcessor_PlayerReceivedGameplayEvent : public UObjectiveProcessor
{
	GENERATED_BODY()

};

