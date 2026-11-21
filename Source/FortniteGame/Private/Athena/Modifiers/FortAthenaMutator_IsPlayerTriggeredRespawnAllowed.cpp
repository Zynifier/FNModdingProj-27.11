// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_IsPlayerTriggeredRespawnAllowed.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_IsPlayerTriggeredRespawnAllowed::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_IsPlayerTriggeredRespawnAllowed, bIsPlayerTriggeredRespawnAllowed);
}
