// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_InputContextTracker.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_InputContextTracker : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(CPP_Default_ContextTagsToAdd="()", CPP_Default_ContextTagsToRemove="()"))
	void UpdateContexts(const FGameplayTagContainer& ContextTagsToAdd, const FGameplayTagContainer& ContextTagsToRemove, bool bForceUpdate = false);

};

