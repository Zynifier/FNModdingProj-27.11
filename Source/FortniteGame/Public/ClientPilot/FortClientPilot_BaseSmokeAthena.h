// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilot/FortClientPilot_GameplayAthena.h"
#include "FortClientPilot_BaseSmokeAthena.generated.h"

USTRUCT()
struct FFortClientPilotConsumableTestDefinition
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortClientPilotMovementTestDefinition
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
class UFortClientPilot_BaseSmokeAthena : public UFortClientPilot_GameplayAthena
{
	GENERATED_BODY()

};

