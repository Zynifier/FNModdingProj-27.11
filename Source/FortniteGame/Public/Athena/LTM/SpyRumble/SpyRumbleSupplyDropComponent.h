// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpyRumbleSupplyDropComponent.generated.h"

class AFortAthenaMutator_SpyRumble;
class AFortPlayerControllerAthena;

UCLASS(HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision"), ClassGroup=("Fortnite"), meta=(BlueprintSpawnableComponent))
class USpyRumbleSupplyDropComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnSupplyDropCollected(AFortPlayerControllerAthena* PlayerController);

protected:
	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_SpyRumble> CachedMutator;

};

