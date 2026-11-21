// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ControllerStateComponent.h"
#include "Net/UnrealNetwork.h"

UControllerStateComponent::UControllerStateComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UControllerStateComponent::OnRep_ActiveStates()
{
}

void UControllerStateComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UControllerStateComponent, ActiveStates);
}
