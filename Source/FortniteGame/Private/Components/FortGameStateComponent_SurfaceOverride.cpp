// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_SurfaceOverride.h"

EPhysicalSurface UFortGameStateComponent_SurfaceOverride::GetSpecialSurfaceType() const
{
	return EPhysicalSurface();
}

bool UFortGameStateComponent_SurfaceOverride::IsLocationInSpecialSurface(const FVector& Location, const float Padding) const
{
	return false;
}
