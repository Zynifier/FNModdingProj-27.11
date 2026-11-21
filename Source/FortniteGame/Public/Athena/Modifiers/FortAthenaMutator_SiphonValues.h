// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_SiphonValues.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SiphonValues : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SiphonValues")
	float HealthSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SiphonValues")
	float WoodSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SiphonValues")
	float StoneSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SiphonValues")
	float MetalSiphonValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="SiphonValues")
	float GoldSiphonValue;

};

