// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaMapInfo.h"

FAircraftFlightInfo AFortAthenaMapInfo::CalcAircraftFlightPath(AFortGameModeAthena* GameModeAthena, const FAircraftFlightConstructionInfo& FlightConstructionInfo, const FVector2D& PathPoint1, const FVector2D& PathPoint2, const FVector2D& RotationAnchorPoint, const float DropZoneHeight, const FBox2D& SpawnZone, const FBox2D& DropZone, const float AircraftOffsetFromMidLine, const float AngleOffset) const
{
	return FAircraftFlightInfo();
}

FSafeZoneLocationParams AFortAthenaMapInfo::ConstructSafeZoneLocationParams(const int32 SafeZoneIndex, const FVector& CenterLocation, const FVector& NextLocation, const bool bFinalPhase, const int32 BaseSafeZoneIndex) const
{
	return FSafeZoneLocationParams();
}

void AFortAthenaMapInfo::DrawSafeZoneVolumeDefinitions()
{
}

FVector AFortAthenaMapInfo::GetMapCenter() const
{
	return FVector();
}

void AFortAthenaMapInfo::HandleStormEffectsPlayerOptionEnabledChanged(bool bInEnabled)
{
}

FVector AFortAthenaMapInfo::PickSafeZoneLocation(const FSafeZoneLocationParams& Params, const TArray<FVector4>& BlacklistLocations) const
{
	return FVector();
}

FVector AFortAthenaMapInfo::PickSupplyDropLocation(const FVector& CenterLocation, const float MaxRadius, const bool bAvoidWater, const float TraceStartZ, const float TraceEndZ, const bool bAvoidUnwalkableTerrain) const
{
	return FVector();
}

void AFortAthenaMapInfo::SetAircraftSpeed(const FScalableFloat& InAircraftSpeed)
{
}
