// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortBaseLayerAnimInstance.h"
#include "FortVehicleLayerAnimInstance_FerretPassenger.generated.h"

UCLASS(HideCategories=("AnimInstance"))
class UFortVehicleLayerAnimInstance_FerretPassenger : public UFortBaseLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_FerretPassenger")
	FFortAnimInput_FerretVehicle FerretVehicleInput;

};

