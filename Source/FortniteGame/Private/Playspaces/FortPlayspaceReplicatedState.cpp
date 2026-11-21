// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/FortPlayspaceReplicatedState.h"

UActorComponent_ReplicatedParamHelper* AFortPlayspaceReplicatedState::GetReplicatedParamHelper() const
{
	return nullptr;
}

bool AFortPlayspaceReplicatedState::IsLocalPlayerInOwningPlayspace(int32 PlayerIndex) const
{
	return false;
}
