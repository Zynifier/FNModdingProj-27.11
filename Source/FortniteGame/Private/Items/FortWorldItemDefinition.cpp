// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortWorldItemDefinition.h"

bool UFortWorldItemDefinition::CanBeDisassembled() const
{
	return false;
}

UFortWorldItemDefinition* UFortWorldItemDefinition::GetAmmoWorldItemDefinition_BP() const
{
	return nullptr;
}

float UFortWorldItemDefinition::GetDamageAtLevel(int32 ItemLevel) const
{
	return float();
}

float UFortWorldItemDefinition::GetDPSAtLevel(int32 ItemLevel) const
{
	return float();
}

int32 UFortWorldItemDefinition::GetInitialAmmo(const int32 ItemLevel) const
{
	return int32();
}

float UFortWorldItemDefinition::GetMaxDurability(int32 ItemLevel) const
{
	return float();
}
