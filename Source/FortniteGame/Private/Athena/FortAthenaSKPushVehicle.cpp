// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaSKPushVehicle.h"

void AFortAthenaSKPushVehicle::CacheAudioPointers(UFortVehicleAudioVoice* InAudioMovement, UFortVehicleAudioVoice* InAudioCoast, UFortVehicleAudioVoice* InAudioSkid, UFortVehicleAudioVoice* InAudioInAir, UFortVehicleAudioVoice* InAudioScrape, UFortVehicleAudioVoice* InAudioWind)
{
}

void AFortAthenaSKPushVehicle::CacheFX(UParticleSystemComponent* InWheelDustFX)
{
}

ECoastState AFortAthenaSKPushVehicle::GetCoastState(bool bGetPhysicsState) const
{
	return ECoastState();
}

FName AFortAthenaSKPushVehicle::GetShoppingCartCoastActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

float AFortAthenaSKPushVehicle::GetStandingInPlaceSteeringAngle() const
{
	return float();
}

bool AFortAthenaSKPushVehicle::IsApplyingPedalForce() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsCoasting() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsDismountingFromCoast() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsEndCoasting() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsMounting() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsReadyToPedalFromCoast() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::IsStandingInPlace() const
{
	return false;
}

bool AFortAthenaSKPushVehicle::PlayerWantsToCoast(bool bCheckAnimOnlyCoast) const
{
	return false;
}
