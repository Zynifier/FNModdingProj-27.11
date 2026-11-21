// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "VerseSimulationSubsystem.generated.h"

class AController;
class UVerseAgent;

// The Verse Simulation Subsystem provides a centralized respository for persistent verse::player and verse::agent objects
// There should be at most, a single object allocated for each unique player or controller present in the game. 
// System is created for transient world types like EWorldType::Game, EWorldType::PIE - therefore torn down  
// and recreated when these worlds are destroyed (e.g. server starting new game)

UCLASS()
class UVerseSimulationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<TWeakObjectPtr<AController>, TObjectPtr<UVerseAgent>> TrackedAgents;

};

