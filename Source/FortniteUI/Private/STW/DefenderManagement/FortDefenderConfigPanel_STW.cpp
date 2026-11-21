// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/DefenderManagement/FortDefenderConfigPanel_STW.h"

void UFortDefenderConfigPanel_STW::DisableInputAction(FDataTableRowHandle InputActionRow)
{
}

void UFortDefenderConfigPanel_STW::EnableInputAction(FDataTableRowHandle InputActionRow)
{
}

int32 UFortDefenderConfigPanel_STW::GetAmmoCountFromDefender(const UFortWorldItemDefinition* AmmoItemDef) const
{
	return int32();
}

int32 UFortDefenderConfigPanel_STW::GetAmmoCountFromPlayer(const UFortWorldItemDefinition* AmmoItemDef) const
{
	return int32();
}

UFortWorldItem* UFortDefenderConfigPanel_STW::GetCompatibleAmmo() const
{
	return nullptr;
}

UFortWorldItemDefinition* UFortDefenderConfigPanel_STW::GetCompatibleAmmoDef() const
{
	return nullptr;
}

UFortWorldItem* UFortDefenderConfigPanel_STW::GetDefenderPawnWeaponItem(const AFortAIPawn* DefenderPawn) const
{
	return nullptr;
}

AFortAIPawn* UFortDefenderConfigPanel_STW::GetSelectedDefenderPawn() const
{
	return nullptr;
}

UFortSchematicItemDefinition* UFortDefenderConfigPanel_STW::GetSourceSchematic(const UFortWorldItemDefinition* ItemDefUsedForCrafting) const
{
	return nullptr;
}

bool UFortDefenderConfigPanel_STW::HasAnyDefenders() const
{
	return false;
}

bool UFortDefenderConfigPanel_STW::HasWeaponForSelectedDefender() const
{
	return false;
}

bool UFortDefenderConfigPanel_STW::IsWeaponSelectionValid() const
{
	return false;
}

void UFortDefenderConfigPanel_STW::RegisterInputAction(FDataTableRowHandle InputActionRow, FCommonAction CommittedEvent)
{
}

bool UFortDefenderConfigPanel_STW::SpawnDefender() const
{
	return false;
}

bool UFortDefenderConfigPanel_STW::UnsummonDefender() const
{
	return false;
}
