// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortVehicleLayerAnimInstance.h"
#include "FortVehicleLayerAnimInstance_ShoppingCartPassenger.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortVehicleLayerAnimInstance_ShoppingCartPassenger : public UFortVehicleLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortVehicleLayerAnimInstance_ShoppingCartPassenger")
	FFortAnimInput_ShoppingCart ShoppingCartInput;

};

