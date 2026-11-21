// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortValetSedanAnimInstance.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortValetSedanAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Mods")
	bool bHasTireMod;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Damage Alphas")
	float TrunkDamageAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Damage Alphas")
	float MirrorLeftDamageAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Damage Alphas")
	float MirrorRightDamageAlpha;

};

