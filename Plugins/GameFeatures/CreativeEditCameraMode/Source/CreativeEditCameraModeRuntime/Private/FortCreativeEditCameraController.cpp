// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCreativeEditCameraController.h"

void AFortCreativeEditCameraController::HandleWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon)
{
}

void AFortCreativeEditCameraController::OnCreativeEditModeChanged(bool bIsCreativeEditModeEnabled)
{
}

void AFortCreativeEditCameraController::OnWantsToImmersiveEditChanged(UFortCreativeOption* CreativeOption, uint8 IndexValue)
{
}

void AFortCreativeEditCameraController::ServerSetImmersiveEdit_Implementation(const bool bWantsToImmersiveEdit, const bool bIsCreativeEditModeEnabled)
{
}
bool AFortCreativeEditCameraController::ServerSetImmersiveEdit_Validate(const bool bWantsToImmersiveEdit, const bool bIsCreativeEditModeEnabled)
{
	return true;
}
