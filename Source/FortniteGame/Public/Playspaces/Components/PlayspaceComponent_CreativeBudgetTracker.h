// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayspaceComponent.h"
#include "PlayspaceComponent_CreativeBudgetTracker.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlayspaceComponent_CreativeBudgetTracker : public UPlayspaceComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PlayspaceComponent_CreativeBudgetTracker")
	float UpdateFrequencyInSeconds;

};

