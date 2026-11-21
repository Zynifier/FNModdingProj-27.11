// Copyright Epic Games, Inc. All Rights Reserved.

#include "Aircraft/FortAircraft.h"
#include "Net/UnrealNetwork.h"

void AFortAircraft::OnRep_JumpFlashCount()
{
}

void AFortAircraft::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAircraft, JumpFlashCount);
}
