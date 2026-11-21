// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/FortCurieComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCurieComponent::OnRep_ActiveStateBitfield()
{
}

void UFortCurieComponent::OnRep_ActiveVoxelReplicationData()
{
}

void UFortCurieComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCurieComponent, LastElectricityPropagationParent);
	DOREPLIFETIME(UFortCurieComponent, LastElectrifiedTime);
	DOREPLIFETIME(UFortCurieComponent, LastFireFXRelatedStateTime);
	DOREPLIFETIME(UFortCurieComponent, ActiveStateBitfield);
	DOREPLIFETIME(UFortCurieComponent, ActiveVoxelReplicationData);
}
