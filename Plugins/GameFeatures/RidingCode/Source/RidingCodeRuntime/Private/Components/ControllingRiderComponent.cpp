// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/ControllingRiderComponent.h"
#include "Net/UnrealNetwork.h"

void UControllingRiderComponent::ControllingActor_OnJumpInput(bool bPressed)
{
}

void UControllingRiderComponent::ControllingActor_OnMoveForward(float Val)
{
}

void UControllingRiderComponent::ControllingActor_OnMoveRight(float Val)
{
}

const FRidingControlInputState& UControllingRiderComponent::GetControlInputState() const
{
	static FRidingControlInputState Dummy;
	return Dummy;
}

void UControllingRiderComponent::HandleGamepadRidingAbilityPressed()
{
}

void UControllingRiderComponent::HandlePettingAbilityPressed()
{
}

void UControllingRiderComponent::HandleRidingAbilityPressed()
{
}

void UControllingRiderComponent::HandleRidingAbilityReleased()
{
}

void UControllingRiderComponent::HandleSpotActorOrPettingAbilityPressed()
{
}

void UControllingRiderComponent::HandleSpotActorOrPettingAbilityReleased()
{
}

bool UControllingRiderComponent::IsTryingToMove(float Tolerance) const
{
	return false;
}

void UControllingRiderComponent::OnRep_ControlInputReliable()
{
}

void UControllingRiderComponent::OnRep_ControlInputUnreliable()
{
}

void UControllingRiderComponent::OnRep_IsControllingRidable()
{
}

void UControllingRiderComponent::OnSprintCanceled_Implementation()
{
}

void UControllingRiderComponent::ReloadPressed()
{
}

void UControllingRiderComponent::ServerCancelPetting_Implementation()
{
}

void UControllingRiderComponent::ServerUpdateControlInputStateReliable_Implementation(FRidingControlInputStateReliable InputState)
{
}
bool UControllingRiderComponent::ServerUpdateControlInputStateReliable_Validate(FRidingControlInputStateReliable InputState)
{
	return true;
}

void UControllingRiderComponent::ServerUpdateControlInputStateUnreliable_Implementation(FRidingControlInputStateUnreliable InputState)
{
}
bool UControllingRiderComponent::ServerUpdateControlInputStateUnreliable_Validate(FRidingControlInputStateUnreliable InputState)
{
	return true;
}

void UControllingRiderComponent::UpdateFromInput_Implementation(float DeltaTime, const FRidingControlInputState& InputState)
{
}

void UControllingRiderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UControllingRiderComponent, bIsControllingRidable);
	DOREPLIFETIME(UControllingRiderComponent, ReplicatedControlInputStateReliable);
	DOREPLIFETIME(UControllingRiderComponent, ReplicatedControlInputStateUnreliable);
}
