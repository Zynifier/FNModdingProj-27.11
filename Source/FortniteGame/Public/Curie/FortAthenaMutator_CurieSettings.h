// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CurieSettings.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CurieSettings : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Curie")
	bool bIsCurieEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Curie")
	bool bIsCurieEnabledOutsideOfGame;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Curie")
	bool bIsGrassFireBoundsUpdateEnabled;

};

