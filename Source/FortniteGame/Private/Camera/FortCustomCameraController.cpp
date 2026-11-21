// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortCustomCameraController.h"
#include "Net/UnrealNetwork.h"

void AFortCustomCameraController::AllowCustomCameraMode()
{
}

UFortCameraMode* AFortCustomCameraController::GetCameraModeInstance() const
{
	return nullptr;
}

void AFortCustomCameraController::OnRep_IsCustomCameraModeEnabled()
{
}

void AFortCustomCameraController::RestrictCustomCameraMode()
{
}

void AFortCustomCameraController::SetCustomCameraEnabled(const bool bEnable)
{
}

void AFortCustomCameraController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortCustomCameraController, bIsCustomCameraModeEnabled);
}
