// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryFilterEnum.generated.h"

UENUM(BlueprintType)
enum class EFortFrontendInventoryFilter : uint8
{
	// NOTE: Update the enum range macro if you add a new value immediately after this comment!!!

	Schematics = 0,
	WorldItems = 1,
	// "Backpack"

	WorldItemsInGame = 2,
	// "Inventory"

	WorldItemsStorage = 3,
	// frontend storm shield storage, read only

	WorldItemsTransfer = 4,
	ConsumablesAndAccountResources = 5,
	// "Resources"

	Heroes = 6,
	Defenders = 7,
	Survivors = 8,
	// Athena Filter catagories

	AthenaCharacter = 9,
	AthenaBackpack = 10,
	AthenaPickaxe = 11,
	AthenaGliders = 12,
	AthenaContrails = 13,
	AthenaEmotes = 14,
	AthenaItemWraps = 15,
	AthenaLoadingScreens = 16,
	AthenaLobbyMusic = 17,
	AthenaCharm = 18,
	// Hestia-specifc Filter Categories

	HestiaWeapons = 19,
	HestiaResources = 20,
	// Starlight-specific Filter Categories

	StarlightInventory = 21,
	// Don't display in UI at all

	Invisible = 22,
	// Invalid type, used in filters to say "any type"

	Max_None = 23 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EFortInventoryCustomFilter : uint8
{
	Mythic = 0,
	Legendary = 1,
	Epic = 2,
	Rare = 3,
	Uncommon = 4,
	Common = 5,
};

UENUM(BlueprintType)
enum class EFortInventoryFilter : uint8
{
	WeaponMelee = 0,
	WeaponRanged = 1,
	WeaponMod = 2,
	Ammo = 3,
	Traps = 4,
	Consumables = 5,
	Ingredients = 6,
	PlayerAugment = 7,
	Gadget = 8,
	Decorations = 9,
	Badges = 10,
	Heroes = 11,
	LeadSurvivors = 12,
	Survivors = 13,
	Defenders = 14,
	Resources = 15,
	ConversionControl = 16,
	AthenaCosmetics = 17,
	Playset = 18,
	CreativePlot = 19,
	TeamPerk = 20,
	// Workers = Survivors + LeadSurvivors

	Workers = 21,
	// Don't display in UI at all

	Invisible = 22,
	// Invalid type, used in filters to say "any type"

	Max_None = 23 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EInventoryContentSortType : uint8
{
	ByName = 0,
	ByRating = 1,
	ByLevel = 2,
	ByCategory = 3,
	ByRarity = 4,
	ByLocation = 5,
	ByPersonality = 6,
	ByBonus = 7,
	BySubtype = 8,
	ByGrantTime = 9,
	BySeries = 10,
	BySet = 11,
	ByReleaseDate = 12,
	Invalid = 13,
};

