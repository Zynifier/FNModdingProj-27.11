// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "DataRegistryId.h"
#include "GameplayTagContainer.h"
#include "FortGameStateComponent_ServerRollQuests.generated.h"

class AFortGameStateAthena;
class UDataRegistry;
class UFortPlaylist;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class SERVERROLLQUESTSRUNTIME_API UFortGameStateComponent_ServerRollQuests : public UGameStateComponent
{
	GENERATED_BODY()

public:
	UFortGameStateComponent_ServerRollQuests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

private:
	UFUNCTION()
	void HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& GameplayTags);

	UFUNCTION()
	void PopulateMap(const UDataRegistry* ServerRollQuestsRegistry, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(Config)
	FDataRegistryType DataRegistryType_ServerRollQuests;

};

