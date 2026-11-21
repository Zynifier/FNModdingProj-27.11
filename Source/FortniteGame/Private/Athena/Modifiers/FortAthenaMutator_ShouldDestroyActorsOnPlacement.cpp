// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_ShouldDestroyActorsOnPlacement.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_ShouldDestroyActorsOnPlacement::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_ShouldDestroyActorsOnPlacement, bShouldDestroyOnPlacement);
}
