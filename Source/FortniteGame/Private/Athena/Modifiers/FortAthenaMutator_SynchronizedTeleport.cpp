// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_SynchronizedTeleport.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_SynchronizedTeleport::OnRep_TeleportComplete()
{
}

void AFortAthenaMutator_SynchronizedTeleport::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_SynchronizedTeleport, InProgressTeleportPlayerIDs);
	DOREPLIFETIME(AFortAthenaMutator_SynchronizedTeleport, bTeleportComplete);
}
