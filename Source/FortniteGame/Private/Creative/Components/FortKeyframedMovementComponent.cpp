// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortKeyframedMovementComponent.h"
#include "Net/UnrealNetwork.h"

bool UFortKeyframedMovementComponent::HasValidAnimation() const
{
	return false;
}

bool UFortKeyframedMovementComponent::IsPaused() const
{
	return false;
}

bool UFortKeyframedMovementComponent::IsPlaying() const
{
	return false;
}

void UFortKeyframedMovementComponent::MoveTo(const FTransform& TargetTransform, float OverTime)
{
}

void UFortKeyframedMovementComponent::OnRep_CommandState()
{
}

void UFortKeyframedMovementComponent::Pause()
{
}

void UFortKeyframedMovementComponent::Play()
{
}

bool UFortKeyframedMovementComponent::SetKeyframes(const TArray<FFortKeyframedMovementKeyframeData>& RelativeKeyframes, EFortKeyframedMovementMovementMode MovementModeIn, bool NotifyStateChangeListeners)
{
	return false;
}

void UFortKeyframedMovementComponent::Stop()
{
}

void UFortKeyframedMovementComponent::TeleportTo(const FTransform& Transform)
{
}

void UFortKeyframedMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortKeyframedMovementComponent, PendingCommand);
}
