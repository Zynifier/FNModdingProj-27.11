// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortKickReasons.generated.h"

UENUM()
enum class EFortKickReason : uint8
{
	/** default state */
	NotKicked = 0,
	/** all non specific kick reasons, set by KickPlayer if not set elsewhere */
	GenericKick = 1,
	/** ban hammer */
	WasBanned = 2,
	/** missing encryption when required */
	EncryptionRequired = 3,
	/** cross play restriction (ie mixed consoles) */
	CrossPlayRestriction = 4,
	/** client id restriction */
	ClientIdRestriction = 5,
};

