// Copyright Epic Games, Inc. All Rights Reserved.

#include "RockVehicleAbility_Boost.h"
#include "Net/UnrealNetwork.h"

float URockVehicleBoostTank::GetMaxBoostInSeconds() const
{
	return float();
}

float URockVehicleBoostTank::GetPercentRemaining() const
{
	return float();
}

void URockVehicleBoostTank::GiveBoost(float Seconds)
{
}

bool URockVehicleBoostTank::HasBoost() const
{
	return false;
}

bool URockVehicleBoostTank::IsBoostFull() const
{
	return false;
}

void URockVehicleBoostTank::OnRep_SecondsRemaining(float PrevValue)
{
}

void URockVehicleBoostTank::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URockVehicleBoostTank, MaxSeconds);
	DOREPLIFETIME(URockVehicleBoostTank, BoostLogic);
	DOREPLIFETIME(URockVehicleBoostTank, BoostRechargeRate);
	DOREPLIFETIME(URockVehicleBoostTank, BoostRechargeDelay);
	DOREPLIFETIME(URockVehicleBoostTank, SecondsRemaining);
}
