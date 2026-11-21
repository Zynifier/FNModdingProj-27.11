// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomPartTypeEnum.generated.h"

UENUM(BlueprintType)
namespace EFortCustomPartType
{
	enum Type
	{
		// Defines the head, usually including the hair and face. Supports other parts applying specific morph targets to this part.

		Head = 0,
		// Defines the body of the character, sometimes this is the only part (and this type is required).

		Body = 1,
		//~ Below this are !IsRequiredPart [Technically, only Body is required]
//~ This part can have data related to morphing the hair on the Head part.  Includes, hats, helmets, and even
//~ "head replacements" in some cases.

		Hat = 2,
		/**
		 * This part is not used by Character Item Definitions, rather used mostly for Backpack Item Definitions or as part of a Gadget.
		 * When present, backpacks determine where loot appears to enter the player.
		 **/
		Backpack = 3,
		// This part is primarily used for extra cosmetic fluff, or as the name suggests, tails.

		MiscOrTail = 4,
		// this part is for facial accessories such as glasses, goggles, masks, etc.

		Face = 5,
		// A generic part used for gameplay important items, such as gauntlets.

		Gameplay = 6 UMETA(DisplayName="Gauntlets/Arms (Gameplay)"),
		//~ Used for gauntlets and such, maybe?

		NumTypes = 7 UMETA(Hidden),
	};
}

