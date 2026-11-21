// Copyright Epic Games, Inc. All Rights Reserved.

#include "Modifiers/FortGameplayMutator.h"
#include "Net/UnrealNetwork.h"

bool AFortGameplayMutator::IsMutatorActive() const
{
	return false;
}

void AFortGameplayMutator::OnRep_bMutatorActive()
{
}

void AFortGameplayMutator::SetMutatorActive(bool bEnable)
{
}

void AFortGameplayMutator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameplayMutator, bMutatorActive);
}
