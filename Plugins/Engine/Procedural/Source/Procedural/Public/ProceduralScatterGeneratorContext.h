// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProceduralGeneratorContext.h"
#include "ProceduralScatterPoint.h"
#include "ProceduralScatterProjectionPoint.h"
#include "ProceduralScatterGeneratorContext.generated.h"

class UMaterialInstanceDynamic;
class UProceduralPointCloud;
class UProceduralScatterGeneratorTile;

USTRUCT(BlueprintType)
struct FScatteredPointCloud
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FProceduralScatterPoint> Points;

};

USTRUCT()
struct FSourcePointGenerator
{
	GENERATED_BODY()

};

UCLASS()
class UProceduralScatterGeneratorContext : public UProceduralGeneratorContext
{
	GENERATED_BODY()

protected:
	/** Generated point cloud. */
	UPROPERTY(BlueprintReadOnly, Transient, NonTransactional, Category="Procedural Scatter Point Cloud")
	FScatteredPointCloud ScatteredPointCloud;

private:
	/** List of unique tiles that contain cached points scattered in tiles. */
	UPROPERTY(Transient, NonTransactional)
	TArray<TObjectPtr<UProceduralScatterGeneratorTile>> UniqueTiles;

	/** List of unique tiles per source points tag that contain points scattered in a annular shape. */
	UPROPERTY(Transient, NonTransactional)
	TArray<FSourcePointGenerator> SourcePointGenerators;

	/** Projection point cloud (prior to trace in world). */
	UPROPERTY(Transient, NonTransactional)
	TArray<FProceduralScatterProjectionPoint> ProjectionPointCloud;

	/** Source point cloud : list of points that can act as source generators in SourcePoint mode. */
	UPROPERTY(Transient, NonTransactional)
	TObjectPtr<UProceduralPointCloud> SourcePointCloud;

	/** Blocker point cloud : list of points that act as blockers. */
	UPROPERTY(Transient, NonTransactional)
	TObjectPtr<UProceduralPointCloud> BlockerPointCloud;

	/** Projection vector material used for visualization. */
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> ProjectionVectorMaterial;

};

