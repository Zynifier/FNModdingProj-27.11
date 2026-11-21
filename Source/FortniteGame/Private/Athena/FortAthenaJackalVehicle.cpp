// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaJackalVehicle.h"

void AFortAthenaJackalVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioBoost, UFortVehicleAudioVoice* InAudioWind)
{
}

void AFortAthenaJackalVehicle::CacheFX(UParticleSystemComponent* InBoostFX, UParticleSystemComponent* InLoopingFX)
{
}

bool AFortAthenaJackalVehicle::CanActivateBoost() const
{
	return false;
}

bool AFortAthenaJackalVehicle::CanBoost() const
{
	return false;
}

bool AFortAthenaJackalVehicle::CanChargeJump() const
{
	return false;
}

bool AFortAthenaJackalVehicle::CanJump() const
{
	return false;
}

void AFortAthenaJackalVehicle::CheckWater(float WaterLocationZ, UParticleSystemComponent* WaterFX, UAudioComponent* WaterAudio)
{
}

int32 AFortAthenaJackalVehicle::GetBoostCandidateIndex() const
{
	return int32();
}

FFortRechargingActionTimer AFortAthenaJackalVehicle::GetCurrentBoostTimer()
{
	return FFortRechargingActionTimer();
}

bool AFortAthenaJackalVehicle::GetSpringHitLocation(int32 SpringIndex, FVector& HitLocation) const
{
	return false;
}

bool AFortAthenaJackalVehicle::IsDriveModeOnly() const
{
	return false;
}

void AFortAthenaJackalVehicle::NativeOnBoostBegin()
{
}

void AFortAthenaJackalVehicle::NativeOnBoostEnd()
{
}

void AFortAthenaJackalVehicle::OnHeldObjectDropped(AActor* HeldObject)
{
}

void AFortAthenaJackalVehicle::OnHeldObjectPickedUp(AActor* HeldObject)
{
}

void AFortAthenaJackalVehicle::OnWeaponUnholstered()
{
}
