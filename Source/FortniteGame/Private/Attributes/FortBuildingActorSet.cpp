// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/FortBuildingActorSet.h"
#include "Net/UnrealNetwork.h"

void UFortBuildingActorSet::OnRep_BuildTime(const FFortGameplayAttributeData& OldValue)
{
}

void UFortBuildingActorSet::OnRep_RepairTime(const FFortGameplayAttributeData& OldValue)
{
}

void UFortBuildingActorSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBuildingActorSet, BuildTime);
	DOREPLIFETIME(UFortBuildingActorSet, RepairTime);
}
