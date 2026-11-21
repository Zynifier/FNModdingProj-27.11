// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "GameplayTagContainer.h"
#include "FortQueryContext_AllBots.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortQueryContext_AllBots : public UEnvQueryContext
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_AllBots")
	bool bIncludeOnlyAthenaGameParticipantBots;

	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_AllBots")
	FGameplayTagQuery BotTagQuery;

};

