// Copyright Epic Games, Inc. All Rights Reserved.

#include "MovementMode.h"

const UMoverBlackboard* UBaseMovementMode::GetBlackboard() const
{
	return nullptr;
}

UMoverBlackboard* UBaseMovementMode::GetBlackboard_Mutable() const
{
	return nullptr;
}

UKinematicMoverComponent* UBaseMovementMode::GetMoverComponent() const
{
	return nullptr;
}
