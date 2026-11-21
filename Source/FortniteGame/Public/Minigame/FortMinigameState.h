// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "FortMinigameState.generated.h"

UCLASS(Config=Creative, NotPlaceable, Deprecated, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(DeprecationMessage="FortMinigameMode and FortMinigameState have been replaced by FortMinigame", ScriptName="DeprecatedMinigameState"))
class ADEPRECATED_FortMinigameState : public AInfo
{
	GENERATED_BODY()

};

