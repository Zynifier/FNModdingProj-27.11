// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Math/MathFwd.h"
#include "Building/BuildingTypes.h"
#include "Building/StructuralSupport/BuildingStructuralSupportSystem.h"
#include "FortInteriorAudioTypes.generated.h"

class AActor;
class ABuildingSMActor;

UENUM(BlueprintType)
enum class EInteriorAudioBuildingDefaultRotation : uint8
{
	PositiveY = 0,
	NegativeX = 1,
	NegativeY = 2,
	PositiveX = 3,
};

UENUM(BlueprintType)
enum class EInteriorAudioBuildingDirection : uint8
{
	Left = 0,
	Right = 1,
	Forward = 2,
	Backward = 3,
	Upward = 4,
};

UENUM(BlueprintType)
enum class EInteriorAudioBuildingEvaluation : uint8
{
	Invalid = 0,
	Partial = 1,
	Solid = 2,
};

UENUM(BlueprintType)
namespace EInteriorAudioBuildingRelativePosition
{
	enum Type
	{
		SameCell = 0,
		SameCellQuadrantTestFailed = 1,
		OtherCellParallelToForward = 2,
		OtherCellParallelToRight = 3,
		OtherCellParallelToUp = 4,
		Max_None = 5 UMETA(DisplayName="None"),
	};
}

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
namespace EInteriorAudioBuildingTags
{
	enum Type
	{
		None = 0,
		HasDoors = 1,
		RotationDependant = 2,
		UseConditionalEvaluation = 3,
	};
}

UENUM(BlueprintType)
enum class EInteriorAudioBuildingType : uint8
{
	None = 0,
	Wall = 1,
	Floor = 2,
	CenterCell = 3,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EInteriorAudioQuadrant : uint8
{
	None = 0,
	Left = 1,
	Right = 2,
	Top = 4,
	Bottom = 8,
};

USTRUCT(BlueprintType)
struct FFortInteriorAudioSphereTraceResult
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortInteriorAudioSphereTraceResult")
	bool bBlocking;

	UPROPERTY(BlueprintReadOnly, Category="FortInteriorAudioSphereTraceResult")
	float Distance;

};

USTRUCT(BlueprintType)
struct FInteriorAudioBuildingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<ABuildingSMActor> Actor;

};

USTRUCT(BlueprintType)
struct FInteriorAudioBuildingRotationConstraint
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioBuildingRotationConstraint")
	EInteriorAudioBuildingDefaultRotation StartingOrientation;

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioBuildingRotationConstraint")
	float XScaleFlipRotation;

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioBuildingRotationConstraint")
	float YScaleFlipRotation;

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioBuildingRotationConstraint", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EInteriorAudioQuadrant"))
	int32 Quadrant;

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioBuildingRotationConstraint", meta=(EditCondition="bUseDotProductComparison", EditConditionHides))
	FVector DotProductComparisons;

};

USTRUCT(BlueprintType)
struct FInteriorAudioDictionaryEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Entry")
	FString EditCode;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Entry")
	FName EditCodeDescription;
#endif

	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioDictionaryEntry", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EInteriorAudioBuildingTags"))
	int32 Tags;

	UPROPERTY(EditDefaultsOnly, Category="Entry|Evaluation")
	EInteriorAudioBuildingEvaluation DefaultEvaluation;

	UPROPERTY(EditDefaultsOnly, Category="Entry|Evaluation", meta=(EditCondition="Tags & EInteriorAudioBuildingTags::UseConditionalEvaluation", EditConditionHides))
	EInteriorAudioBuildingEvaluation ConditionalEvaluation;

	UPROPERTY(EditDefaultsOnly, Category="Entry|Rotation Info", meta=(EditCondition="Tags & EInteriorAudioBuildingTags::RotationDependant", EditConditionHides))
	FInteriorAudioBuildingRotationConstraint RotationConstraint;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="InteriorAudioDictionaryEntry", meta=(ArraySizeEnum="/Script/FortniteGame.EInteriorAudioBuildingRelativePosition"))
	int32 BuildingWeights[5];

};

USTRUCT(BlueprintType)
struct FInteriorAudioDictionary
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="InteriorAudioDictionary", meta=(TitleProperty="EditCodeDescription"))
	TArray<FInteriorAudioDictionaryEntry> Entries;

};

USTRUCT(BlueprintType)
struct FInteriorAudioDirectionScanInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FInteriorAudioBuildingInfo Building;

};

USTRUCT(BlueprintType)
struct FInteriorAudioPlayerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EInteriorAudioBuildingDirection, FInteriorAudioDirectionScanInfo> Directions;

	UPROPERTY()
	TMap<EStructuralWallPosition, TWeakObjectPtr<ABuildingSMActor>> StartingWalls;

	UPROPERTY()
	TWeakObjectPtr<ABuildingSMActor> CenterCellActor;

	UPROPERTY(EditAnywhere, Category="InteriorAudioPlayerInfo", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.EInteriorAudioQuadrant"))
	EInteriorAudioQuadrant Quadrant;

};

USTRUCT(BlueprintType)
struct FInteriorAudioScanDirectionResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	TObjectPtr<ABuildingSMActor> BuildingActor;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	FVector HitLocation;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	bool bLineTraceResult;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	bool bIsPlayerBuilt;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanDirectionResults")
	bool bIsPartialObstruction;

};

USTRUCT(BlueprintType)
struct FInteriorAudioScanResults_BuildingGrid
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 Size;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 SolidBuildingCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 DistantPartialBuildingCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 PartialBuildingCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 PlayerBuiltCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 TotalBuildingCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 LineTraceCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	int32 CeilingCheckCount;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	bool bHasRoof;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	TEnumAsByte<EFortResourceType::Type> DominantResourceType;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_BuildingGrid")
	TMap<EInteriorAudioBuildingDirection, FInteriorAudioScanDirectionResults> DirectionResults;

};

USTRUCT(BlueprintType)
struct FInteriorAudioScanResults_SphereTrace
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_SphereTrace")
	float BlockingHitRatio;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_SphereTrace")
	float AvgTraceDistance;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults_SphereTrace")
	TArray<FFortInteriorAudioSphereTraceResult> TraceResults;

};

USTRUCT(BlueprintType)
struct FInteriorAudioScanResults
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults")
	TObjectPtr<AActor> ViewTarget;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults")
	FTransform ViewTargetTransform;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults")
	FInteriorAudioScanResults_BuildingGrid BuildingGrid;

	UPROPERTY(BlueprintReadOnly, Category="InteriorAudioScanResults")
	FInteriorAudioScanResults_SphereTrace SphereTrace;

};

