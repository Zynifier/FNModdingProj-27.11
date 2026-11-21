// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationCarryObjectSpawnPoint.h"
#include "Net/UnrealNetwork.h"

AActor* AInfiltrationCarryObjectSpawnPoint::GetIntelActor() const
{
	return nullptr;
}

void AInfiltrationCarryObjectSpawnPoint::OnEnterWater(AFortWaterBodyActor* WaterBody, UFortWaterInteractionComponent* WaterInteractionComponent, bool bIsFirstBody)
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectDestroy()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectDropped()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectPickedUp()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectPlaced()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectThrown()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnHeldObjectThrownLanded()
{
}

void AInfiltrationCarryObjectSpawnPoint::OnRep_CurrentState(ESpawnPointState OldState)
{
}

void AInfiltrationCarryObjectSpawnPoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AInfiltrationCarryObjectSpawnPoint, CurrentState);
	DOREPLIFETIME(AInfiltrationCarryObjectSpawnPoint, CachedIntelActor);
}
