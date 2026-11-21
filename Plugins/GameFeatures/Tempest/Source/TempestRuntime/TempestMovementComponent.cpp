// Copyright Epic Games, Inc. All Rights Reserved.

#include "TempestMovementComponent.h"
#include "Net/UnrealNetwork.h"

UTempestMovementComponent::UTempestMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UTempestMovementComponent::OnRep_MovementData() const
{
}

void UTempestMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UTempestMovementComponent, MovementData);
}
