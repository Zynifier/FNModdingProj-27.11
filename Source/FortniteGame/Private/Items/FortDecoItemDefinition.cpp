// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortDecoItemDefinition.h"

TSubclassOf<ABuildingActor> UFortDecoItemDefinition::GetBlueprintClass() const
{
	return TSubclassOf<ABuildingActor>();
}

float UFortDecoItemDefinition::GetGridPlacementOffset() const
{
	return float();
}

float UFortDecoItemDefinition::GetGridSnapSizeOverride() const
{
	return float();
}

int32 UFortDecoItemDefinition::GetMaxPlacementDistance() const
{
	return int32();
}

TSubclassOf<AFortDecoPreview> UFortDecoItemDefinition::GetPlacementPreviewClass() const
{
	return TSubclassOf<AFortDecoPreview>();
}

EPlacementType::Type UFortDecoItemDefinition::GetPlacementTypeOverride() const
{
	return EPlacementType::Type();
}

float UFortDecoItemDefinition::GetRotationAngleIncrement() const
{
	return float();
}

bool UFortDecoItemDefinition::RequiresPermissionToEditWorld() const
{
	return false;
}

bool UFortDecoItemDefinition::RequiresPlayerPlaceableAttachmentActors() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldAllowAnyFloorPlacement() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldAllowPlacementOnBuildings() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldAllowPlacementOnWorldGeometry() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldAllowStairsWhenAttachingToFloors() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldAttachWhenPlacing() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldCancelAbilityOnUnequip() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldCancelToolWhenPlaced() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldConsumeWhenPlaced(const AFortPlayerController* PlayerController) const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldDestroySmallObjectsWhenPlaced() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldDisableLocationLerpWhilePlacing() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldDisableRotationLerpWhilePlacing() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldDisableScaleLerpWhilePlacing() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldForceIgnoreBuildingOverlaps() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldForceIgnoreOverlapTest() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldIgnoreCollisionWithCriticalActors() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldIgnoreCollisionWithFortStaticMeshActors() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldIgnoreCollisionWithPlayers() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldIgnoreCollisionWithStructuralGridActors() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldIgnoreCollisionWithVehicles() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldSnapYawToHorizontalAxes() const
{
	return false;
}

bool UFortDecoItemDefinition::ShouldUseRelativeCameraRotation() const
{
	return false;
}
