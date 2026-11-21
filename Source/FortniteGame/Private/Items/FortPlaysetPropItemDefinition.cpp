// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPlaysetPropItemDefinition.h"

const TSoftClassPtr<AActor>& UFortPlaysetPropItemDefinition::GetPropActorClass() const
{
	static TSoftClassPtr<AActor> Dummy;
	return Dummy;
}
