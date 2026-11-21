// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Carmine.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Carmine : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	FGameplayTag JimInventoryTag;

	UPROPERTY(Transient)
	FGameplayTag JimPickupTag;

};

