// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaFerretVehicle.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaFerretVehicle::CacheAudioVoicePointers(UFortVehicleAudioVoice* InAudioMovementClose, UFortVehicleAudioVoice* InAudioMovementDistant, UFortVehicleAudioVoice* InAudioWindFirstPerson, UFortVehicleAudioVoice* InAudioDive, UFortVehicleAudioVoice* InAudioTaxi, UFortVehicleAudioVoice* InAudioSpark)
{
}

void AFortAthenaFerretVehicle::CachePlaneFX(UParticleSystemComponent* InPlaneSpeedFX)
{
}

void AFortAthenaFerretVehicle::CachePropAndBoostMeterSM(UStaticMeshComponent* InPropSM, UStaticMeshComponent* InBoostSM)
{
}

float AFortAthenaFerretVehicle::GetBoostCharge() const
{
	return float();
}

bool AFortAthenaFerretVehicle::IsLocalPlayerRiding() const
{
	return false;
}

bool AFortAthenaFerretVehicle::IsShooting() const
{
	return false;
}

bool AFortAthenaFerretVehicle::IsTryingToShoot() const
{
	return false;
}

void AFortAthenaFerretVehicle::SetSkidActive(bool bActive)
{
}

void AFortAthenaFerretVehicle::SpawnWingTrailParticles()
{
}

void AFortAthenaFerretVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaFerretVehicle, MaxHealthToDestroyPropWhileBoosting);
	DOREPLIFETIME(AFortAthenaFerretVehicle, MaxHealthToDestroyPropWithDirectHit);
	DOREPLIFETIME(AFortAthenaFerretVehicle, MaxHealthToDestroyProp);
}
