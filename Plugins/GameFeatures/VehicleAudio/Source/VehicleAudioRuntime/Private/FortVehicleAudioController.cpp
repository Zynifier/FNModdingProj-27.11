// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortVehicleAudioController.h"

void AFortVehicleAudioController::CacheJitterTime()
{
}

UAudioMotorModelComponent* AFortVehicleAudioController::GetAudioMotorModelComponent() const
{
	return nullptr;
}

UAudioParameterComponent* AFortVehicleAudioController::GetAudioParameterComponent() const
{
	return nullptr;
}

float AFortVehicleAudioController::GetBrakingNative() const
{
	return float();
}

UAudioComponent* AFortVehicleAudioController::GetEngineAudioComponent() const
{
	return nullptr;
}

float AFortVehicleAudioController::GetJitterTime() const
{
	return float();
}

UFortLayeredAudioComponent* AFortVehicleAudioController::GetLayeredAudioComponent() const
{
	return nullptr;
}

const UFortPhysicsVehicleConfigs* AFortVehicleAudioController::GetPhysicsVehicleConfigs() const
{
	return nullptr;
}

bool AFortVehicleAudioController::GetRedlineActive() const
{
	return false;
}

UREVComponent* AFortVehicleAudioController::GetREVComponent() const
{
	return nullptr;
}

float AFortVehicleAudioController::GetThrottleNative() const
{
	return float();
}

AFortAthenaVehicle* AFortVehicleAudioController::GetVehicleActor() const
{
	return nullptr;
}

void AFortVehicleAudioController::Init()
{
}

bool AFortVehicleAudioController::IsNativizationEnabled() const
{
	return false;
}

void AFortVehicleAudioController::SetLayeredAudioComponent(UFortLayeredAudioComponent* InComponent)
{
}

void AFortVehicleAudioController::SetRedlineActive(bool bEnabled)
{
}

void AFortVehicleAudioController::SetVehicle(AFortAthenaVehicle* InVehicle)
{
}

void AFortVehicleAudioController::Shutdown()
{
}

void AFortVehicleAudioController::Update(float DeltaSeconds)
{
}

void AFortVehicleAudioController::UpdateMotorModelNative(float DeltaSeconds)
{
}

bool AFortVehicleAudioController::UseMetasounds() const
{
	return false;
}
