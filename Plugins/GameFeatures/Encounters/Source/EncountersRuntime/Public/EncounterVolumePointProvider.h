// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EncounterPointProviderInterface.h"
#include "FortAthenaLivingWorldVolume.h"
#include "EncounterVolumePointProvider.generated.h"

UCLASS(MinimalAPI, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AEncounterVolumePointProvider : public AFortAthenaLivingWorldVolume, public IEncounterPointProviderInterface
{
	GENERATED_BODY()

};

