// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTimeOfDayManager.h"
#include "FortTimeOfDayManagerAtmosphere.generated.h"

class USkyAtmosphereComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Transformation", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), ClassGroup=("Fog"))
class AFortTimeOfDayManagerAtmosphere : public AFortTimeOfDayManager
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="DayNightCycle", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkyAtmosphereComponent> SkyAtmosphereComponent;

};

