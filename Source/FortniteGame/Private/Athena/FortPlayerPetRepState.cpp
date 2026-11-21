// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerPetRepState.h"
#include "Net/UnrealNetwork.h"

AFortPlayerPawn* AFortPlayerPetRepState::GetFortPlayerPawn() const
{
	return nullptr;
}

void AFortPlayerPetRepState::OnRep_LookAtTarget()
{
}

void AFortPlayerPetRepState::OnRep_PetItemDef()
{
}

void AFortPlayerPetRepState::OnRep_StimuliTag()
{
}

void AFortPlayerPetRepState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerPetRepState, LookAtTarget);
	DOREPLIFETIME(AFortPlayerPetRepState, PetItemDef);
	DOREPLIFETIME(AFortPlayerPetRepState, StimuliTag);
}
