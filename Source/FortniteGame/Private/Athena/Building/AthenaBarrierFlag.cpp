// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaBarrierFlag.h"
#include "Net/UnrealNetwork.h"

UStaticMesh* AAthenaBarrierFlag::GetHeadMesh() const
{
	return nullptr;
}

FVector AAthenaBarrierFlag::GetMeshScale() const
{
	return FVector();
}

AAthenaBarrierObjective* AAthenaBarrierFlag::GetObjectiveActor_Implementation() const
{
	return nullptr;
}

void AAthenaBarrierFlag::OnRep_CurrentState()
{
}

void AAthenaBarrierFlag::OnRep_FoodTeam()
{
}

void AAthenaBarrierFlag::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaBarrierFlag, CurrentState);
	DOREPLIFETIME(AAthenaBarrierFlag, FoodTeam);
}
