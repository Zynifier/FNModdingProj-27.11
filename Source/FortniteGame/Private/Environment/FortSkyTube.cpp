// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortSkyTube.h"

void AFortSkyTube::AddNonSkyTubeMeshComponent(const UMeshComponent* MeshComponent)
{
}

void AFortSkyTube::DeferredEnableOverlaps()
{
}

float AFortSkyTube::GetDelayUntilDisabled() const
{
	return float();
}

bool AFortSkyTube::IsExemptFromShutdown() const
{
	return false;
}

bool AFortSkyTube::IsMeshComponentPartOfSkyTube(const UMeshComponent* MeshComponent) const
{
	return false;
}

bool AFortSkyTube::IsShuttingDown() const
{
	return false;
}

bool AFortSkyTube::IsSkyTubeEnabled() const
{
	return false;
}
