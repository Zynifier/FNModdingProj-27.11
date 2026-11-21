// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortInGameMapManager.h"
#include "Net/UnrealNetwork.h"

void AFortInGameMapManager::AllowShowMainMap(bool bAllowShow)
{
}

void AFortInGameMapManager::AllowShowMiniMap(bool bAllowShow)
{
}

FVector2D AFortInGameMapManager::BPWorldLocationToMapLocation(const FVector& WorldLocation, float InMapSize)
{
	return FVector2D();
}

void AFortInGameMapManager::BroadcastExplorationEvents_Implementation(const TArray<FTeamMapExplorationEvent>& Events)
{
}

AFortInGameMapManager* AFortInGameMapManager::GetCurrent(const UObject* WorldContextObject)
{
	return nullptr;
}

UTexture2D* AFortInGameMapManager::GetHeatmapMask() const
{
	return nullptr;
}

float AFortInGameMapManager::GetHeatmapMaskScale() const
{
	return float();
}

bool AFortInGameMapManager::GetStaticCaptureSetupComplete() const
{
	return false;
}

void AFortInGameMapManager::OnRep_ClearAllFog()
{
}

void AFortInGameMapManager::OnRep_MapData()
{
}

void AFortInGameMapManager::PaintOnFog(const FVector& WorldCoords, EFortTeam::Type Team)
{
}

void AFortInGameMapManager::ResetCaptureLocation()
{
}

void AFortInGameMapManager::ResetCaptureRotation()
{
}

void AFortInGameMapManager::ServerClearAllFog()
{
}

void AFortInGameMapManager::SetActorBoundaryData(float UpperZ, float LowerZ, const TArray<TSoftClassPtr<AActor>>& ClassesToHide)
{
}

void AFortInGameMapManager::SetCaptureLocation(const FVector& Location)
{
}

bool AFortInGameMapManager::ShouldShowMainMap() const
{
	return false;
}

void AFortInGameMapManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortInGameMapManager, MapData);
	DOREPLIFETIME(AFortInGameMapManager, bClearAllFog);
}
