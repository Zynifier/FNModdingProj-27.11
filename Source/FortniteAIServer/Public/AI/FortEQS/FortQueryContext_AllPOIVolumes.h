// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "GameplayTagContainer.h"
#include "FortQueryContext_AllPOIVolumes.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortQueryContext_AllPOIVolumes : public UEnvQueryContext
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortQueryContext_AllPOIVolumes")
	FGameplayTagQuery VolumeLocationTagQuery;

};

