// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/Transient/FortIntelPackSet.h"
#include "Net/UnrealNetwork.h"

void UFortIntelPackSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortIntelPackSet, MaxCharges);
	DOREPLIFETIME(UFortIntelPackSet, CurrentCharges);
	DOREPLIFETIME(UFortIntelPackSet, StormTrackerCost);
	DOREPLIFETIME(UFortIntelPackSet, RevealedTargetsRange);
	DOREPLIFETIME(UFortIntelPackSet, RevealedTargetsDuration);
	DOREPLIFETIME(UFortIntelPackSet, RevealedTargetsCost);
}
