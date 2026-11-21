// Copyright Epic Games, Inc. All Rights Reserved.

#include "AutoAimWeaponKismetLibrary.h"

bool UAutoAimWeaponKismetLibrary::DoesAutoAimWeaponHaveLineOfSight(AFortPawn* SourcePawn, AFortPawn* TargetPawn)
{
	return false;
}

bool UAutoAimWeaponKismetLibrary::DoesAutoAimWeaponReticleIntersectTarget(float& OutReticleDistance, AFortPawn* SourcePawn, AFortPawn* TargetPawn, const float ReticleSize)
{
	return false;
}

void UAutoAimWeaponKismetLibrary::FindBestAutoAimTarget(AFortPawn*& OutTargetPawn, float& OutReticleDistance, AFortPlayerPawn* SourcePawn, const float ReticleSize, const float Range)
{
}

UAutoAimWeaponPawnComponent* UAutoAimWeaponKismetLibrary::GetAutoAimWeaponPawnComponent(AFortPawn* SourcePawn)
{
	return nullptr;
}
