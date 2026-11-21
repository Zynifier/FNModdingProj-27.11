// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FrontEndTypes.generated.h"

UENUM(BlueprintType)
enum class EFrontEndCamera : uint8
{
	Invalid = 0 UMETA(Hidden),
	Command = 1,
	/** Used as the camera for the command screen when hero loadout is enabled. */
	Command_HeroLoadout = 2,
	/** Used as the camera for looking at the hero in the command screen, the until hero loadout system goes online permanently. */
	LegacyHeroLoadout = 3,
	/** Similar to the inspect/vault screen but different camera placement. */
	Cosmetics = 4,
	Expeditions = 5,
	FrontendDefault = 6,
	/** The Heroes area */
	Heroes = 7,
	/** During matchmaking we ask people to pick a hero */
	HeroSelect = 8,
	/** The proper hero loadout camera, to be used once the hero loadout system goes online permanently.*/
	HeroLoadout = 9,
	/** Portal-like home page tab */
	Home = 10,
	/** The home base (main area) */
	HomeBase = 11,
	/** What we look at during the login screen */
	Login = 12,
	Manage1 = 13,
	Manage2 = 14,
	Manage3 = 15,
	Manage4 = 16,
	/** This is where you go to find fights */
	MissionControl = 17,
	/** Once everyone has picked a hero we show the party */
	Party = 18,
	Play = 19,
	Research = 20,
	/** Skill Trees */
	SkillTrees = 21,
	/** Similar to the inspect/vault screen but different camera placement for limited screen utilization. */
	SmallCosmetics = 22,
	/** UI Navigated by clicking in 3D world */
	SpatialUI = 23,
	/** Used for events only */
	SpecialEvent = 24,
	SpecialEvent2 = 25,
	SpecialEvent3 = 26,
	/** The store where we buy stuff */
	Store = 27,
	/** Similar to the inspect/vault screen but different camera placement. */
	StoreItemInspect = 28,
	/** Similar to FrontendDefault but specific to STW for other tabs */
	StwFrontendDefault = 29,
	/** Survivor squads*/
	SurvivorSquadBuilding1 = 30,
	SurvivorSquadBuilding2 = 31,
	SurvivorSquadBuilding3 = 32,
	SurvivorSquadBuilding4 = 33,
	/** Tutorial phases */
	TutorialPhaseOne = 34,
	TutorialPhaseTwo = 35,
	TutorialPhaseThree = 36,
	Upgrades = 37,
	/** The vault */
	Vault = 38,
	/** Displayed prior to the theater of war */
	WorldMap = 39,
	/** Displayed prior to the theater of war */
	LobbyCentered = 40,
	/** Used to display a wide variety of cosmetics*/
	CosmeticDisplay = 41,
	/** Battle Pass Camera */
	BattlePass = 42,
	/** Rewards Screen Camera */
	Rewards = 43,
	/** Special Event Rewards Screen Camera */
	SpecialEventRewards = 44,
	Armory = 45,
	/** DM Stub*/
	DM_Customization = 46,
	/** Discovery in Lobby Camera */
	DiscoveryHome = 47,
};

