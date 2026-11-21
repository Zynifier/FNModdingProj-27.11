// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/HotSpots/FortAIHotSpot.h"
#include "FortAIHotSpot_Building.generated.h"

class UAIHotSpotConfig;

UCLASS(MinimalAPI, HideCategories=("Object", "Actor", "Input", "Rendering"))
class AFortAIHotSpot_Building : public AFortAIHotSpot
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UAIHotSpotConfig> ExtraTypeConfig;

};

