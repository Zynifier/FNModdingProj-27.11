// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_NamePlate.generated.h"

UENUM(BlueprintType)
enum class EIndicatorDisplayMode : uint8
{
	Default = 0 UMETA(DisplayName="Always Show To Team"),
	Always = 1 UMETA(DisplayName="Always Show To All"),
	Never = 2 UMETA(DisplayName="Always Hide"),
	MiniMap = 3,
	Custom = 4,
};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_NamePlate : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_DisplayMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, ReplicatedUsing=OnRep_DisplayMode, Category="UI")
	EIndicatorDisplayMode DisplayMode;

};

