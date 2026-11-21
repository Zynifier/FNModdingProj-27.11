// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_InfiniteResources.generated.h"

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InfiniteResources : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_bInfiniteResources();

protected:
	UFUNCTION(BlueprintCallable)
	void UpdateResourceIcons();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, ReplicatedUsing=OnRep_bInfiniteResources, Category="InfiniteResources")
	bool bInfiniteResources;

};

