// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortActorSpawner.h"
#include "FortSpecialRelevancyActorSpawner.generated.h"

class AActor;

UCLASS(HideCategories=("Tick", "Collision", "Input"))
class SPECIALEVENTGAMEPLAYRUNTIME_API AFortSpecialRelevancyActorSpawner : public AFortActorSpawner
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Spawning", meta=(DisplayName="OnActorSpawnedPerRelevancyGroup"))
	void BP_OnActorSpawnedPerRelevancyGroup(const TArray<AActor*>& InSpawnedActors);

};

