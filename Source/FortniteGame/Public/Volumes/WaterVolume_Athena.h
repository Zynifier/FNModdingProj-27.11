// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Volumes/WaterVolume_Shallow.h"
#include "WaterVolume_Athena.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AWaterVolume_Athena : public AWaterVolume_Shallow
{
	GENERATED_BODY()

};

