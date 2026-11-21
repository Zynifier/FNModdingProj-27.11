// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_OverrideTODMSkylightCubemap.generated.h"

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EOverrideCubemapType : uint8
{
	No = 0,
	Yes = 1,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_OverrideTODMSkylightCubemap : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Override Cubemap")
	EOverrideCubemapType OverrideCubemapType;

};

