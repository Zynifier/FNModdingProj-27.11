// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaDoghouseVehicle.h"
#include "Net/UnrealNetwork.h"

bool AFortAthenaDoghouseVehicle::GasPedalIsDown() const
{
	return false;
}

EAileronRollDirection AFortAthenaDoghouseVehicle::GetAileronRollDirection() const
{
	return EAileronRollDirection();
}

FVector AFortAthenaDoghouseVehicle::GetAimPoint()
{
	return FVector();
}

FVector AFortAthenaDoghouseVehicle::GetAimPointLocal()
{
	return FVector();
}

float AFortAthenaDoghouseVehicle::GetAltitudeZ() const
{
	return float();
}

FVector AFortAthenaDoghouseVehicle::GetFlightControlForce() const
{
	return FVector();
}

const FFlightControlSurfaces& AFortAthenaDoghouseVehicle::GetFlightControlSurfaces() const
{
	static FFlightControlSurfaces Dummy;
	return Dummy;
}

const FFlightControlSurfaces& AFortAthenaDoghouseVehicle::GetFlightControlSurfaceTargets() const
{
	static FFlightControlSurfaces Dummy;
	return Dummy;
}

FVector AFortAthenaDoghouseVehicle::GetFlightControlTorque() const
{
	return FVector();
}

FVector AFortAthenaDoghouseVehicle::GetShootCenterPoint()
{
	return FVector();
}

FVector AFortAthenaDoghouseVehicle::GetShootCenterPointLocal()
{
	return FVector();
}

float AFortAthenaDoghouseVehicle::GetStandingInPlaceSteeringAngle() const
{
	return float();
}

bool AFortAthenaDoghouseVehicle::IsAileronRolling() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsEngineAutoStartingInAir() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsEngineOn() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsFlying() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsFreelooking() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsRollingInverted() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsRollingLeft() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsRollingRight() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsStallingFromAltitude() const
{
	return false;
}

bool AFortAthenaDoghouseVehicle::IsStandingInPlace() const
{
	return false;
}

void AFortAthenaDoghouseVehicle::MultiBeginAileronRoll_Implementation(EAileronRollDirection Direction)
{
}

void AFortAthenaDoghouseVehicle::OnRep_ControlState()
{
}

void AFortAthenaDoghouseVehicle::ServerBeginAileronRoll_Implementation(EAileronRollDirection Direction)
{
}
bool AFortAthenaDoghouseVehicle::ServerBeginAileronRoll_Validate(EAileronRollDirection Direction)
{
	return true;
}

void AFortAthenaDoghouseVehicle::ServerUpdateControlState_Implementation(FReplicatedControlState InControlState)
{
}
bool AFortAthenaDoghouseVehicle::ServerUpdateControlState_Validate(FReplicatedControlState InControlState)
{
	return true;
}

void AFortAthenaDoghouseVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaDoghouseVehicle, ControlState);
}
