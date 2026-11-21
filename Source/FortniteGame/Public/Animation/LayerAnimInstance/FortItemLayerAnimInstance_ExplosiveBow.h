// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/LayerAnimInstance/FortItemLayerAnimInstance.h"
#include "FortItemLayerAnimInstance_ExplosiveBow.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortItemLayerAnimInstance_ExplosiveBow : public UFortItemLayerAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemLayerAnimInstance_ExplosiveBow")
	FFortAnimInput_BowWeapon BowWeaponInput;

};

