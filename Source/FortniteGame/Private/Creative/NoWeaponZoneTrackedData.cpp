// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/NoWeaponZoneTrackedData.h"

void UNoWeaponZoneTrackedData::AddTrackedDestroy()
{
}

int32 UNoWeaponZoneTrackedData::GetDestroyCount() const
{
	return int32();
}

int32 UNoWeaponZoneTrackedData::GetMaxDestroyCount() const
{
	return int32();
}

int32 UNoWeaponZoneTrackedData::GetMaxDestroyCountPerTrackedDevice() const
{
	return int32();
}

bool UNoWeaponZoneTrackedData::IsTrackedDestroyAtLimit() const
{
	return false;
}

void UNoWeaponZoneTrackedData::OnMinigameEnded()
{
}

void UNoWeaponZoneTrackedData::OnMinigameStarted()
{
}

void UNoWeaponZoneTrackedData::SetupMinigame(AFortMinigame* InMinigame)
{
}

void UNoWeaponZoneTrackedData::StartResetDestroyCountTimer()
{
}

void UNoWeaponZoneTrackedData::TrackNewDevice()
{
}

void UNoWeaponZoneTrackedData::UntrackDevice()
{
}
