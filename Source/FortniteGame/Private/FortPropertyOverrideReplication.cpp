// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPropertyOverrideReplication.h"
#include "Net/UnrealNetwork.h"

void AFortPropertyOverrideReplShared::OnRep_ReplOverrides()
{
}

void AFortPropertyOverrideReplShared::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPropertyOverrideReplShared, ReplOverrides);
}

void APropertyOverrideDataReplChunkActor::OnRep_ChunkIndex()
{
}

void APropertyOverrideDataReplChunkActor::OnRep_PartialReplOverrides()
{
}

void APropertyOverrideDataReplChunkActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APropertyOverrideDataReplChunkActor, ChunkIndex);
	DOREPLIFETIME(APropertyOverrideDataReplChunkActor, PartialReplOverrides);
}
