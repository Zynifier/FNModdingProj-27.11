// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ReroutePlayerEvent.generated.h"

USTRUCT(BlueprintType)
struct FReroutePlayerEventDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ReroutePlayerEventDefinition")
	FGameplayTagContainer IncomingEventTags;

	UPROPERTY(EditDefaultsOnly, Category="ReroutePlayerEventDefinition")
	FGameplayTagContainer IncludeTags;

	UPROPERTY(EditDefaultsOnly, Category="ReroutePlayerEventDefinition")
	FGameplayTagContainer ExcludeTags;

	UPROPERTY(EditDefaultsOnly, Category="ReroutePlayerEventDefinition")
	FGameplayTag ImmediateOutgoingEventTag;

	UPROPERTY(EditDefaultsOnly, Category="ReroutePlayerEventDefinition")
	FGameplayTag MergedOutgoingEventTag;

};

USTRUCT()
struct FReroutePlayerEventQueueEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayEventData GameplayEventData;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Actor", "LOD", "Cooking", "Replication", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ReroutePlayerEvent : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_ReroutePlayerEvent")
	TArray<FReroutePlayerEventDefinition> RerouteDefinitions;

private:
	UFUNCTION()
	void FlushEventQueue();

};

