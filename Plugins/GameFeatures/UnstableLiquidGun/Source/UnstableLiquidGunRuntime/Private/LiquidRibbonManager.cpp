// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiquidRibbonManager.h"

float ALiquidRibbonManager::CalculatePointFlashIntensity(const int32 PointSize) const
{
	return float();
}

float ALiquidRibbonManager::CalculatePointSize(int32 SegmentIndex, int32 PointIndex) const
{
	return float();
}

TArray<FLiquidRibbonSplineSegment> ALiquidRibbonManager::CalculateSegments(const TArray<FVector>& Points, const float Tension)
{
	return TArray<FLiquidRibbonSplineSegment>();
}

void ALiquidRibbonManager::CalculateSplinePointsAndSetNiagaraData(const TArray<AFortLiquidGunProjectile*>& Projectiles, bool bAttachSplineToMuzzle, UNiagaraComponent* NiagaraComponent, TArray<FVector>& OutAllPositions, TArray<int32>& OutRibbonIDs, TArray<bool>& OutRibbonVisibilities, TArray<float>& OutFlashIntensities, TArray<int32>& OutRibbonSizes)
{
}

int32 ALiquidRibbonManager::GetFirstVisiblePointIndex_Implementation() const
{
	return int32();
}

const FLiquidRibbonSplineDetachment& ALiquidRibbonManager::GetOrAddDetachment(const int32 RibbonID, const FLiquidRibbonSplineSegment& Segment)
{
	static FLiquidRibbonSplineDetachment Dummy;
	return Dummy;
}

FVector ALiquidRibbonManager::GetPointOnSegment(float T, const FLiquidRibbonSplineSegment& Segment) const
{
	return FVector();
}

void ALiquidRibbonManager::RunSplineCollisionTestOnProjectiles()
{
}

void ALiquidRibbonManager::SetNiagaraData(UNiagaraComponent* NiagaraComponent, const TArray<FVector>& Positions, const TArray<int32>& RibbonIDs, const TArray<bool>& RibbonVisibilities, const TArray<float>& FlashIntensities, const TArray<int32>& RibbonSizes) const
{
}
