// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryGenerator.h"
#include "GameplayTagContainer.h"
#include "TokenProviderQueryGenerator.generated.h"

UCLASS()
class FORTNITEAISERVER_API UTokenProviderQueryGenerator : public UEnvQueryGenerator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Provider")
	FGameplayTagQuery GameplayTagQuery;

};

