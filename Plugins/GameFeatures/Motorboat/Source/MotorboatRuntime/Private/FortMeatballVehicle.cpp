// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortMeatballVehicle.h"

void AFortMeatballVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioEngineUp, UFortVehicleAudioVoice* InAudioEngineDown, UFortVehicleAudioVoice* InAudioWakeTurn, UFortVehicleAudioVoice* InAudioWakeSpeed, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioEngineOutOfFuel)
{
}

void AFortMeatballVehicle::CacheGroundFXComponent(UNiagaraComponent* InGroundFXComponent)
{
}

float AFortMeatballVehicle::GetBoostCharge() const
{
	return float();
}

FVector AFortMeatballVehicle::GetSeatOffset() const
{
	return FVector();
}

FQuat AFortMeatballVehicle::GetSeatRotation() const
{
	return FQuat();
}

void AFortMeatballVehicle::LandShakeEnd()
{
}

void AFortMeatballVehicle::StopDriverCameraShake()
{
}

void AFortMeatballVehicle::StopLandRumble()
{
}

void AFortMeatballVehicle::StopTurnRumble()
{
}

void AFortMeatballVehicle::UpdateSnowAndDirtParams(float NormalizedForwardSpeed)
{
}
