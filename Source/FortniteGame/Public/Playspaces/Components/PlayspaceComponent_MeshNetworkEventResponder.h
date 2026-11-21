// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_MeshNetworkEventResponder.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UPlayspaceComponent_MeshNetworkEventResponder : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Mesh Network Event Responder | Data")
	TMap<FName, FGameplayTagContainer> ActiveEventsToTagsToApplyMap;

};

