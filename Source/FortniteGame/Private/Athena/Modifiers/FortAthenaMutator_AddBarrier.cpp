// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AddBarrier.h"
#include "Net/UnrealNetwork.h"

AAthenaBigBaseWall* AFortAthenaMutator_AddBarrier::GetBigBaseWall() const
{
	return nullptr;
}

bool AFortAthenaMutator_AddBarrier::IsBarrierUp() const
{
	return false;
}

void AFortAthenaMutator_AddBarrier::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AddBarrier, BigBaseWall);
}
