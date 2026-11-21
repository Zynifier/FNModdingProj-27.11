// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaLivingWorldPlayerTracker.generated.h"

class AController;
class AFortAthenaAIBotController;
class AFortPlayerPawn;

USTRUCT()
struct FFortAthenaLivingWorldPlayerTracker
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortAthenaAIBotController>> TrackedBotControllers;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawn>> TrackedPlayerPawns;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AController>> TrackedPlayerControllers;

};

