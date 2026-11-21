// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PlayspaceComponent_PlayerSpawning.h"
#include "GameHubPlayerSpawningComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class GAMEHUBRUNTIME_API UGameHubPlayerSpawningComponent : public UPlayspaceComponent_PlayerSpawning
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="GameHubPlayerSpawningComponent")
	FGameplayTagContainer PlayerStartRequirements;

};

