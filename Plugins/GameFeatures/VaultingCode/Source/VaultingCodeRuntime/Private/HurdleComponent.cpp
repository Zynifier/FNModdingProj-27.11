// Copyright Epic Games, Inc. All Rights Reserved.

#include "HurdleComponent.h"
#include "Net/UnrealNetwork.h"

void UHurdleComponent::HandleOwnerJumpInput(bool bPressed)
{
}

void UHurdleComponent::HandleOwnerMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
}

void UHurdleComponent::HandleOwnerTeleported(AFortPawn* TeleportedOwner)
{
}

bool UHurdleComponent::IsContextualActionPrototypeActive() const
{
	return false;
}

void UHurdleComponent::OnMutatorUpdated()
{
}

void UHurdleComponent::OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
}

void UHurdleComponent::OnRep_ReplicatedHurdleState()
{
}

void UHurdleComponent::OnRep_ReplicatedLastTeleportTime()
{
}

void UHurdleComponent::RegisterMutatorUpdatedDelegate(APawn* AffectedPawn)
{
}

void UHurdleComponent::ServerStartHurdle_Implementation(const FReplicatedHurdleTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime)
{
}
bool UHurdleComponent::ServerStartHurdle_Validate(const FReplicatedHurdleTargetingData InReplicatedTargetingData, const double ClientLastTeleportTime)
{
	return true;
}

bool UHurdleComponent::ShouldShowHurdleIndicator() const
{
	return false;
}

void UHurdleComponent::UnregisterMutatorUpdatedDelegate()
{
}

void UHurdleComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UHurdleComponent, ReplayHurdleTargetingData);
	DOREPLIFETIME(UHurdleComponent, LastTeleportTime);
	DOREPLIFETIME(UHurdleComponent, ReplicatedHurdleState);
}
