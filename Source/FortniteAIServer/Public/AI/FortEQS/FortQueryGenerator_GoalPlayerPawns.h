// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_GoalPlayerPawns.generated.h"

UCLASS(meta=(DisplayName="Goal: Athena Player Pawns"))
class UFortQueryGenerator_GoalPlayerPawns : public UEnvQueryGenerator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	bool bOnlyAthenaGameParticipants;

};

