// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_PlayStopPauseManager.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceComponent_PlayStopPauseManager::OnRep_PlayDevices()
{
}

void UPlayspaceComponent_PlayStopPauseManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_PlayStopPauseManager, bPlayDevices);
	DOREPLIFETIME(UPlayspaceComponent_PlayStopPauseManager, ReplicatedPlayPauseStopActors);
}
