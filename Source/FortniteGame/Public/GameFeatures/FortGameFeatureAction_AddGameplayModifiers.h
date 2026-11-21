// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "FortGameFeatureAction_AddGameplayModifiers.generated.h"

class UFortGameplayModifierItemDefinition;

UCLASS(MinimalAPI, meta=(DisplayName="Add Gameplay Modifiers"))
class UFortGameFeatureAction_AddGameplayModifiers : public UGameFeatureAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Gameplay Modifiers")
	TArray<TSoftObjectPtr<UFortGameplayModifierItemDefinition>> GameplayModifiers;

};

