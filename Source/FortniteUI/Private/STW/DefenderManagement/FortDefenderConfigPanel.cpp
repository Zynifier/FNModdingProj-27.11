// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/DefenderManagement/FortDefenderConfigPanel.h"

int32 UFortDefenderConfigPanel::GetAmmoCountFromDefender(const UFortWorldItemDefinition* AmmoItemDef) const
{
	return int32();
}

int32 UFortDefenderConfigPanel::GetAmmoCountFromPlayer(const UFortWorldItemDefinition* AmmoItemDef) const
{
	return int32();
}

UFortWorldItem* UFortDefenderConfigPanel::GetCompatibleAmmo() const
{
	return nullptr;
}

UFortWorldItemDefinition* UFortDefenderConfigPanel::GetCompatibleAmmoDef() const
{
	return nullptr;
}

UFortWorldItem* UFortDefenderConfigPanel::GetDefenderPawnWeaponItem(const AFortAIPawn* DefenderPawn) const
{
	return nullptr;
}

AFortAIPawn* UFortDefenderConfigPanel::GetSelectedDefenderPawn() const
{
	return nullptr;
}

UFortSchematicItemDefinition* UFortDefenderConfigPanel::GetSourceSchematic(const UFortWorldItemDefinition* ItemDefUsedForCrafting) const
{
	return nullptr;
}

bool UFortDefenderConfigPanel::HasAnyDefenders() const
{
	return false;
}

bool UFortDefenderConfigPanel::HasWeaponForSelectedDefender() const
{
	return false;
}

bool UFortDefenderConfigPanel::IsWeaponSelectionValid() const
{
	return false;
}

bool UFortDefenderConfigPanel::SpawnDefender() const
{
	return false;
}

bool UFortDefenderConfigPanel::UnsummonDefender() const
{
	return false;
}
