// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAnimInputGrindRail.generated.h"

USTRUCT(BlueprintType)
struct FFortAnimInput_GrindRail
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	uint8 bAimFWD : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	uint8 bAimBWD : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	uint8 bAimLFT : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	uint8 bAimRGT : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	float AimFWDDeltaAngleDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	float AimBWDDeltaAngleDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	float AimLFTDeltaAngleDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	float AimRGTDeltaAngleDegrees;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Grind Rail")
	float PawnToSplineDeltaYawAngleDegrees;

};

