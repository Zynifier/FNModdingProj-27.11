// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "GameplayTagContainer.h"
#include "FortQueryTest_GameplayTagsPerDifficulty.generated.h"

USTRUCT()
struct FFortGameplayTagQueryPerDifficulty
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagQueryPerDifficulty")
	FDataTableRowHandle DifficultyInfo;

	UPROPERTY(EditDefaultsOnly, Category="FortGameplayTagQueryPerDifficulty")
	FGameplayTagQuery TagQueryToMatch;

	UPROPERTY(Transient)
	float Difficulty;

};

UCLASS()
class UFortQueryTest_GameplayTagsPerDifficulty : public UEnvQueryTest
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryTest_GameplayTagsPerDifficulty")
	TArray<FFortGameplayTagQueryPerDifficulty> TagQueriesPerDifficulty;

};

