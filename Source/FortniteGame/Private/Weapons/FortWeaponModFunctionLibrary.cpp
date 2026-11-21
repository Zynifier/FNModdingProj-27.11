// Copyright Epic Games, Inc. All Rights Reserved.

#include "Weapons/FortWeaponModFunctionLibrary.h"

void UFortWeaponModFunctionLibrary::ApplyModSetToPickup(const UFortWeaponModSetData* ModSet, AFortPickup* WeaponPickup)
{
}

bool UFortWeaponModFunctionLibrary::ApplyWeaponModToPickup(AFortPickup* Pickup, UFortWeaponModItemDefinition* WeaponModItem)
{
	return false;
}

void UFortWeaponModFunctionLibrary::AssignPlayerNameToItemEntry(AFortPlayerStateAthena* PlayerState, FFortItemEntry& ItemEntry)
{
}

void UFortWeaponModFunctionLibrary::AssignPlayerNameToWeapon(AFortPlayerStateAthena* PlayerState, AFortWeapon* Weapon)
{
}

bool UFortWeaponModFunctionLibrary::CanApplyModToWeapon(const UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon)
{
	return false;
}

UStaticMeshComponent* UFortWeaponModFunctionLibrary::FindPreviewModMeshComponent(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon)
{
	return nullptr;
}

TArray<FFortModDisplayData> UFortWeaponModFunctionLibrary::GetModDisplayData(const UObject* WorldContext, const UFortWeaponItemDefinition* WeaponItemDefinition, const UFortWeaponModSetData* WeaponModSetData)
{
	return TArray<FFortModDisplayData>();
}

FWeaponModStaticMeshData UFortWeaponModFunctionLibrary::GetModStaticMeshDataForWeapon(const UObject* WorldContextObject, UFortWeaponModItemDefinition* WMID, UFortWeaponItemDefinition* WID)
{
	return FWeaponModStaticMeshData();
}

const UFortWeaponModSetData* UFortWeaponModFunctionLibrary::GetRandomWeaponModSetData(const UObject* WorldContext, const UFortWeaponItemDefinition* WeaponItemDefinition)
{
	return nullptr;
}

TArray<UFortWeaponModItemDefinition*> UFortWeaponModFunctionLibrary::GetWeaponModsFromPickup(const AFortPickup* Pickup)
{
	return TArray<UFortWeaponModItemDefinition*>();
}

bool UFortWeaponModFunctionLibrary::ModAllowedOnWeapon(const UFortWeaponModItemDefinition* ModDefinition, const AFortWeapon* WeaponActor)
{
	return false;
}

bool UFortWeaponModFunctionLibrary::ModAllowedOnWeaponDefinition(const UFortWeaponModItemDefinition* ModDefinition, const UFortWeaponItemDefinition* WeaponDefintion)
{
	return false;
}

AFortWeapon* UFortWeaponModFunctionLibrary::SpawnWeaponModPreviewActor(const UObject* WorldContextObject, UFortWeaponItemDefinition* WeaponItemDef, FTransform Transform)
{
	return nullptr;
}

UStaticMeshComponent* UFortWeaponModFunctionLibrary::TryAddPreviewWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon)
{
	return nullptr;
}

bool UFortWeaponModFunctionLibrary::TryAddWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon)
{
	return false;
}

TArray<FFortRemoveWeaponModResult> UFortWeaponModFunctionLibrary::TryRemoveAllWeaponModsFromWeapon(AFortWeapon* Weapon)
{
	return TArray<FFortRemoveWeaponModResult>();
}

bool UFortWeaponModFunctionLibrary::TryRemovePreviewWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* PreviewWeapon)
{
	return false;
}

bool UFortWeaponModFunctionLibrary::TryRemoveWeaponMod(UFortWeaponModItemDefinition* WeaponModItem, AFortWeapon* Weapon)
{
	return false;
}

int32 UFortWeaponModFunctionLibrary::TrySplitModsFromWeaponPickup(AFortPlayerController* PlayerController, AFortPickup* Pickup)
{
	return int32();
}
