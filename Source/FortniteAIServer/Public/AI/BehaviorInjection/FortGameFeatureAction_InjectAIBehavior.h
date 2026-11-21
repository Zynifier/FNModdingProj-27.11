// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/BehaviorInjection/FortAISpawnerTagQueryInjectedBehavior.h"
#include "GameFeatures/FortGameInstanceGameFeatureAction.h"
#include "FortGameFeatureAction_InjectAIBehavior.generated.h"

UCLASS(MinimalAPI, meta=(DisplayName="Inject AI Behaviors"))
class UFortGameFeatureAction_InjectAIBehavior : public UFortGameInstanceGameFeatureAction
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Injected behaviors")
	TArray<FFortAISpawnerTagQueryInjectedBehavior> InjectedBehaviors;

};

