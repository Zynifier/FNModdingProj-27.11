// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortAthenaMutator_BlockBuilding.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_BlockBuilding : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, Category="BlockBuilding")
	const FGameplayTagContainer GetHUDVisibilityTags() const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="BlockBuilding")
	EBuildingMode AllowBuilding;

};

