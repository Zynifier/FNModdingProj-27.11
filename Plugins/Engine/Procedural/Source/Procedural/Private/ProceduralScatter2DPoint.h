// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralScatter2DPoint.generated.h"

class UProceduralScatterSettings;

/** Structure used to store scattered 2D points (used by ProceduralScatterGeneratorTile) */
USTRUCT()
struct PROCEDURAL_API FProceduralScatter2DPoint
{
	GENERATED_BODY()

public:
	/** Location point attribute. */
	UPROPERTY(EditAnywhere, Category="Procedural")
	FVector Location;

	/** Uniform scale point attribute. */
	UPROPERTY(EditAnywhere, Category="Procedural")
	float Scale;

	/** ScatterSettings object point attribute. */
	UPROPERTY(EditAnywhere, Category="Procedural")
	TObjectPtr<UProceduralScatterSettings> ScatterSettings;

	/** Used when inserting in ProceduralScatterGeneratorTile's Broadphase. */
	UPROPERTY()
	FBox2D MaxAABB;

	/** Point's footprint in broadphase. */
	UPROPERTY()
	float CollisionRadius;

	/** Flag set on points that will always dominate other points in broadphase. */
	UPROPERTY()
	bool bBlocker;

	/** Used to distribute probability for a point to dominate another point when other criteria are identical. */
	UPROPERTY()
	int32 RandomNumber;

};

