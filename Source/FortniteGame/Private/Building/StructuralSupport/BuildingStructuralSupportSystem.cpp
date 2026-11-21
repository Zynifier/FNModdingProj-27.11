// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/StructuralSupport/BuildingStructuralSupportSystem.h"

bool UBuildingStructuralSupportSystem::AreGridIndicesValid(const FBuildingSupportCellIndex& GridIndices) const
{
	return false;
}

bool UBuildingStructuralSupportSystem::AreNeighboringBuildingActorsConnected(const ABuildingSMActor* NeighborOne, const ABuildingSMActor* NeighborTwo) const
{
	return false;
}

bool UBuildingStructuralSupportSystem::AreNeighborsConnected(const ABuildingSMActor* NeighborOne, const FVector& NeighborOneLoc, const FRotator& NeighborOneRot, bool bNeighborOneMirrored, const ABuildingSMActor* NeighborTwo, const FVector& NeighborTwoLoc, const FRotator& NeighborTwoRot, bool bNeighborTwoMirrored) const
{
	return false;
}

EFortStructuralGridQueryResults::Type UBuildingStructuralSupportSystem::CanAddBuildingActorClassToGrid(UObject* WorldContextObject, UClass* BuildingSMActorClassToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const
{
	return EFortStructuralGridQueryResults::Type();
}

ABuildingSMActor* UBuildingStructuralSupportSystem::GetCenterCellActor(const FBuildingSupportCellIndex& GridIndices) const
{
	return nullptr;
}

FBox UBuildingStructuralSupportSystem::GetGridBox(const FBuildingSupportCellIndex& CellIndex) const
{
	return FBox();
}

void UBuildingStructuralSupportSystem::GetLogicalBuildingGroundSupportedActors(int32 LogicalIndex, TArray<ABuildingSMActor*>& LogicalBuildingGroundSupportedActors)
{
}

ABuildingSMActor* UBuildingStructuralSupportSystem::GetWallActor(const FBuildingSupportCellIndex& GridIndices, EStructuralWallPosition WallPosition) const
{
	return nullptr;
}

bool UBuildingStructuralSupportSystem::IsBuildingActorStructurallySupported(const ABuildingSMActor* ActorToCheck) const
{
	return false;
}

bool UBuildingStructuralSupportSystem::IsBuildingActorValid(const ABuildingSMActor* ActorToTest)
{
	return false;
}

bool UBuildingStructuralSupportSystem::IsWorldLocValid(const FVector& WorldLoc) const
{
	return false;
}

EFortStructuralGridQueryResults::Type UBuildingStructuralSupportSystem::K2_CanAddBuildingActorToGrid(UObject* WorldContextObject, const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored, TArray<ABuildingActor*>& ExistingBuildings, EFortBuildPreviewMarkerOptionalAdjustment& MarkerOptionalAdjustment, bool bAllowStaticOverlap) const
{
	return EFortStructuralGridQueryResults::Type();
}

EFortStructuralGridQueryResults::Type UBuildingStructuralSupportSystem::K2_CanAddCenterCellActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type CenterCellType, int32& OutHorizontalGridIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbStructurallySupported, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const
{
	return EFortStructuralGridQueryResults::Type();
}

EFortStructuralGridQueryResults::Type UBuildingStructuralSupportSystem::K2_CanAddFloorActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type FloorType, EStructuralFloorPosition& OutFloorPosition, int32& OutFloorIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const
{
	return EFortStructuralGridQueryResults::Type();
}

EFortStructuralGridQueryResults::Type UBuildingStructuralSupportSystem::K2_CanAddWallActorToGrid(const FVector& WorldLocation, const FBuildingSupportCellIndex& GridIndices, EFortBuildingType::Type WallType, EStructuralWallPosition& OutWallPosition, int32& OutWallIdx, TArray<ABuildingActor*>& OutExistingBuildings, bool& OutbSupportedByWorld, bool bAllowStaticOverlap, bool bPerformCollisionChecks) const
{
	return EFortStructuralGridQueryResults::Type();
}

bool UBuildingStructuralSupportSystem::K2_GetBuildingActorsInGridCell(const FVector& WorldLocation, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell)
{
	return false;
}

bool UBuildingStructuralSupportSystem::K2_GetBuildingActorsInGridCells(const TArray<FBuildingSupportCellIndex>& CellIndices, const FBuildingGridActorFilter& Filter, FBuildingNeighboringActorInfo& OutActorsInGridCell)
{
	return false;
}

FBox UBuildingStructuralSupportSystem::K2_GetGridBoxFromWorldLoc(const FVector& WorldLocation) const
{
	return FBox();
}

bool UBuildingStructuralSupportSystem::K2_GetGridIndicesFromWorldLoc(const FVector& WorldLoc, FBuildingSupportCellIndex& OutGridIndices)
{
	return false;
}

void UBuildingStructuralSupportSystem::K2_GetLogicalBuildingActors(int32 LogicalIdx, TArray<ABuildingSMActor*>& LogicalBuildingActors)
{
}

void UBuildingStructuralSupportSystem::K2_GetNeighboringActorsForCenterCellActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const
{
}

void UBuildingStructuralSupportSystem::K2_GetNeighboringActorsForWallActor(const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const
{
}

void UBuildingStructuralSupportSystem::K2_GetNeighboringBuildingActors(EFortBuildingType::Type BuildingType, const FVector& WorldLocation, FBuildingSupportCellIndex& OutActorGridIndices, FBuildingNeighboringActorInfo& OutNeighboringActors) const
{
}

bool UBuildingStructuralSupportSystem::K2_GetWorldLocFromGridIndices(const FBuildingSupportCellIndex& GridIndices, FVector& OutWorldLoc) const
{
	return false;
}

void UBuildingStructuralSupportSystem::StartActorRemovalBatch()
{
}

void UBuildingStructuralSupportSystem::StopActorRemovalBatch()
{
}

bool UBuildingStructuralSupportSystem::WouldBuildingBeStructurallySupportedByNeighbors(const ABuildingSMActor* ActorToCheck, const FVector& Location, const FRotator& Rotation, bool bMirrored) const
{
	return false;
}
