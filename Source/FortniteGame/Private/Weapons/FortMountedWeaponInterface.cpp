// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortMountedWeaponInterface.h"

void IFortMountedWeaponInterface::AddToIgnoreActors(AActor* Actor)
{
}

TScriptInterface<IFortVehicleInterface> IFortMountedWeaponInterface::BP_GetHostVehicle() const
{
	return TScriptInterface<IFortVehicleInterface>();
}

UFortVehicleSeatWeaponComponent* IFortMountedWeaponInterface::GetWeaponComponentCached()
{
	return nullptr;
}
