// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortOstrichSet.h"
#include "Net/UnrealNetwork.h"

void UFortOstrichSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortOstrichSet, WalkSpeed);
	DOREPLIFETIME(UFortOstrichSet, SprintSpeed);
}
