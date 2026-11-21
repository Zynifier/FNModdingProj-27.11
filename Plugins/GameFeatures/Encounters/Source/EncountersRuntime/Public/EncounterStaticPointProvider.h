// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EncounterPointProviderInterface.h"
#include "FortAthenaLivingWorldStaticPointProvider.h"
#include "EncounterStaticPointProvider.generated.h"

UCLASS(MinimalAPI)
class AEncounterStaticPointProvider : public AFortAthenaLivingWorldStaticPointProvider, public IEncounterPointProviderInterface
{
	GENERATED_BODY()

};

