// Copyright Epic Games, Inc. All Rights Reserved.

#include "Missions/FortMissionStormSafeZone.h"
#include "Net/UnrealNetwork.h"

float AFortMissionStormSafeZone::GetConvertedSafeZoneRadius() const
{
	return float();
}

float AFortMissionStormSafeZone::GetSafeZoneRadius() const
{
	return float();
}

void AFortMissionStormSafeZone::OnRep_SafeZoneInStormStateChanged()
{
}

void AFortMissionStormSafeZone::OnRep_ZoneRadius()
{
}

void AFortMissionStormSafeZone::SetSafeZoneRadius(const float InRadius)
{
}

void AFortMissionStormSafeZone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortMissionStormSafeZone, bSafeZoneInStormStateChanged);
	DOREPLIFETIME(AFortMissionStormSafeZone, SafeZoneRadius);
}

UAbilitySystemComponent* AFortMissionStormSafeZone::GetAbilitySystemComponent() const
{
	return nullptr;
}
