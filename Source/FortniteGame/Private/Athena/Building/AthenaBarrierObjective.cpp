// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaBarrierObjective.h"
#include "Net/UnrealNetwork.h"

EBarrierFoodTeam AAthenaBarrierObjective::GetFoodTeam() const
{
	return EBarrierFoodTeam();
}

EBarrierObjectiveDamageState AAthenaBarrierObjective::GetObjectiveDamageState() const
{
	return EBarrierObjectiveDamageState();
}

bool AAthenaBarrierObjective::IsFriendlyTeam() const
{
	return false;
}

void AAthenaBarrierObjective::OnGeneratorDestroyed()
{
}

void AAthenaBarrierObjective::OnRep_FoodTeam()
{
}

void AAthenaBarrierObjective::OnRep_HeadRotationYaw()
{
}

void AAthenaBarrierObjective::OnRep_ObjectiveDamageState()
{
}

void AAthenaBarrierObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaBarrierObjective, FoodTeam);
	DOREPLIFETIME(AAthenaBarrierObjective, ObjectiveDamageState);
	DOREPLIFETIME(AAthenaBarrierObjective, HeadRotationYaw);
	DOREPLIFETIME(AAthenaBarrierObjective, bAllowDamage);
}
