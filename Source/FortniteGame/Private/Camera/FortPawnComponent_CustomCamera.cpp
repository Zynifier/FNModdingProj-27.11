// Copyright Epic Games, Inc. All Rights Reserved.

#include "Camera/FortPawnComponent_CustomCamera.h"
#include "Net/UnrealNetwork.h"

void UFortPawnComponent_CustomCamera::ActivateCameraController()
{
}

void UFortPawnComponent_CustomCamera::DisableCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController)
{
}

void UFortPawnComponent_CustomCamera::EnableCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController)
{
}

AFortCustomCameraController* UFortPawnComponent_CustomCamera::GetCurrentCameraController() const
{
	return nullptr;
}

AFortCustomCameraController* UFortPawnComponent_CustomCamera::GetCustomCameraController(UObject* ContextObject) const
{
	return nullptr;
}

void UFortPawnComponent_CustomCamera::OnFortPlayerDied(AFortPlayerPawnAthena* PlayerPawnAthena)
{
}

void UFortPawnComponent_CustomCamera::OnRep_CurrentCameraController()
{
}

void UFortPawnComponent_CustomCamera::PopCameraController(UObject* ContextObject, const bool bRefreshActiveCameraController)
{
}

AFortCustomCameraController* UFortPawnComponent_CustomCamera::PushCameraController(UObject* ContextObject, const TSubclassOf<AFortCustomCameraController> CameraControllerClass, const float Priority, const bool bEnabled, const bool bRefreshActiveCameraController)
{
	return nullptr;
}

void UFortPawnComponent_CustomCamera::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPawnComponent_CustomCamera, CurrentCameraController);
	DOREPLIFETIME(UFortPawnComponent_CustomCamera, LastCameraController);
}
