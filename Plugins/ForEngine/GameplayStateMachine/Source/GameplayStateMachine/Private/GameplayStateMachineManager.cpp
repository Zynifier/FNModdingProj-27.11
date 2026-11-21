// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayStateMachineManager.h"
#include "Net/UnrealNetwork.h"

void UGameplayStateMachineManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UGameplayStateMachineManager, StateMachineList);
}
