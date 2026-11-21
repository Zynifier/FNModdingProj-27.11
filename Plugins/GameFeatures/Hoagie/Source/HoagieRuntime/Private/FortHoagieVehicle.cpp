// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortHoagieVehicle.h"
#include "Net/UnrealNetwork.h"

float AFortHoagieVehicle::GetAltitude() const
{
	return float();
}

float AFortHoagieVehicle::GetBoostCooldown() const
{
	return float();
}

FVector AFortHoagieVehicle::GetBoostDirection() const
{
	return FVector();
}

float AFortHoagieVehicle::GetBoostDuration() const
{
	return float();
}

float AFortHoagieVehicle::GetBoostTimeLeft() const
{
	return float();
}

float AFortHoagieVehicle::GetDistanceToGround() const
{
	return float();
}

float AFortHoagieVehicle::GetForwardAlpha() const
{
	return float();
}

bool AFortHoagieVehicle::GetIsEngineOn() const
{
	return false;
}

float AFortHoagieVehicle::GetLiftAlpha() const
{
	return float();
}

float AFortHoagieVehicle::GetMaxAltitude() const
{
	return float();
}

float AFortHoagieVehicle::GetMaxBoostCooldown() const
{
	return float();
}

float AFortHoagieVehicle::GetRotorAngleDegrees() const
{
	return float();
}

FVector AFortHoagieVehicle::GetRotorCenterPosition() const
{
	return FVector();
}

float AFortHoagieVehicle::GetRotorSpeed() const
{
	return float();
}

float AFortHoagieVehicle::GetRotorSpeedPercent() const
{
	return float();
}

float AFortHoagieVehicle::GetShutdownTimeLeft() const
{
	return float();
}

float AFortHoagieVehicle::GetSteerAlpha() const
{
	return float();
}

float AFortHoagieVehicle::GetStrafeAlpha() const
{
	return float();
}

FVector AFortHoagieVehicle::GetThrustDirection(bool bWorldSpace) const
{
	return FVector();
}

float AFortHoagieVehicle::GetVerticalSpeedKmh() const
{
	return float();
}

void AFortHoagieVehicle::HoagieOnDisabledChanged(bool bDisabled)
{
}

bool AFortHoagieVehicle::IsScrapingBottom() const
{
	return false;
}

bool AFortHoagieVehicle::IsShuttingDown() const
{
	return false;
}

bool AFortHoagieVehicle::IsStartingUp() const
{
	return false;
}

void AFortHoagieVehicle::MulticastRotorImpulse_Implementation(const FHitResult& RotorHit)
{
}

void AFortHoagieVehicle::OnRefueledFromEmpty()
{
}

void AFortHoagieVehicle::OnRep_ControlState()
{
}

void AFortHoagieVehicle::OnRep_HoagieState()
{
}

void AFortHoagieVehicle::ServerUpdateControlState_Implementation(FReplicatedHeliControlState InControlState)
{
}

void AFortHoagieVehicle::UpdateDamageStateNative(float Damage)
{
}

void AFortHoagieVehicle::UpdateHoagieAnimBP_Implementation()
{
}

void AFortHoagieVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortHoagieVehicle, HoagieStateRep);
	DOREPLIFETIME(AFortHoagieVehicle, ControlState);
}
