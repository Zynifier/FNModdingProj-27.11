// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Playspaces/FortPlayspace.h"
#include "SidewaysPlayspace.generated.h"

UCLASS(Config=Game, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class ASidewaysPlayspace : public AFortPlayspace
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void NotifySizeChanged();

	UFUNCTION(BlueprintCallable)
	void RefreshActorsInSideways();

};

