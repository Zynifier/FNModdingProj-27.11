// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"

AFortWeapon* UFortWeaponReticleExtensionWidgetBase::GetEquippedWeapon() const
{
	return nullptr;
}

bool UFortWeaponReticleExtensionWidgetBase::GetIsADS() const
{
	return false;
}

void UFortWeaponReticleExtensionWidgetBase::HandleCooldownTimer(const bool bActivateTimer, const float TimerInterval)
{
}

void UFortWeaponReticleExtensionWidgetBase::HandleEnterVehicleDriver()
{
}

void UFortWeaponReticleExtensionWidgetBase::HandleEnterVehiclePassenger()
{
}

void UFortWeaponReticleExtensionWidgetBase::HandleFullyExitVehicle()
{
}

void UFortWeaponReticleExtensionWidgetBase::HandleTargetingChanged(bool bNewIsADS)
{
}

void UFortWeaponReticleExtensionWidgetBase::HandleVehicleSeatChanged(int32 SeatIndex)
{
}

void UFortWeaponReticleExtensionWidgetBase::SeatChangeEndedWidgetStateHandler()
{
}
