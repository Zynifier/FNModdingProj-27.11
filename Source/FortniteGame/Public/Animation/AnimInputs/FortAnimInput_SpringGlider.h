// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/MathFwd.h"
#include "FortAnimInput_SpringGlider.generated.h"

USTRUCT(BlueprintType)
struct FFortAnimInput_SpringGlider
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFloatSpringState GliderXRotationRightSpringLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFloatSpringState GliderYRotationRightSpringLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFloatSpringState GliderZLocationSpring;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFloatSpringState GliderXLocationSpring;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	FFloatSpringState GliderYLocationSpring;

	UPROPERTY(BlueprintReadWrite, Category="Glider")
	FRotator GliderOffsetRotator;

	UPROPERTY(BlueprintReadWrite, Category="Glider")
	FRotator GliderOffsetRotationRightLeg;

	UPROPERTY(BlueprintReadWrite, Category="Glider")
	FRotator GliderOffsetRotationLeftLeg;

	UPROPERTY(BlueprintReadWrite, Category="Glider")
	FVector GliderOffsetLocation;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderYOffsetRotationRightLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderYOffsetRotationLeftLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderXOffsetRotationRightLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderXOffsetRotationLeftLeg;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderZOffset;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderXOffset;

	UPROPERTY(BlueprintReadOnly, Category="Glider")
	float GliderYOffset;

};

