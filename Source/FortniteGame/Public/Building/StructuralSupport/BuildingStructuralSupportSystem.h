// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Building/BuildingTypes.h"
#include "Building/EditMode/BuildingEditModeMetadata_Floor.h"
#include "BuildingStructuralSupportSystem.generated.h"

class ABuildingActor;
class ABuildingLayoutRequirement;
class ABuildingSMActor;
class AController;
class AFortNavigationGraph;
class UObject;
enum class EFortBuildPreviewMarkerOptionalAdjustment : uint8;
enum class EStructuralFloorPosition : uint8;
enum class EStructuralWallPosition : uint8;

UENUM(BlueprintType)
enum class EStructuralFloorPosition : uint8
{
	Top = 0,
	// Top of the grid cell

	Bottom = 1,
};

UENUM(BlueprintType)
enum class EStructuralWallPosition : uint8
{
	Left = 0,
	// Left side of the grid cell

	Right = 1,
	// Right side of the grid cell

	Front = 2,
	// Front of the grid cell

	Back = 3,
};

USTRUCT(BlueprintType)
struct FBuildingGridActorFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Actor Filter")
	bool bIncludeWalls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Actor Filter")
	bool bIncludeFloors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Actor Filter", meta=(EditCondition="bIncludeFloors", EditConditionHides))
	TArray<EFloorPatternType> FloorPatternsToIgnore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Actor Filter", meta=(EditCondition="bIncludeFloors", EditConditionHides))
	bool bIncludeFloorInTop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Grid Actor Filter")
	bool bIncludeCenterCell;

};

USTRUCT(BlueprintType)
struct FBuildingNavigationCellInfo
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FBuildingSupportCellIndex
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cell Index")
	int32 X;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cell Index")
	int32 Y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Cell Index")
	int32 Z;

};

USTRUCT(BlueprintType)
struct FNeighboringCenterCellInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringCenterCellInfo")
	TWeakObjectPtr<ABuildingSMActor> NeighboringActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringCenterCellInfo")
	FBuildingSupportCellIndex NeighboringCellIdx;

};

USTRUCT(BlueprintType)
struct FNeighboringFloorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringFloorInfo")
	TWeakObjectPtr<ABuildingSMActor> NeighboringActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringFloorInfo")
	FBuildingSupportCellIndex NeighboringCellIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringFloorInfo")
	EStructuralFloorPosition FloorPosition;

};

USTRUCT(BlueprintType)
struct FNeighboringWallInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringWallInfo")
	TWeakObjectPtr<ABuildingSMActor> NeighboringActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringWallInfo")
	FBuildingSupportCellIndex NeighboringCellIdx;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="NeighboringWallInfo")
	EStructuralWallPosition WallPosition;

};

USTRUCT(BlueprintType)
struct FBuildingNeighboringActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingNeighboringActorInfo")
	TArray<FNeighboringWallInfo> NeighboringWallInfos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingNeighboringActorInfo")
	TArray<FNeighboringFloorInfo> NeighboringFloorInfos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingNeighboringActorInfo")
	TArray<FNeighboringCenterCellInfo> NeighboringCenterCellInfos;

};

USTRUCT(BlueprintType)
struct FBuildingValueRules
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 CellsAbove;

	UPROPERTY()
	int32 CellsBelow;

	UPROPERTY()
	int32 CellHorizontalRadius;

	UPROPERTY()
	float DistanceFromObjectiveWeight;

	UPROPERTY()
	float AttackWeight;

	UPROPERTY()
	float StructuralWeight;

	UPROPERTY()
	float TrapWeight;

};

USTRUCT(BlueprintType)
struct FLogicalBuilding
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI)
class UBuildingStructuralSupportSystem : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Building")
	bool AreGridIndicesValid(const FBuildingSupportCellIndex& GridIndices) const;

	UFUNCTION(BlueprintPure, Category="Building")
	bool AreNeighboringBuildingActorsConnected(const ABuildingSMActor* NeighborOne, const ABuildingSMActor* NeighborTwo) const;

	UFUNCTION(BlueprintPure, Category="Building")
	EFortStructuralGridQueryResults::Type CanAddBuildingActorClassToGrid(UObject* WorldContextObject, UClass* BuildingSMActorClassToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const;

	UFUNCTION(BlueprintPure, Category="Building")
	ABuildingSMActor* GetCenterCellActor(const FBuildingSupportCellIndex& GridIndices) const;

	UFUNCTION(BlueprintPure, Category="Building")
	FBox GetGridBox(const FBuildingSupportCellIndex& CellIndex) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void GetLogicalBuildingGroundSupportedActors(int32 LogicalIndex, TArray<ABuildingSMActor*>& LogicalBuildingGroundSupportedActors);

	UFUNCTION(BlueprintPure, Category="Building")
	ABuildingSMActor* GetWallActor(const FBuildingSupportCellIndex& GridIndices, EStructuralWallPosition WallPosition) const;

	UFUNCTION(BlueprintPure, Category="Building")
	bool IsBuildingActorStructurallySupported(const ABuildingSMActor* ActorToCheck) const;

	UFUNCTION(BlueprintPure, Category="Building")
	bool IsWorldLocValid(const FVector& WorldLoc) const;

	UFUNCTION(BlueprintPure, Category="Building")
	EFortStructuralGridQueryResults::Type K2_CanAddBuildingActorToGrid(UObject* WorldContextObject, const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const;

	UFUNCTION(BlueprintCallable, Category="Building")
	bool K2_GetBuildingActorsInGridCell(const FVector& WorldLocation, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell);

	UFUNCTION(BlueprintCallable, Category="Building")
	bool K2_GetBuildingActorsInGridCells(const TArray<FBuildingSupportCellIndex>& CellIndices, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell);

	UFUNCTION(BlueprintPure, Category="Building")
	FBox K2_GetGridBoxFromWorldLoc(const FVector& WorldLocation) const;

	UFUNCTION(BlueprintCallable, Category="Building")
	bool K2_GetGridIndicesFromWorldLoc(const FVector& WorldLoc, FBuildingSupportCellIndex& OutGridIndices);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Building")
	void K2_GetLogicalBuildingActors(int32 LogicalIdx, TArray<ABuildingSMActor*>& LogicalBuildingActors);

	UFUNCTION(BlueprintPure, Category="Building")
	void K2_GetNeighboringBuildingActors(EFortBuildingType::Type BuildingType, const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;

	UFUNCTION(BlueprintPure, Category="Building")
	bool K2_GetWorldLocFromGridIndices(const FBuildingSupportCellIndex& GridIndices, FVector& OutWorldLoc) const;

	UFUNCTION(BlueprintCallable, Category="Building")
	void StartActorRemovalBatch();

	UFUNCTION(BlueprintCallable, Category="Building")
	void StopActorRemovalBatch();

	UFUNCTION(BlueprintPure, Category="Building")
	bool WouldBuildingBeStructurallySupportedByNeighbors(const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored) const;

protected:
	UPROPERTY(Transient)
	TObjectPtr<AFortNavigationGraph> NavGraph;

private:
	UFUNCTION(BlueprintPure, Category="Building")
	bool AreNeighborsConnected(const ABuildingSMActor* NeighborOne, const FVector& NeighborOneLoc, const FRotator& NeighborOneRot, bool bNeighborOneMirrored, const ABuildingSMActor* NeighborTwo, const FVector& NeighborTwoLoc, const FRotator& NeighborTwoRot, bool bNeighborTwoMirrored) const;

	UFUNCTION(BlueprintCallable, Category="Building")
	static bool IsBuildingActorValid(const ABuildingSMActor* ActorToTest);

	UFUNCTION(BlueprintPure, Category="Building")
	EFortStructuralGridQueryResults::Type K2_CanAddCenterCellActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type CenterCellType, int32& OutHorizontalGridIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbStructurallySupported, bool bAllowStaticOverlap = false, bool bPerformCollisionChecks = true) const;

	UFUNCTION(BlueprintPure, Category="Building")
	EFortStructuralGridQueryResults::Type K2_CanAddFloorActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type FloorType, EStructuralFloorPosition& OutFloorPosition, int32& OutFloorIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap = false, bool bPerformCollisionChecks = true) const;

	UFUNCTION(BlueprintPure, Category="Building")
	EFortStructuralGridQueryResults::Type K2_CanAddWallActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type WallType, EStructuralWallPosition& OutWallPosition, int32& OutWallIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap = false, bool bPerformCollisionChecks = true) const;

	UFUNCTION(BlueprintPure, Category="Building")
	void K2_GetNeighboringActorsForCenterCellActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;

	UFUNCTION(BlueprintPure, Category="Building")
	void K2_GetNeighboringActorsForWallActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const;

	UPROPERTY()
	TWeakObjectPtr<AController> BatchedRemovalInstigator;

	UPROPERTY(Transient)
	TArray<TObjectPtr<ABuildingLayoutRequirement>> LayoutRequirementActorsToRegister;

};

