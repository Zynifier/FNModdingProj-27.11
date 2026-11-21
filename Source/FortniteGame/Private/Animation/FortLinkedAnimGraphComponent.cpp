// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortLinkedAnimGraphComponent.h"
#include "Net/UnrealNetwork.h"

void UFortLinkedAnimGraphComponent::OnRep_WindAnimLayer(const TSubclassOf<UAnimInstance> AnimLayer)
{
}

void UFortLinkedAnimGraphComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortLinkedAnimGraphComponent, WindAnimLayer);
}
