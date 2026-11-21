// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameFeatureEnum.generated.h"

UENUM(BlueprintType)
enum class EFortGameFeature : uint8
{
	// Early startup assets, needed for all other states

	EarlyStartup = 0,
	// This is actually a dedicated server

	DedicatedServer = 1,
	// In the initial kairos startup map, could be patching or loading

	KairosInitial = 2,
	// Doing scene captures for kairos

	KairosCapture = 3,
	// Play video in Kairos via engine

	KairosLoadElectraPlayer = 4,
	// Doing AR dances

	DanceRoyale = 5,
	// In the front end menus

	Frontend = 6,
	// Frontend Lobby menu where you can see the store and select which game to play

	MinimalLobby = 7,
	// Actively playing athena

	GameplayAthena = 8,
	// Actively playing campaign tutorial

	GameplayCampaignTutorial = 9,
	// Actively playing campaign

	GameplayCampaign = 10,
	// Actively playing creative

	GameplayCreative = 11,
	// Cosmetics that are installed instead of downloaded on demand

	PredownloadedCosmetics = 12,
	// Unknown, still initializing

	Invalid = 13,
	Count = 13,
};

