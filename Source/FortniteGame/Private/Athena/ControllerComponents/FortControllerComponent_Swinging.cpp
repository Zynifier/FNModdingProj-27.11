// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_Swinging.h"

void UFortControllerComponent_Swinging::EndSwingingMovement()
{
}

bool UFortControllerComponent_Swinging::IsInSwingingMovement() const
{
	return false;
}

bool UFortControllerComponent_Swinging::IsSwingAttached() const
{
	return false;
}

bool UFortControllerComponent_Swinging::IsSwingingGrounded() const
{
	return false;
}

void UFortControllerComponent_Swinging::JumpAndImpulse(const FVector& JumpImpulse)
{
}

void UFortControllerComponent_Swinging::JumpPressed()
{
}

void UFortControllerComponent_Swinging::LaunchEnterSwinging(const FVector& InVelocity)
{
}

void UFortControllerComponent_Swinging::StartSwingingUnattached()
{
}

void UFortControllerComponent_Swinging::SwingAttached(AActor* NewAttachedActor)
{
}

void UFortControllerComponent_Swinging::SwingDetached()
{
}
