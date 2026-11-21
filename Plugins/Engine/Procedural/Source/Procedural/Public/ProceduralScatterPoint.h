// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralHitPoint.h"
#include "ProceduralScatterPoint.generated.h"

class UProceduralScatterSettings;

USTRUCT(BlueprintType)
struct FProceduralScatterPoint
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	FVector Location;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	FRotator Rotation;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	float Scale;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	TObjectPtr<UProceduralScatterSettings> ScatterSettings;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	int32 VariationIdx;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	FVector GenerationLocation;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Scatter Point")
	FProceduralHitPoint HitPoint;

};

