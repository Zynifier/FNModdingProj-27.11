// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponRangedForVehicle.h"
#include "Net/UnrealNetwork.h"

void AFortWeaponRangedForVehicle::OnRep_MountedWeaponInfoRepped()
{
}

void AFortWeaponRangedForVehicle::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeaponRangedForVehicle, MountedWeaponInfoRepped);
}
