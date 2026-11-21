// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/SidewaysStateComponent.h"
#include "Net/UnrealNetwork.h"

USidewaysStateComponent::USidewaysStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

ESidewaysState USidewaysStateComponent::GetSidewaysState() const
{
	return ESidewaysState();
}

void USidewaysStateComponent::OnRep_SidewaysPlayspace(ASidewaysPlayspace* NewSidewaysPlayspace)
{
}

void USidewaysStateComponent::OnRep_SidewaysState(ESidewaysState LastSidewaysState)
{
}

void USidewaysStateComponent::SetSidewaysState(ESidewaysState NewState, ASidewaysPlayspace* NewSidewaysPlayspace)
{
}

void USidewaysStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USidewaysStateComponent, SidewaysState);
	DOREPLIFETIME(USidewaysStateComponent, SidewaysPlayspace);
}
