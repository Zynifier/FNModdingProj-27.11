// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationCarryObject.h"
#include "Net/UnrealNetwork.h"

uint8 UInfiltrationCarryObjectComponent::GetAttackingTeam() const
{
	return uint8();
}

uint8 UInfiltrationCarryObjectComponent::GetDefendingTeam() const
{
	return uint8();
}

void UInfiltrationCarryObjectComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UInfiltrationCarryObjectComponent, ParentSpawnPoint);
	DOREPLIFETIME(UInfiltrationCarryObjectComponent, CachedMutator);
	DOREPLIFETIME(UInfiltrationCarryObjectComponent, bIsInteractable);
}
