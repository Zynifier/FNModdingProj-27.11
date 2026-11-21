// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_TournamentStatsTracker.generated.h"

USTRUCT()
struct FTrackedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EventId;

	UPROPERTY()
	FString EventWindowId;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_TournamentStatsTracker : public UFortControllerComponent
{
	GENERATED_BODY()

private:
	UFUNCTION(Server, Reliable)
	void Server_SendTrackedEvent(FTrackedEvent InTrackedEvents);

};

