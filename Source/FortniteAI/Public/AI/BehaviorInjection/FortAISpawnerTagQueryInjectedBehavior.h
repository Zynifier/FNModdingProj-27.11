// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AI/BehaviorInjection/FortInjectedBehavior.h"
#include "FortAISpawnerTagQueryInjectedBehavior.generated.h"

USTRUCT()
struct FFortAISpawnerTagQueryInjectedBehavior
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Injected Behaviors")
	FGameplayTagQuery SpawnerTagsQuery;

	UPROPERTY(EditAnywhere, Category="Injected Behaviors")
	TArray<FFortInjectedBehaviorEntry> InjectedBehaviors;

};

