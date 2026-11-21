// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_ActiveEventManager.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_ActiveEventManager : public UFortGameStateComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FString> EventsAlreadyApplied;

private:
	UFUNCTION()
	void HandleActiveSeasonDataChanged(const TArray<FString>& ActiveEventFlags);

	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

};

