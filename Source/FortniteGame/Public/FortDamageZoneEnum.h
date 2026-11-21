// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortDamageZoneEnum.generated.h"

UENUM(BlueprintType)
namespace EFortDamageZone
{
	enum Type
	{
		// Light damage zone and should apply < 1.0 damage

		Light = 0,
		// Normal damage zone, this is the default and should apply 1.0x damage

		Normal = 1,
		// Critical damage zone e.g. headshot or weak spot should apply > 1.0 damage

		Critical = 2,
		// Super-critical damage / special damage.  Meant for "special" weak spots such as the Smasher Monkey Butt (when Headshots still exist but are separate)

		Vulnerability = 3,
		// Invulnerable damage zone and should apply no damage, but might have other effects

		Invulnerability = 4,
		Max = 5,
	};
}

