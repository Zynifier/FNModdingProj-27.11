// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaGoatVehicle.h"

void AFortAthenaGoatVehicle::CacheParticleComponentPointers(UParticleSystemComponent* WheelDust, UParticleSystemComponent* WheelSlide, UParticleSystemComponent* TrailLeft, UParticleSystemComponent* TrailRight)
{
}

void AFortAthenaGoatVehicle::ClearBoostAccumulated()
{
}

float AFortAthenaGoatVehicle::GetBoostAccumulated() const
{
	return float();
}

FName AFortAthenaGoatVehicle::GetGolfCartEBrakeActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

FName AFortAthenaGoatVehicle::GetGolfCartForwardActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

FName AFortAthenaGoatVehicle::GetGolfCartHonkActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

FName AFortAthenaGoatVehicle::GetGolfCartReverseActionName(AFortPlayerPawn* FortPlayerPawn) const
{
	return FName();
}

bool AFortAthenaGoatVehicle::IsEBraking() const
{
	return false;
}

bool AFortAthenaGoatVehicle::IsLeaningOrBouncingBL() const
{
	return false;
}

bool AFortAthenaGoatVehicle::IsLeaningOrBouncingBR() const
{
	return false;
}

bool AFortAthenaGoatVehicle::IsLeaningOrBouncingFR() const
{
	return false;
}

bool AFortAthenaGoatVehicle::IsLocalPlayerRiding() const
{
	return false;
}

bool AFortAthenaGoatVehicle::IsPowerSliding() const
{
	return false;
}

void AFortAthenaGoatVehicle::SetSkidActive(bool bActive)
{
}
