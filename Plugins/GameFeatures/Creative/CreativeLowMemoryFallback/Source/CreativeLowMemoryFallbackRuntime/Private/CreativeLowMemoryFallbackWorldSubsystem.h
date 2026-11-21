// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Subsystems/WorldSubsystem.h"
#include "CreativeLowMemoryFallbackSettings.h"
#include "CreativeLowMemoryFallbackWorldSubsystem.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;

UCLASS()
class UCreativeLowMemoryFallbackWorldSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPlaylistDataChanged(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Transient)
	FCreativeLowMemoryFallbackFreeMemoryThresholds CurrentThresholds;

};

