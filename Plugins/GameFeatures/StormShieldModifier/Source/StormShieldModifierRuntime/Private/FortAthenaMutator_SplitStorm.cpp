// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_SplitStorm.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_SplitStorm::OnRep_CurrentProxyCircle()
{
}

void AFortAthenaMutator_SplitStorm::OnSafeZoneIndicatorSpawned(const FFortSafeZoneIndicatorUpdatedEvent& Event)
{
}

void AFortAthenaMutator_SplitStorm::OnSafeZonePhaseChanged()
{
}

void AFortAthenaMutator_SplitStorm::SetProxyCenter_Implementation(const FVector NewCenter)
{
}

void AFortAthenaMutator_SplitStorm::SetProxyRadius_Implementation(const float NewRadius)
{
}

void AFortAthenaMutator_SplitStorm::SetSafeZoneProxyPhase(ESplitStormProxyPhase NewPhase)
{
}

void AFortAthenaMutator_SplitStorm::StartProxyUpdateTimer()
{
}

void AFortAthenaMutator_SplitStorm::UpdateProxyCenterAndRadius()
{
}

void AFortAthenaMutator_SplitStorm::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_SplitStorm, SafeZoneProxy);
	DOREPLIFETIME(AFortAthenaMutator_SplitStorm, CurrentProxyPhase);
	DOREPLIFETIME(AFortAthenaMutator_SplitStorm, ProxyHoldCircle);
	DOREPLIFETIME(AFortAthenaMutator_SplitStorm, CurrentProxyCircle);
}
