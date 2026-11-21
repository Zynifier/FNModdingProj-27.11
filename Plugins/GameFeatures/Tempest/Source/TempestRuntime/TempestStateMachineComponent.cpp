// Copyright Epic Games, Inc. All Rights Reserved.

#include "TempestStateMachineComponent.h"
#include "Net/UnrealNetwork.h"

UTempestStateMachineComponent::UTempestStateMachineComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UTempestStateMachineComponent::ForceDissipate(const FString& InDissipationReason)
{
}

ETempestState UTempestStateMachineComponent::GetCurrentState() const
{
	return ETempestState();
}

float UTempestStateMachineComponent::GetCurrentStateCompletionPercentage() const
{
	return float();
}

FTempestStateInfo UTempestStateMachineComponent::GetCurrentStateInfo() const
{
	return FTempestStateInfo();
}

void UTempestStateMachineComponent::OnRep_CurrentStateInfo()
{
}

void UTempestStateMachineComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UTempestStateMachineComponent, CurrentStateInfo);
}
