// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_FallDamageMultiplier.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_FallDamageMultiplier : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FallDamageMultiplier")
	bool bFallDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FallDamageMultiplier")
	bool bFallDamageAllowedBeforeMinigameStarted;

};

