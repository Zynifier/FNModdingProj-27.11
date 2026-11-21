// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortHotfixBlockingVolume.h"
#include "Net/UnrealNetwork.h"

void AFortHotfixBlockingVolume::CopyToClipboard()
{
}

void AFortHotfixBlockingVolume::OnRep_ReplicatedExtent()
{
}

void AFortHotfixBlockingVolume::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortHotfixBlockingVolume, ReplicatedExtent);
}
