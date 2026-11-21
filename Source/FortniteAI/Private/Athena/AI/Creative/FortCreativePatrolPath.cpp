// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/Creative/FortCreativePatrolPath.h"
#include "Net/UnrealNetwork.h"

bool AFortCreativePatrolPath::HasPatrolValidNavMesh() const
{
	return false;
}

void AFortCreativePatrolPath::SetPatrolHasValidNavMesh(const bool bValidNavMesh)
{
}

void AFortCreativePatrolPath::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCreativePatrolPath, CreativePatrolPoints);
}
