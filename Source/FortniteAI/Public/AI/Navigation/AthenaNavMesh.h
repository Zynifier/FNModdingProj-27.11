// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "AI/FortNavMesh.h"
#include "AthenaNavMesh.generated.h"

class AAthenaNavMesh;

USTRUCT()
struct FUpdatedNavMeshTiles
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	AAthenaNavMesh* NavMesh;

};

UCLASS(MinimalAPI, HideCategories=("Input", "Rendering", "Tags", "Transformation", "Actor", "Layers", "Replication"))
class AAthenaNavMesh : public AFortNavMesh
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Navigation")
	void ComputeOffsetForMoveTiles(const FVector& StartPosition, const FVector& DesiredPosition, FVector& OutEndPosition, FIntPoint& OutTileOffset);

	UFUNCTION(BlueprintCallable, Category="Navigation")
	void MoveTiles(const FBox& SourceBox, const FIntPoint& TileOffset, const float RotationDeg, const FVector2D& FillerTilePosition);

protected:
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query", meta=(ClampMin="1", UIMin="1"))
	int32 HotSpotPathfindingMaxSearchNodes;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	float ShallowWaterTraceStartOffsetZ;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	float ShallowWaterTraceEndOffsetZ;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Query")
	int32 MaximumTilesToProcessForWaterPerFrame;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Performance")
	bool bSuspendNavmeshWhenNoAIUsersAlive;

	UPROPERTY()
	TArray<FBox> SerializedDirtyAreas;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Athena Generation")
	uint8 bAutoLoadPreviewLevelsDuringBuild : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bDrawSerializedDirtyAreas : 1;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Display", meta=(DisplayAfter="bDrawOctreeDetails", editcondition="bDrawOctree"))
	uint8 bDrawNavOctreeElements : 1;
#endif

};

