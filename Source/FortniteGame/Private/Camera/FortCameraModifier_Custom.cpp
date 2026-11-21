// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortCameraModifier_Custom.h"

FVector UFortCameraModifier_Custom::GetCameraLookAtLocation() const
{
	return FVector();
}

UFortCameraMode* UFortCameraModifier_Custom::GetCameraModeInstance() const
{
	return nullptr;
}

FRotator UFortCameraModifier_Custom::GetCameraRotationInput() const
{
	return FRotator();
}

float UFortCameraModifier_Custom::GetTotalRotationInputClamped() const
{
	return float();
}
