// Copyright Epic Games, Inc. All Rights Reserved.

#include "RockVehicle.h"
#include "Net/UnrealNetwork.h"

const FRockRuntimeConfigOverrides& ARockVehicle::GetCurrentRockRuntimeConfigOverrides() const
{
	static FRockRuntimeConfigOverrides Dummy;
	return Dummy;
}

FFortAthenaVehicleInputState ARockVehicle::GetDriverInput() const
{
	return FFortAthenaVehicleInputState();
}

float ARockVehicle::GetThrottleState() const
{
	return float();
}

void ARockVehicle::OnRep_FreeLookCamera()
{
}

void ARockVehicle::ServerSetLegacyDamageValues(bool bDamageFriendlyVehicles, bool bDamageOtherVehicles, bool bDamageOwnVehicle, bool bDamageAllowedFromOtherVehicle)
{
}

void ARockVehicle::ServerToggleFreeCam_Implementation()
{
}
bool ARockVehicle::ServerToggleFreeCam_Validate()
{
	return true;
}

void ARockVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ARockVehicle, bFreeLookCamera);
	DOREPLIFETIME(ARockVehicle, RockRuntimeConfigs);
}
