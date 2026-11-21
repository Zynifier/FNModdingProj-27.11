// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortVehicleLayerAnimInstance.h"
#include "FortVehicleLayerAnimInstance_GolfcartPassenger.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleLayerAnimInstance_GolfcartPassenger : public UFortVehicleLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FortVehicleLayerAnimInstance_GolfcartPassenger")
	FFortAnimInput_GolfCart GolfCartVehicleInput;

};

