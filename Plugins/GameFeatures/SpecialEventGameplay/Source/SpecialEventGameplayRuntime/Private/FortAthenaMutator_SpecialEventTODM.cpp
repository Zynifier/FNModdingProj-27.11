// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_SpecialEventTODM.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_SpecialEventTODM::OnPhaseActivated(ASpecialEventScript* InSpecialEventScript, ASpecialEventPhase* InSpecialEventPhase)
{
}

void AFortAthenaMutator_SpecialEventTODM::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_SpecialEventTODM, PhaseIndexInProgress);
	DOREPLIFETIME(AFortAthenaMutator_SpecialEventTODM, SubphaseIndexInProgress);
	DOREPLIFETIME(AFortAthenaMutator_SpecialEventTODM, SpawnedTODM);
	DOREPLIFETIME(AFortAthenaMutator_SpecialEventTODM, bDebug);
}

void UFortCheatManager_SpecialEventTODM::SpecialEventTODM_ToggleDebug()
{
}
