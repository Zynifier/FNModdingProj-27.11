// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralHitPoint.h"
#include "ProceduralScatterProjectionPoint.generated.h"

class UProceduralScatterSettings;

USTRUCT()
struct FProceduralScatterProjectionPoint
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector GenerationLocation;

	UPROPERTY()
	FRotator Rotation;

	UPROPERTY()
	float Scale;

	UPROPERTY()
	TObjectPtr<UProceduralScatterSettings> ScatterSettings;

	UPROPERTY()
	int32 VariationIdx;

	// Trace Info

	UPROPERTY()
	FVector StartTrace;

	UPROPERTY()
	FVector EndTrace;

	UPROPERTY()
	FProceduralHitPoint HitPoint;

};

