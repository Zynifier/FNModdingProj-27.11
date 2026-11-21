// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortAFKComponent.h"
#include "Net/UnrealNetwork.h"

UFortAFKComponent::UFortAFKComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortAFKComponent::OnRep_bIsAFKWarningActive()
{
}

void UFortAFKComponent::OnRep_bIsConfirmedAFK()
{
}

void UFortAFKComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortAFKComponent, bIsAFKWarningActive);
	DOREPLIFETIME(UFortAFKComponent, bIsConfirmedAFK);
	DOREPLIFETIME(UFortAFKComponent, NumTimesPlayerWentAFK);
}
