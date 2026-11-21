// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortWaterBodyActor.h"

void AFortWaterBodyActor::GetWaterSurfaceInfo(FVector QueryLocation, FVector& WaterPlaneLocation, FVector& WaterPlaneNormal, FVector& WaterSurfacePosition, float& WaterDepth, int32& WaterBodyIdx, FVector& WaterVelocity, bool bIncludeDepth, bool bIncludeWaves, bool bSimpleWaves) const
{
}

void AFortWaterBodyActor::GetWaterSurfaceInfoStruct(FWaterSurfaceInfo& OutWaterSurfaceInfo, const FVector& QueryLocation, const bool bIncludeDepth, const bool bIncludeWaves, bool bSimpleWaves) const
{
}

void AFortWaterBodyActor::SetSwampLocationAndRadius(const FVector& InPosition, float InRadius)
{
}

void AFortWaterBodyActor::SetWaterBodyType(EWaterBodyType InType)
{
}
