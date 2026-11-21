// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_EditModeHUDElements.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_EditModeHUDElements::HandleMutatorSettingsChanged(const FPropertyOverrideData& OverrideData)
{
}

void AFortAthenaMutator_EditModeHUDElements::OnRep_PendingNotify()
{
}

void AFortAthenaMutator_EditModeHUDElements::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_EditModeHUDElements, bPendingNotify);
}
