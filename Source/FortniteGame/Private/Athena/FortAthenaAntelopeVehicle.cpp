// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaAntelopeVehicle.h"

void AFortAthenaAntelopeVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioEngineRevUp, UFortVehicleAudioVoice* InAudioSkid, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioWind, UFortVehicleAudioVoice* InAudioBoost, UFortVehicleAudioVoice* InAudioHandbrakeSkid, UFortVehicleAudioVoice* InAudioBoostCharge, UFortVehicleAudioVoice* InAudioEngineIdle)
{
}

void AFortAthenaAntelopeVehicle::CacheBoostSM(UStaticMeshComponent* InBoost)
{
}

void AFortAthenaAntelopeVehicle::CacheParticleComponentPointers(UParticleSystemComponent* WheelDust, UParticleSystemComponent* WheelSlide, UParticleSystemComponent* TrailLeft, UParticleSystemComponent* TrailRight, UParticleSystemComponent* InEngineReady)
{
}

void AFortAthenaAntelopeVehicle::CacheWheelBlurStaticMeshes(UStaticMeshComponent* InBL, UStaticMeshComponent* InBR, UStaticMeshComponent* InFL, UStaticMeshComponent* InFR)
{
}

void AFortAthenaAntelopeVehicle::ClearBoostAccumulated()
{
}

float AFortAthenaAntelopeVehicle::GetBoostAccumulated() const
{
	return float();
}

bool AFortAthenaAntelopeVehicle::IsAccumulatingBoost() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsInBoostSmashForgivenessPeriod() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsLeaningOrBouncingBack() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsLocalPlayerRiding() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsNaturalSliding() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsPassivelyExpendingBoost() const
{
	return false;
}

bool AFortAthenaAntelopeVehicle::IsSmashing() const
{
	return false;
}

void AFortAthenaAntelopeVehicle::SetSkidActive(bool bActive)
{
}
