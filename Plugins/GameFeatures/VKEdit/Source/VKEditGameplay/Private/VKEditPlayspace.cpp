// Copyright Epic Games, Inc. All Rights Reserved.

#include "VKEditPlayspace.h"
#include "Net/UnrealNetwork.h"

void AVKEditPlayspace::OnClientActivatedContent(const FUniqueNetIdRepl& ClientNetId) const
{
}

void UPlayspaceComponent_EditConnectionManager::OnRep_EditConnections() const
{
}

void UPlayspaceComponent_EditConnectionManager::OnRep_VkEditStatus() const
{
}

void UPlayspaceComponent_EditConnectionManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPlayspaceComponent_EditConnectionManager, EditConnections);
	DOREPLIFETIME(UPlayspaceComponent_EditConnectionManager, VkEditStatus);
}
