// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CreativeRespawnWave.generated.h"

UENUM(BlueprintType)
enum class ECreativeRespawnWaveType : uint8
{
	None = 0 UMETA(DisplayName="Individual"),
	WaveStartingOnElimination = 1 UMETA(DisplayName="Wave"),
};

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeRespawnWave : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="RespawnTime")
	ECreativeRespawnWaveType RespawnWaveType;

};

