// Copyright Epic Games, Inc. All Rights Reserved.

#include "Items/FortPickupInteractOverrideComponent.h"

UFortPickupInteractOverrideComponent::UFortPickupInteractOverrideComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

int32 UFortPickupInteractOverrideComponent::GetPriority() const
{
	return int32();
}
