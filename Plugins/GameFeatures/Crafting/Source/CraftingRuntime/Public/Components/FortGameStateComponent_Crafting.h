// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataRegistryId.h"
#include "GameplayTagContainer.h"
#include "Components/FortGameStateComponent.h"
#include "Types/CraftingTypes.h"
#include "FortGameStateComponent_Crafting.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

UCLASS(Config=Crafting, MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_Crafting : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_CraftingResultsList();

	UPROPERTY(Config)
	FDataRegistryType CraftingFormulaRegistryType;

	UPROPERTY(Config)
	FDataRegistryType CraftingIngredientsUIDataRegistryType;

	UPROPERTY(ReplicatedUsing=OnRep_CraftingResultsList)
	TArray<FCraftingResult> CraftingResultsList;

};

