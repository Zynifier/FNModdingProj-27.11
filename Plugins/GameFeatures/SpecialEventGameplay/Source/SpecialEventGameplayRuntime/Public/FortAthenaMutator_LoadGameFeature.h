// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_LoadGameFeature.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_LoadGameFeature : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_LoadGameFeature")
	FString GameFeatureToLoad;

};

