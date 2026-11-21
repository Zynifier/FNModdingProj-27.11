// Copyright Epic Games, Inc. All Rights Reserved.

#include "Playspace.h"
#include "Net/UnrealNetwork.h"

void APlayspace::OnRep_bIsInitialized()
{
}

void APlayspace::OnRep_bMatchHasEnded()
{
}

void APlayspace::OnRep_MatchStartTime()
{
}

void APlayspace::OnRep_PlayspaceUsers()
{
}

void APlayspace::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayspace, PlayspaceUsers);
	DOREPLIFETIME(APlayspace, ChildPlayspaces);
	DOREPLIFETIME(APlayspace, BoundGameplayVolume);
	DOREPLIFETIME(APlayspace, bIsInitialized);
	DOREPLIFETIME(APlayspace, bMatchHasEnded);
	DOREPLIFETIME(APlayspace, MatchStartTime);
}
