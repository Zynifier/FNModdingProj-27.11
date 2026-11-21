// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator_EnvironmentalDamage.h"
#include "FortAthenaMutator_CreativeEnvironmentalDamage.generated.h"

UENUM(BlueprintType)
enum class EAllowedToEdit : uint8
{
	Default = 0,
	Anyone = 1,
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CreativeEnvironmentalDamage : public AFortAthenaMutator_EnvironmentalDamage
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Mutator")
	EAllowedToEdit AllowedToEditFilter;

};

