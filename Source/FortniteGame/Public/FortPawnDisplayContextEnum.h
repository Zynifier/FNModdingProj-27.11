// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPawnDisplayContextEnum.generated.h"

UENUM(BlueprintType)
enum class EFortPawnDisplayContext : uint8
{
	BattleRoyale = 0,
	// Used for Battle-Royale only cases, which need to use the old system.

	VaultItemsFromOffer = 1,
	// 

	VaultItem = 2,
	// 
//

	VaultItems = 3,
	// 
//
// 

	VaultItemFromDefinition = 4,
	// 
//
// 
// 

	CampaignFrontEndPlayer = 5,
	// 
//
// 
// 
// Used for the StW lobby, locker, and commander in the Hero Loadout.  Includes both local and remote players.

	CampaignNPC = 6,
	CampaignHeroInspect = 7,
	// For now, also includes ItemShop

	CampaignHeroLoadoutSupport = 8,
	CampaignOutfitPicker = 9,
};

