// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_NamePlate.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_NamePlate::OnRep_DisplayMode()
{
}

void AFortAthenaMutator_NamePlate::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_NamePlate, DisplayMode);
}
