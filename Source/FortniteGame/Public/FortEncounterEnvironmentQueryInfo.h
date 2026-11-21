// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "FortEncounterEnvironmentQueryInfo.generated.h"

class UEnvQuery;

USTRUCT(BlueprintType)
struct FEncounterEnvironmentQueryInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	TObjectPtr<UEnvQuery> EnvironmentQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	TArray<FEnvNamedValue> QueryParams;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EnvironmentQuery")
	bool bIsDirectional;

};

