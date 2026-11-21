// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlayspaceLogic.h"
#include "Net/UnrealNetwork.h"

void APlayspaceLogic::OnRep_bMatchHasEnded()
{
}

void APlayspaceLogic::OnRep_MatchStartTime()
{
}

void APlayspaceLogic::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(APlayspaceLogic, bMatchHasEnded);
	DOREPLIFETIME(APlayspaceLogic, MatchStartTime);
}
