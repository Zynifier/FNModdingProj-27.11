// Copyright Epic Games, Inc. All Rights Reserved.

#include "EntityDynamicActivationComponent.h"
#include "Net/UnrealNetwork.h"

void UEntityDynamicActivationComponent::OnEnabledChanged(bool bIsEnabled)
{
}

void UEntityDynamicActivationComponent::OnRep_TransitionTarget()
{
}

void UEntityDynamicActivationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UEntityDynamicActivationComponent, TransitionTargetTime);
	DOREPLIFETIME(UEntityDynamicActivationComponent, bTargetState);
	DOREPLIFETIME(UEntityDynamicActivationComponent, LinkedComponents);
}
