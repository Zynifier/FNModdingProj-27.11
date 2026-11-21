// Copyright Epic Games, Inc. All Rights Reserved.

#include "CreativeRoyaleRootPlayspace.h"
#include "Net/UnrealNetwork.h"

bool ACreativeRoyaleRootPlayspace::BuildDataRegistryResolverScope_Implementation(TArray<FName>& InOutResolverScopes, int32& InOutPriority) const
{
	return false;
}

void ACreativeRoyaleRootPlayspace::Cheat_LoadEditorIsland()
{
}

void ACreativeRoyaleRootPlayspace::OnPlotLoadComplete()
{
}

void ACreativeRoyaleRootPlayspace::OnRep_bHasPlotLoaded()
{
}

void ACreativeRoyaleRootPlayspace::TeleportPlayersToPlayerStarts()
{
}

void ACreativeRoyaleRootPlayspace::TeleportPlayerToPlayerStart(const FPlayspaceUser& AddedUser)
{
}

void ACreativeRoyaleRootPlayspace::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACreativeRoyaleRootPlayspace, bHasPlotLoaded);
}
