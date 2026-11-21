// Copyright Epic Games, Inc. All Rights Reserved.

#include "CorruptionCoverageMap.h"

bool UCorruptionCoverageMap::IsLocationCorrupted(const FVector& Location, float Padding) const
{
	return false;
}

bool UCorruptionCoverageMap::UpdateCorruptionCoverageMap(UObject* WorldContextObject, UTextureRenderTarget2D* CorruptionRenderTarget, const FVector& InTopLeftWorldCoordinate, const FVector& InBottomRightWorldCoordinate, float CoverageThreshold, float DebugDrawDuration)
{
	return false;
}
