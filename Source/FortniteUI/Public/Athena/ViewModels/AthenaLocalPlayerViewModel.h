// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ViewModels/AthenaPlayerViewModel.h"
#include "AthenaLocalPlayerViewModel.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class UAthenaIndicatorPlayersCache;

UCLASS(MinimalAPI)
class UAthenaLocalPlayerViewModel : public UAthenaPlayerViewModel
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleLocalPlayerChangedTeams();

	UFUNCTION()
	void HandleViewTargetPlayerStateReplicated(AFortPlayerPawn* Pawn);

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerControllerAthena> PlayerController;

	UPROPERTY()
	TObjectPtr<UAthenaIndicatorPlayersCache> IndicatorCache;

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortPlayerPawn>> ListeningForPawnStates;

};

