// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_CreativeLoadingStateProxy.h"
#include "Net/UnrealNetwork.h"

void UPlayspaceComponent_CreativeLoadingStateProxy::OnRep_CurrentLockedLoadingState()
{
}

void UPlayspaceComponent_CreativeLoadingStateProxy::OnRep_SpatialLoadingState()
{
}

void UPlayspaceComponent_CreativeLoadingStateProxy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_CreativeLoadingStateProxy, SpatialLoadingState);
	DOREPLIFETIME(UPlayspaceComponent_CreativeLoadingStateProxy, CurrentLockedLoadingState);
	DOREPLIFETIME(UPlayspaceComponent_CreativeLoadingStateProxy, bNeverAllowSaving);
}
