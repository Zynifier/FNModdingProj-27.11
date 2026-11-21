// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Playspaces/FortPlayspace.h"
#include "GameHubPlayspace.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class GAMEHUBRUNTIME_API AGameHubPlayspace : public AFortPlayspace
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="GameHubPlayspace")
	bool bSimulatePlayerDamage;

	UPROPERTY(EditDefaultsOnly, Category="GameHubPlayspace")
	FGameplayTagContainer PlayerStartRequirements;

};

