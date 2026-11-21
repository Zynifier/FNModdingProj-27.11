// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Animation/FortVehicleAnimInstance.h"
#include "FortDagwoodVehicleAnimInstance.generated.h"

class AFortDagwoodVehicle;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortDagwoodVehicleAnimInstance : public UFortVehicleAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Vehicle")
	TObjectPtr<AFortDagwoodVehicle> Dagwood;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortDagwoodVehicleAnimInstance")
	FVector GlassScale_FR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortDagwoodVehicleAnimInstance")
	FVector GlassScale_FL;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortDagwoodVehicleAnimInstance")
	FVector GlassScale_BR;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortDagwoodVehicleAnimInstance")
	FVector GlassScale_BL;

};

