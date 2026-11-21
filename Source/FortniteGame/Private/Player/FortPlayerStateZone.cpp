// Copyright Epic Games, Inc. All Rights Reserved.

#include "Player/FortPlayerStateZone.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerStateZone::GetHealthAndShields(float& Health, float& HealthMax, float& Shield, float& ShieldMax)
{
}

int32 AFortPlayerStateZone::GetNumOfAccumulatedBluGlo() const
{
	return int32();
}

int32 AFortPlayerStateZone::GetNumOfAccumulatedItem(const UFortWorldItemDefinition* ItemDefinition) const
{
	return int32();
}

void AFortPlayerStateZone::GetOvershields(float& Overshield, float& OvershieldMax)
{
}

FString AFortPlayerStateZone::GetPlayerNameForStreaming() const
{
	return FString();
}

float AFortPlayerStateZone::GetSimulatedAttributeValue(const FGameplayAttribute& Attribute, const float DefaultValue) const
{
	return float();
}

int32 AFortPlayerStateZone::GetSpectatorCount()
{
	return int32();
}

bool AFortPlayerStateZone::HasEverSkydivedFromBus() const
{
	return false;
}

bool AFortPlayerStateZone::HasEverSkydivedFromBusAndLanded() const
{
	return false;
}

bool AFortPlayerStateZone::IsPlayerDead() const
{
	return false;
}

void AFortPlayerStateZone::MulticastTriggerOnGadgetTrackedAttributeDestroyedFX_Implementation(const UFortGadgetItemDefinition* GadgetItemDefinition)
{
}

void AFortPlayerStateZone::OnRep_AccumulatedItems()
{
}

void AFortPlayerStateZone::OnRep_HasEverSkydivedFromBusAndLanded()
{
}

void AFortPlayerStateZone::OnRep_NumRejoins()
{
}

void AFortPlayerStateZone::OnRep_OvershieldBarVisisble()
{
}

void AFortPlayerStateZone::OnRep_QuickbarEquippedItems()
{
}

void AFortPlayerStateZone::OnRep_SpectatingTarget()
{
}

void AFortPlayerStateZone::ServerSetInAircraft_Implementation(bool bNewInAircraft)
{
}

void AFortPlayerStateZone::SetOvershieldBarVisible_Implementation(bool NewVisible)
{
}

bool AFortPlayerStateZone::ShouldOvershieldBarBeVisible() const
{
	return false;
}

void AFortPlayerStateZone::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerStateZone, SpectatingTarget);
	DOREPLIFETIME(AFortPlayerStateZone, Spectators);
	DOREPLIFETIME(AFortPlayerStateZone, KickedFromSessionReason);
	DOREPLIFETIME(AFortPlayerStateZone, CarriedObject);
	DOREPLIFETIME(AFortPlayerStateZone, NumRejoins);
	DOREPLIFETIME(AFortPlayerStateZone, bInvincibleDueToUI);
	DOREPLIFETIME(AFortPlayerStateZone, CurrentHealth);
	DOREPLIFETIME(AFortPlayerStateZone, MaxHealth);
	DOREPLIFETIME(AFortPlayerStateZone, CurrentShield);
	DOREPLIFETIME(AFortPlayerStateZone, MaxShield);
	DOREPLIFETIME(AFortPlayerStateZone, CurrentOvershield);
	DOREPLIFETIME(AFortPlayerStateZone, MaxOvershield);
	DOREPLIFETIME(AFortPlayerStateZone, CurrentSignalInStorm);
	DOREPLIFETIME(AFortPlayerStateZone, MaxSignalInStorm);
	DOREPLIFETIME(AFortPlayerStateZone, bOvershieldBarVisible);
	DOREPLIFETIME(AFortPlayerStateZone, AccumulatedItems);
	DOREPLIFETIME(AFortPlayerStateZone, SimulatedAttributes);
	DOREPLIFETIME(AFortPlayerStateZone, bInAircraft);
	DOREPLIFETIME(AFortPlayerStateZone, bHasEverSkydivedFromBus);
	DOREPLIFETIME(AFortPlayerStateZone, bHasEverSkydivedFromBusAndLanded);
	DOREPLIFETIME(AFortPlayerStateZone, QuickbarEquippedItems);
}
