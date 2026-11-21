// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortPluginActorSpawner.generated.h"

class UChildActorComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Collision", "Input"))
class AFortPluginActorSpawner : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FGameplayTag TagToPluginActor;

	UPROPERTY()
	FScalableFloat MinSpawnChance;

	UPROPERTY()
	FScalableFloat MaxSpawnChance;

	UPROPERTY()
	uint8 bWaitForPlaylistLoad : 1;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UChildActorComponent> PreviewActorComponent;
#endif

};

