// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/FortTreadVehicle.h"

float AFortTreadVehicle::GetTreadCompression() const
{
	return float();
}

bool AFortTreadVehicle::GetTreadContactPoints(TArray<FVector>& OutTreadContactPoints, const ETreadSide::Type TreadSide, const bool bIncludeMisses, const bool bOrdered) const
{
	return false;
}

float AFortTreadVehicle::GetTreadPower(const ETreadSide::Type Side, const bool bClamp) const
{
	return float();
}

float AFortTreadVehicle::GetTreadVelocity(const ETreadSide::Type Side, const EVelocityUnits::Type Units) const
{
	return float();
}

bool AFortTreadVehicle::IsLeftTreadEnabled() const
{
	return false;
}

bool AFortTreadVehicle::IsRightTreadEnabled() const
{
	return false;
}

void AFortTreadVehicle::SetLeftTreadEnabled(const bool bNewValue)
{
}

void AFortTreadVehicle::SetRightTreadEnabled(const bool bNewValue)
{
}
