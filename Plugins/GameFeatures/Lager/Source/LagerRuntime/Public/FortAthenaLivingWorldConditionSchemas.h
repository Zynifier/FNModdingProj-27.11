// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorldConditionSchema.h"
#include "FortAthenaLivingWorldConditionSchemas.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaLivingWorldConditionSchema : public UWorldConditionSchema
{
	GENERATED_BODY()

};

UCLASS()
class UFortAthenaLivingWorldEventDataConditionSchema : public UFortAthenaLivingWorldConditionSchema
{
	GENERATED_BODY()

};

