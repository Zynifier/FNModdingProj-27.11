// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_LevelInstanceDevice.generated.h"

class ALevelInstanceGameplayVolume;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_LevelInstanceDevice : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<ALevelInstanceGameplayVolume> CachedGameplayVolume;

};

