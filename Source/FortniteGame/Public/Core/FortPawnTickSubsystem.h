// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortPawnTickSubsystem.generated.h"

class AFortPlayerPawn;

UCLASS(MinimalAPI)
class UFortPawnTickSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> Pawns;

};

