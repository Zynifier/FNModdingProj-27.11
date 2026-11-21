// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayStateMachine.h"
#include "Net/UnrealNetwork.h"

void UGameplayStateMachine::EvaluateStateTransition_Implementation()
{
}

FGameplayTag UGameplayStateMachine::GetActiveStateId() const
{
	return FGameplayTag();
}

UGameplayState* UGameplayStateMachine::GetActiveStateObject() const
{
	return nullptr;
}

FGameplayTag UGameplayStateMachine::GetStateMachineId() const
{
	return FGameplayTag();
}

void UGameplayStateMachine::OnRep_ActiveGameplayStateData()
{
}

void UGameplayStateMachine::SetState(const FGameplayTag& InStateId, float InBeginStateDelay)
{
}

void UGameplayStateMachine::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UGameplayStateMachine, StateMachineId);
	DOREPLIFETIME(UGameplayStateMachine, ActiveGameplayStateData);
}
