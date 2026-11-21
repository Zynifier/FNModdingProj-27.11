// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Navigation/AthenaNavPresenceDetectorComponent.h"

bool UAthenaNavPresenceDetectorComponent::HasValidNavMeshLocation() const
{
	return false;
}

void UAthenaNavPresenceDetectorComponent::OnNavMeshTilesUpdated(const FUpdatedNavMeshTiles& UpdatedNavMeshTiles)
{
}
