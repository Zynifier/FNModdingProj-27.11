// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspaces/Components/PlayspaceComponent_CreativeToolsPermission.h"
#include "Net/UnrealNetwork.h"

bool UPlayspaceComponent_CreativeToolsPermission::DoesPlayerHavePermissionToEdit(const FUniqueNetIdRepl& UserRequestingPermission) const
{
	return false;
}

void UPlayspaceComponent_CreativeToolsPermission::OnRep_PlotPermissionsChanged()
{
}

void UPlayspaceComponent_CreativeToolsPermission::OnVolumeStateChanged(FEventMessageTag Channel, const FSpatialGamePlayActorLoadingStateUpdatedContext& StateContext)
{
}

void UPlayspaceComponent_CreativeToolsPermission::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_CreativeToolsPermission, AccountIdOfOwner);
	DOREPLIFETIME(UPlayspaceComponent_CreativeToolsPermission, PlotPermissions);
}
