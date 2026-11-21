// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "DynamicUI/DynamicUIDirectorBase.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortCreativeDynamicUIDirector.generated.h"

class UDynamicUIScene;

UCLASS(MinimalAPI, HideCategories=("Actor", "ActorTick", "Collision", "Cooking", "DataLayers", "Events", "HLOD", "Input", "LOD", "Physics", "Rendering", "Replication", "WorldPartition"))
class AFortCreativeDynamicUIDirector : public ADynamicUIDirectorBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlayerEnteredSpatialGameplayActor(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& Context);

	UPROPERTY(EditDefaultsOnly, Category="FortCreativeDynamicUIDirector")
	TMap<FGameplayTag, TObjectPtr<UDynamicUIScene>> CreativeScenesMap;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UDynamicUIScene>> ActiveScenesMap;

};

