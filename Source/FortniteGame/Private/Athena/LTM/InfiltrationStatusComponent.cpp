// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationStatusComponent.h"
#include "Net/UnrealNetwork.h"

uint8 UInfiltrationStatusComponent::GetAttackingTeam() const
{
	return uint8();
}

EIntelStateEnum UInfiltrationStatusComponent::GetCurrentIntelState() const
{
	return EIntelStateEnum();
}

uint8 UInfiltrationStatusComponent::GetDefendingTeam() const
{
	return uint8();
}

float UInfiltrationStatusComponent::GetGroundTimeRemaining() const
{
	return float();
}

bool UInfiltrationStatusComponent::GetIsCurrentlyDefended() const
{
	return false;
}

bool UInfiltrationStatusComponent::IsBeingHeldByLocalPlayer(AFortPlayerControllerAthena* LocalPlayer) const
{
	return false;
}

bool UInfiltrationStatusComponent::IsLocalPlayerAttacking(AFortPlayerControllerAthena* LocalPlayer) const
{
	return false;
}

bool UInfiltrationStatusComponent::IsLocalPlayerDefending(AFortPlayerControllerAthena* LocalPlayer) const
{
	return false;
}

void UInfiltrationStatusComponent::OnRep_CachedMutator()
{
}

void UInfiltrationStatusComponent::OnRoundReset()
{
}

void UInfiltrationStatusComponent::TryExecuteMutatorReady()
{
}

void UInfiltrationStatusComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInfiltrationStatusComponent, CachedMutator);
}
