// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortClientBotManagerAthena.h"
#include "FortClientBotManagerAthena_Smoke.generated.h"

USTRUCT()
struct FConsumableTestDefinition
{
	GENERATED_BODY()

};

USTRUCT()
struct FMovementTestDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ForwardMoveStrength;

	UPROPERTY()
	float SideMoveStrength;

	UPROPERTY()
	float Duration;

	UPROPERTY()
	FString TestName;

};

UCLASS()
class UFortClientBotManagerAthena_Smoke : public UFortClientBotManagerAthena
{
	GENERATED_BODY()

};

