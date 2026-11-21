// Copyright Epic Games, Inc. All Rights Reserved.

#include "StateTree/StateTreeManagerComponent.h"
#include "Net/UnrealNetwork.h"

void UStateTreeManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UStateTreeManagerComponent, ReplicatedStateChanges);
}
