// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "FortQueryGenerator_SquadMembers.generated.h"

UCLASS(meta=(DisplayName="Get SquadMembers"))
class UFortQueryGenerator_SquadMembers : public UEnvQueryGenerator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue LookingForHumanPlayers;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue LookingForPlayerBots;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue LookingForNpcs;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue LookingForAiPawns;

	UPROPERTY(EditDefaultsOnly, Category="Generator")
	FAIDataProviderBoolValue IncludeSelf;

};

