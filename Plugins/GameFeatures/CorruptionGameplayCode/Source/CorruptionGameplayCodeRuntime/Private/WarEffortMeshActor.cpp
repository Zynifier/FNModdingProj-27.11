// Copyright Epic Games, Inc. All Rights Reserved.

#include "WarEffortMeshActor.h"
#include "Net/UnrealNetwork.h"

void AWarEffortMeshActor::OnRep_ActiveFundedItems()
{
}

void AWarEffortMeshActor::OnRep_ActiveTryBeforeYouBuyItems()
{
}

void AWarEffortMeshActor::OnRep_CurrentFundingData()
{
}

void AWarEffortMeshActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWarEffortMeshActor, ActiveFundedItems);
	DOREPLIFETIME(AWarEffortMeshActor, ActiveTryBeforeYouBuyItems);
	DOREPLIFETIME(AWarEffortMeshActor, CurrentFundingData);
}
