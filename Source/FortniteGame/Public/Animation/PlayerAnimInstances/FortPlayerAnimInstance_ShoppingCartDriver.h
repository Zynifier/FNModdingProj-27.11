// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/PlayerAnimInstances/FortPlayerAnimInstanceProxy.h"
#include "FortPlayerAnimInstance_ShoppingCartDriver.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortPlayerAnimInstance_ShoppingCartDriver : public UFortPlayerAnimInstanceProxy
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Category="FortPlayerAnimInstance_ShoppingCartDriver")
	FFortAnimInput_ShoppingCart ShoppingCartInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ShoppingCartDriver")
	FFortAnimInput_VelocityImpact VelocityImpact;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ShoppingCartDriver")
	FVector ImpactDisplacement;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="ShoppingCart")
	bool bIsInAirFarFromGround;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="ShoppingCart")
	bool bForwardVelocityGT400;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="ShoppingCart")
	bool bForwardSpeedKmHLT5;

};

