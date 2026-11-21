// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "FortAsyncAction_CurrentPlaylistReady.generated.h"

class AFortGameStateAthena;
class UFortAsyncAction_CurrentPlaylistReady;
class UFortPlaylist;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FPlaylistReadyAsyncDelegate, AFortGameStateAthena*, GameState, const UFortPlaylist*, Playlist, const FGameplayTagContainer&, PlaylistContextTags);

UCLASS(MinimalAPI)
class UFortAsyncAction_CurrentPlaylistReady : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", WorldContext="WorldContextObject"))
	static UFortAsyncAction_CurrentPlaylistReady* PlaylistDataReadyAsync(UObject* WorldContextObject);

	UPROPERTY(BlueprintAssignable)
	FPlaylistReadyAsyncDelegate OnReady;

private:
	UFUNCTION()
	void HandlePlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

};

