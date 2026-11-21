// Copyright Epic Games, Inc. All Rights Reserved.

#include "Movement/FortTrackMovementComponent.h"
#include "Net/UnrealNetwork.h"

void UFortTrackMovementComponent::FlipDirection()
{
}

float UFortTrackMovementComponent::GetDistanceAlongSpline() const
{
	return float();
}

USplineComponent* UFortTrackMovementComponent::GetSpline() const
{
	return nullptr;
}

AFortTrack* UFortTrackMovementComponent::GetTrack() const
{
	return nullptr;
}

bool UFortTrackMovementComponent::IsReverseDirection() const
{
	return false;
}

void UFortTrackMovementComponent::OnRep_ReplicatedTrackMovement()
{
}

void UFortTrackMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortTrackMovementComponent, TrackVelocity);
	DOREPLIFETIME(UFortTrackMovementComponent, ReplicatedTrackMovement);
}
