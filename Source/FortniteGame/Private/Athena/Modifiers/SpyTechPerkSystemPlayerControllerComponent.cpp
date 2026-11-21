// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/SpyTechPerkSystemPlayerControllerComponent.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_SpyTechPerkSystem::OnRep_AllSelectedPerks()
{
}

void UFortControllerComponent_SpyTechPerkSystem::OnRep_MutatorData()
{
}

void UFortControllerComponent_SpyTechPerkSystem::OnRep_PerkSelection()
{
}

void UFortControllerComponent_SpyTechPerkSystem::OnRep_RerollCount()
{
}

void UFortControllerComponent_SpyTechPerkSystem::OnRep_ServerTimeToRelease()
{
}

void UFortControllerComponent_SpyTechPerkSystem::OnRep_SpyTechArray()
{
}

void UFortControllerComponent_SpyTechPerkSystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, ServerTimeToRelease);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, RerollCount);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, AllSelectedPerks);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, PerkSelection);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, SpyTechArray);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, MutatorData);
	DOREPLIFETIME(UFortControllerComponent_SpyTechPerkSystem, CachedFactionTag);
}
