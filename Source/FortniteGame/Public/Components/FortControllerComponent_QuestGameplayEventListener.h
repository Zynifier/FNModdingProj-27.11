// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "GameplayTagContainer.h"
#include "FortControllerComponent_QuestGameplayEventListener.generated.h"

class UFortObjectiveProcessor_PlayerReceivedGameplayEvent;

USTRUCT()
struct FObjectivesHolder
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_QuestGameplayEventListener : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerComponent_QuestGameplayEventListener(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UPROPERTY()
	TMap<FGameplayTag, FObjectivesHolder> ObjectiveHoldersByTag;

	UPROPERTY()
	TWeakObjectPtr<UFortObjectiveProcessor_PlayerReceivedGameplayEvent> GameplayEventObjectiveProcessor;

};

