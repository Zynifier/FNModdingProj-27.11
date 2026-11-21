// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_HealthAndShield.generated.h"

UENUM(BlueprintType)
enum class EAthenaMutatorEvaluators : uint8
{
	//Do not evaluate this

	NoOverride = 0,
	//Override the existing value with the mutator value

	ForceOverride = 1,
	//Add the mutator value to the existing value

	Add = 2,
	//Multiply the mutator value to the existing value

	Multiply = 3,
};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_HealthAndShield : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	EAthenaMutatorEvaluators NumericalMutatorOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	float StartingHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	float MaxShield;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Health")
	float StartingShield;

};

