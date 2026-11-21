// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Online/FortMcpProfile.h"
#include "FortMcpProfileAthenaStats.generated.h"

class UAthenaSeasonStats;

UCLASS(MinimalAPI)
class UFortMcpProfileAthenaStats : public UFortMcpProfile
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	TArray<UAthenaSeasonStats*> GetLifeTimeAndSeasonList();

	UFUNCTION(BlueprintCallable)
	UAthenaSeasonStats* GetLifetimeStats();

private:
	UPROPERTY()
	TObjectPtr<UAthenaSeasonStats> LifeTimeStats;

	UPROPERTY()
	TArray<TObjectPtr<UAthenaSeasonStats>> LifeTimeAndSeasonStatsList;

};

