// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/FortGameStatePvE.h"
#include "FortGameStateSurvival.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateSurvival : public AFortGameStatePvE
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Score Screen")
	bool bFireEndOfDayDelegate;

	UPROPERTY(EditDefaultsOnly, Category="Score Screen")
	float TimeToDelayEndOfDayZoneScoreWidgetDisplay;

};

