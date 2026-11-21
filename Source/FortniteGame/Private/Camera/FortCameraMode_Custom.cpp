// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortCameraMode_Custom.h"

void UFortCameraMode_Custom::AttemptSetMovementRetention(AFortPlayerPawn* FortPawn, const bool bShouldRetain)
{
}

void UFortCameraMode_Custom::ClearCameraRotationOverride()
{
}

void UFortCameraMode_Custom::ClearControlRotationOverride()
{
}

void UFortCameraMode_Custom::ClearViewRotationOverride()
{
}

FVector UFortCameraMode_Custom::GetCameraLookAtLocation() const
{
	return FVector();
}

bool UFortCameraMode_Custom::GetCameraRotationOverride(FRotator& OutRotation) const
{
	return false;
}

bool UFortCameraMode_Custom::GetControlRotationOverride(FRotator& OutRotation) const
{
	return false;
}

void UFortCameraMode_Custom::SetCameraRotationOverride(const FRotator& InRotation)
{
}

void UFortCameraMode_Custom::SetControlRotationOverride(const FRotator& InRotation)
{
}

void UFortCameraMode_Custom::SetViewRotationOverride(const FRotator& InRotation)
{
}

void UFortCameraMode_Custom::UpdateDeadZone(UFortCameraDeadZone* InDeadZone)
{
}
