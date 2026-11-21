// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayAbility_AIPortal.h"

ABuildingSMActor* UFortGameplayAbility_AIPortal::GetPortalBuilding() const
{
	return nullptr;
}

FVector UFortGameplayAbility_AIPortal::GetPortalInPoint() const
{
	return FVector();
}

FVector UFortGameplayAbility_AIPortal::GetPortalOutPoint() const
{
	return FVector();
}

bool UFortGameplayAbility_AIPortal::HasPortalOutPoint() const
{
	return false;
}

void UFortGameplayAbility_AIPortal::ModifyCollisions()
{
}
