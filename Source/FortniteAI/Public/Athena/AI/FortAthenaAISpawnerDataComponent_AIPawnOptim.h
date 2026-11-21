// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_OptimBase.h"
#include "FortAthenaAISpawnerDataComponent_AIPawnOptim.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AIPawnOptim : public UFortAthenaAISpawnerDataComponent_OptimBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Deimos", meta=(AllowPrivateAccess="true"))
	uint8 bRegisterToAIDropper : 1;

};

