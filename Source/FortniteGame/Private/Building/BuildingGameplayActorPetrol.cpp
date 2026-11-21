// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorPetrol.h"
#include "Net/UnrealNetwork.h"

float ABuildingGameplayActorPetrol::GetCurrentSize() const
{
	return float();
}

int32 ABuildingGameplayActorPetrol::GetProjectileCount() const
{
	return int32();
}

float ABuildingGameplayActorPetrol::GetTargetSize() const
{
	return float();
}

void ABuildingGameplayActorPetrol::IgniteTimerExpired()
{
}

void ABuildingGameplayActorPetrol::OnRep_Ignited(bool bPrevIgnited)
{
}

void ABuildingGameplayActorPetrol::OnRep_PrevPetrol()
{
}

void ABuildingGameplayActorPetrol::OnRep_ProjectileCount(int32 PrevProjectileCount)
{
}

void ABuildingGameplayActorPetrol::UpdateCurrentSize()
{
}

void ABuildingGameplayActorPetrol::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorPetrol, PrevPetrol);
	DOREPLIFETIME(ABuildingGameplayActorPetrol, ImpactDirection);
	DOREPLIFETIME(ABuildingGameplayActorPetrol, bIgnited);
	DOREPLIFETIME(ABuildingGameplayActorPetrol, ProjectileCount);
}
