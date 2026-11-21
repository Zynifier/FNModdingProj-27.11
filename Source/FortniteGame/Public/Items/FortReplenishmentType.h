// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortReplenishmentType.generated.h"

UENUM()
namespace EFortReplenishmentType
{
	enum Type
	{
		// Give the item once and only once. Remove it when it is no longer applicable.

		Restricted = 0,
		// Ensure that at the start of a new zone you AT LEAST have the item at the specified quantity. DO NOT remove the item when it is no longer applicable.

		ClampMin = 1,
		// At the start of a new zone you always give the player this item at the specified quantity.

		Add = 2,
		// Item is granted via a selected ability, and the item should be removed when the ability is not activated. Will also be removed when you switch away from the hero.

		Ability = 3,
	};
}

