// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPickupSourceTypeFlag.generated.h"

UENUM()
enum class EFortPickupSourceTypeFlag : uint8
{
	Other = 0,
	// Mission rewards, scripted gifting, crafting, Llamas (in StW, not sure about BR), Loot Drops (StW gadget, not sure about BR), etc.

	Player = 1,
	Destruction = 2,
	Container = 4,
	AI = 8,
	Tossed = 16,
	FloorLoot = 32,
	Fishing = 64,
	NPCService = 128,
};

UENUM()
enum class EFortPickupSpawnSource : uint8
{
	Unset = 0,
	PlayerElimination = 1,
	Chest = 2,
	SupplyDrop = 3,
	AmmoBox = 4,
	Drone = 5,
	ItemSpawner = 6,
	BotElimination = 7,
	NPCElimination = 8,
	LootDrop = 9,
	TossedByPlayer = 10,
	NPC = 11,
	NPCGift = 12,
	CraftingBench = 13,
	VendingMachine = 14,
};

