// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EncounterPointProviderInterface.h"
#include "FortAthenaPatrolPathPointProvider.h"
#include "EncounterPatrolPathPointProvider.generated.h"

UCLASS()
class AEncounterPatrolPathPointProvider : public AFortAthenaPatrolPathPointProvider, public IEncounterPointProviderInterface
{
	GENERATED_BODY()

};

