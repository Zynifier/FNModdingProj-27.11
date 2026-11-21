// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_CreativeSlide.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class ECanSlideMutatorType : uint8
{
	Unset = 0,
	Yes = 1,
	No = 2,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeSlide : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Slide")
	ECanSlideMutatorType CanSlide;

};

