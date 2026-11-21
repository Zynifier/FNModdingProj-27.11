// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STW/FortGameStatePvE.h"
#include "FortGameStateEndless.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameStateEndless : public AFortGameStatePvE
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable)
	int32 GetWaveNumber();

	UFUNCTION(BlueprintCallable)
	void SetWaveNumber(int32 NewWaveNumber);

	UPROPERTY(Replicated)
	int32 WaveNumber;

};

