// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ViewModels/AthenaPlayerViewModel.h"
#include "AthenaRemotePlayerViewModel.generated.h"

class AActor;
class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AFortPlayerStateAthena;

UCLASS(MinimalAPI)
class UAthenaRemotePlayerViewModel : public UAthenaPlayerViewModel
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleActorDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

private:
	UPROPERTY()
	TObjectPtr<AFortPlayerControllerSpectating> PlayerController;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> SquadList;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> NameIndicatedPlayers;

};

