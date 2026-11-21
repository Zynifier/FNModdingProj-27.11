// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayState.h"
#include "Net/UnrealNetwork.h"

void UGameplayState::AddStateRuntimeTag(const FGameplayTag& AddedTag)
{
}

UGameplayStateMachine* UGameplayState::GetGameplayStateMachine() const
{
	return nullptr;
}

AActor* UGameplayState::GetOwningActor() const
{
	return nullptr;
}

FGameplayTag UGameplayState::GetStateId() const
{
	return FGameplayTag();
}

const FGameplayTagContainer& UGameplayState::GetStateRuntimeTags() const
{
	static FGameplayTagContainer Dummy;
	return Dummy;
}

bool UGameplayState::HasAuthority() const
{
	return false;
}

bool UGameplayState::HasStateRuntimeTag(const FGameplayTag& QueryTag)
{
	return false;
}

void UGameplayState::MarkStateToEvaluateTransitions()
{
}

void UGameplayState::RemoveStateRuntimeTag(const FGameplayTag& RemovedTag)
{
}

void UGameplayState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UGameplayState, StateId);
}
