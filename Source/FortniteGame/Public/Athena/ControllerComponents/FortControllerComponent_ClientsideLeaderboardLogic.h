// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortTypes.h"
#include "FortControllerComponent_ClientsideLeaderboardLogic.generated.h"

class AFortGameStateAthena;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_ClientsideLeaderboardLogic : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortInGameLeaderboardPlacementData> Leaderboard;

	UPROPERTY()
	TObjectPtr<AFortGameStateAthena> CachedGameState;

};

