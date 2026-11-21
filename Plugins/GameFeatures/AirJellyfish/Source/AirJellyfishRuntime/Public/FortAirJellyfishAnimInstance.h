// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortAnimInstance.h"
#include "FortAirJellyfishAnimInstance.generated.h"

UCLASS(HideCategories=("AnimInstance"))
class UFortAirJellyfishAnimInstance : public UFortAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAirJellyfishAnimInstance")
	float RotatorLerpRate;

	UPROPERTY(EditAnywhere, Category="FortAirJellyfishAnimInstance")
	float VelocityDirectionScalar;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAirJellyfishAnimInstance")
	FRotator RootRotation;

};

