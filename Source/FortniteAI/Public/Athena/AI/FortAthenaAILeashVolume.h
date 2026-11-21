// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Math/MathFwd.h"
#include "FortAthenaAILeashVolume.generated.h"

UCLASS(HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaAILeashVolume : public AVolume
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Leash")
	FVector ProjectExtent;

	UPROPERTY(EditAnywhere, Category="Leash")
	float IsInsideTolerance;

};

