// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralGenerator.h"
#include "ProceduralScatterGenerator.generated.h"

class UProceduralScatterSettings;

UENUM(BlueprintType)
enum class EProceduralScatterMethod : uint8
{
	/** Scatters points based on density using tiles. */
	Density = 0,
	/** Scatter points around the points with Tag matching Source Point Tag. */
	SourcePoints = 1,
	/** Scatters points based on a grid. */
	Grid = 2,
};

UENUM(BlueprintType)
enum class EProceduralScatterTileRandomGenerator : uint8
{
	/** Pseudo random generator. */
	PseudoRandom = 0,
	/** Halton sequence generator. */
	HaltonSequence = 1,
};

USTRUCT(BlueprintType)
struct FProceduralScatterDebugSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugPlane;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugTrace;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugFootprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugHitNormal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug")
	bool bShowDebugPivots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Debug", meta=(ClampMax="10000000", ClampMin="0", UIMax="10000000", UIMin="0"))
	float DebugMaxCullingDistance;

};

USTRUCT(BlueprintType)
struct PROCEDURAL_API FProceduralScatterSettingsElement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(InlineEditConditionToggle))
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(EditCondition="bEnabled"))
	TObjectPtr<UProceduralScatterSettings> ScatterSettings;

	/** The maximum number of points to scatter for this element (0 means no maximum). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings", meta=(ClampMax="10000000", ClampMin="0", UIMax="10000000", UIMin="0"))
	int32 MaxPoints;

};

USTRUCT(BlueprintType)
struct FProceduralScatterTileSettings
{
	GENERATED_BODY()

public:
	/** The number of unique tiles to generate. The final result is a procedurally determined combination of the various unique tiles. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(ClampMin="1", UIMin="1"))
	int32 NumUniqueTiles;

	/** Length of the tile (in cm) along one axis. The total area of the tile will be TileSize*TileSize. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(ClampMax="100000", ClampMin="1000", UIMax="100000", UIMin="1000"))
	float TileSize;

	/** The amount of overlap between tiles (in percentage). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Distribution", meta=(ClampMax="50", ClampMin="0", DisplayName="Tile Overlap", UIMax="50", UIMin="0", Units="%"))
	float TileOverlapPercentage;

	/** Minimum size of the quad tree used during the generation. Reduce if too many instances are in splittable leaf quads (as warned in the log). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Distribution", meta=(ClampMin="0", UIMin="0"))
	float MinimumQuadTreeSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category="Distribution")
	EProceduralScatterTileRandomGenerator RandomGenerator;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, AutoExpandCategories=("InstanceSettings"))
class UProceduralScatterGenerator : public UProceduralGenerator
{
	GENERATED_BODY()

public:
	/** Scatter method. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution")
	EProceduralScatterMethod ScatterMethod;

	/** Scatter tiling settings */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(EditCondition="ScatterMethod == EProceduralScatterMethod::Density", ShowOnlyInnerProperties))
	FProceduralScatterTileSettings TileSettings;

	/** The seed used for generating the randomness of the generation. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, DuplicateTransient, AdvancedDisplay, Category="Distribution")
	int32 RandomSeed;

	/** The number of unique patterns to generate when using Source Point scatter method. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(ClampMin="0", EditCondition="ScatterMethod == EProceduralScatterMethod::SourcePoints", UIMin="0"))
	int32 NumUniqueSourcePointPatterns;

	/** The grid size (in cm) when using the Grid scatter method. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(ClampMin="0.100000", EditCondition="ScatterMethod == EProceduralScatterMethod::Grid", UIMin="0.100000"))
	FVector2D GridSize;

	/** The amount of jitter to use around the grid when using the Grid scatter method (in cm). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(EditCondition="ScatterMethod == EProceduralScatterMethod::Grid"))
	FVector2D GridJitter;

	/** The grid orientation when using the Grid scatter method. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(EditCondition="ScatterMethod == EProceduralScatterMethod::Grid"))
	float GridRotation;

	/** The grid offset when using the Grid scatter method. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Distribution", meta=(EditCondition="ScatterMethod == EProceduralScatterMethod::Grid"))
	FVector2D GridOffset;

	/** Scatter Settings elements */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="InstanceSettings")
	TArray<FProceduralScatterSettingsElement> ScatterSettingsElements;

	/** Scatter placement will consider hit world actors with one of the specified tags as blocking volumes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering")
	TArray<FName> BlockingActorTags;

	/** If checked, scatter placement will consider all scattered points and use their collision radius as blocking volumes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering")
	bool bAllScatterPointsBlocking;

	/** If checked, the scattered points will move along with the generation volume if it is moved/modified, otherwise, they will stay at the same position in the world, regardless of the generation volume). */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Distribution")
	bool bLocalDistribution;

	/** Scatter placement will consider scattered point tags and use their collision radius as blocking volumes. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filtering", meta=(EditCondition="!bAllScatterPointsBlocking"))
	TArray<FName> BlockingScatterPointTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Debug", meta=(ShowOnlyInnerProperties))
	FProceduralScatterDebugSettings ScatterDebugSettings;

};

