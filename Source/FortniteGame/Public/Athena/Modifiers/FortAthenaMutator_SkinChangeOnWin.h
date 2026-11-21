// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortAthenaMutator_SkinChangeOnWin.generated.h"

UCLASS(HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SkinChangeOnWin : public AFortAthenaMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="OnWin")
	FFortAthenaLoadout CosmeticLoadoutToApplyOnWin;

	UPROPERTY(EditDefaultsOnly, Category="OnWin")
	FGameplayTag GameplayCueTagToApplyOnWin;

};

