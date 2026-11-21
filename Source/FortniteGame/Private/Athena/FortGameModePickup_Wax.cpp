// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortGameModePickup_Wax.h"
#include "Net/UnrealNetwork.h"

void AFortGameModePickup_Wax::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortGameModePickup_Wax, bIsFirstGeneration);
	DOREPLIFETIME(AFortGameModePickup_Wax, AmountOfTokens);
}
