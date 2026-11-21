// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GenerateOverlapEventsOverride.generated.h"

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GenerateOverlapEventsOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetCenterLocation(FVector NewCenterLocation);

	UFUNCTION(BlueprintCallable)
	void SetRadius(float NewRadius);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Override Values")
	uint8 bGenerateOverlapEventsOverrideValue : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GenerateOverlapEventsOverride")
	float Radius;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_GenerateOverlapEventsOverride")
	FVector CenterLocation;

};

