// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_MultiInteraction.generated.h"

UENUM(BlueprintType)
enum class EMultiInteractionMutatorType : uint8
{
	Unset = 0,
	On = 1,
	Off = 2,
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_MultiInteraction : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_MultiInteraction")
	EMultiInteractionMutatorType MultiInteractionEnabledType;

};

