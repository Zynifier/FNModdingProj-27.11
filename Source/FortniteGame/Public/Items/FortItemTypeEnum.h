// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortItemTypeEnum.generated.h"

enum class EFortItemType : uint8;

UENUM(BlueprintType)
enum class EFortItemType : uint8
{
	// World item, parent of following types

	WorldItem = 0,
	Ammo = 1,
	Badge = 2,
	BackpackPickup = 3,
	BuildingPiece = 4,
	CharacterPart = 5,
	Consumable = 6,
	Deco = 7,
	EditTool = 8,
	Ingredient = 9,
	ItemCache = 10,
	Food = 11,
	Gadget = 12,
	AthenaGadget = 13,
	HomebaseGadget = 14,
	// BattleLab Devices used in "my island"

	BattleLabDevice = 15,
	// Spytech perks used in Spy LTM

	SpyTechPerk = 16,
	HeroAbility = 17,
	MissionItem = 18,
	Trap = 19,
	// An item that can transform between various Weapon and Gadget items.  For example, the Unstable Bow

	MultiItem = 20,
	// Parent of both types of weapon

	Weapon = 21,
	WeaponMelee = 22,
	WeaponRanged = 23,
	WeaponHarvest = 24,
	WeaponCreativePhone = 25,
	WeaponMod = 26,
	// Wood, metal, etc

	WorldResource = 27,
	// Creative User Prefab

	CreativeUserPrefab = 28,
	CreativePlayset = 29,
	// Vehicles

	Vehicle = 30,
	// Npcs

	Npc = 31,
	PlayerAugment = 32,
	// Account item, parent of following types

	AccountItem = 33,
	// Home base resources and gold

	AccountResource = 34,
	// Pending Account Resources waiting to be collected

	CollectedResource = 35,
	Alteration = 36,
	CardPack = 37,
	Currency = 38,
	Hero = 39,
	Schematic = 40,
	Worker = 41,
	TeamPerk = 42,
	// the definition for player tech unlocked through progression

	PlayerTech = 43,
	// Items that are "one off" like hero slots

	Token = 44,
	DailyRewardScheduleToken = 45,
	// Redeemable code tokens

	CodeToken = 46,
	// Item that represents a F.O.R.T. Stat

	Stat = 47,
	// Item that represents a bonus if it is in your inventory and active

	Buff = 48,
	// Item that represents a grant of a given amount of a Buff item. Should never actually exist in the inventory

	BuffCredit = 49,
	// Quest

	Quest = 50,
	// accolades

	Accolades = 51,
	// Item to track instanced items given to player from a friend chest.  They are often wrappers for real item given, but track stats about it.

	FriendChest = 52,
	//Medal Punch Cards

	MedalsPunchCard = 53,
	//Repeatable Dailies Cards

	RepeatableDailiesCard = 54,
	// A Challenge Bundle is a list of quests with a description and an overall completion criteria, with optional rewards for completion

	ChallengeBundle = 55,
	// A challenge bundle schedule is a list of challenge bundles that are granted either when the schedule is obtained or at some scheduled point in the future

	ChallengeBundleSchedule = 56,
	// special token that will track the completion progress of ChallengeBundles

	ChallengeBundleCompletionToken = 57,
	// Mutator/modifier items

	GameplayModifier = 58,
	Outpost = 59,
	HomebaseNode = 60,
	Defender = 61,
	// Used to take account items and convert them to a more specific item

	ConversionControl = 62,
	DeployableBaseCloudSave = 63,
	// Consumable account items

	ConsumableAccountItem = 64,
	//Quota item

	Quota = 65,
	// Expedition account items

	Expedition = 66,
	// Homebase banner icon for account profile

	HomebaseBannerIcon = 67,
	// Homebase banner color for account profile

	HomebaseBannerColor = 68,
	// sky diving trail

	AthenaSkyDiveContrail = 69,
	// Personal Vehicle

	PersonalVehicle = 70,
	// Glider/umbrella

	AthenaGlider = 71,
	// Athena harvesting tool / melee weapon

	AthenaPickaxe = 72,
	// Hat

	AthenaHat = 73,
	// Backpack

	AthenaBackpack = 74,
	// Character skin

	AthenaCharacter = 75,
	// A dance is a persistent equipable emote and you always have at least one available

	AthenaDance = 76,
	// A consumable emote is a consumable animation (taunt or special dance)

	AthenaConsumableEmote = 77,
	// A loading screen displayed when loading into or out of an athena map

	AthenaLoadingScreen = 78,
	// A battle bus replacement cosmetic

	AthenaBattleBus = 79,
	// Decorative item attached to a vehicle (theoretical)

	AthenaVehicleCosmetic = 80,
	// Decorative skin for one or more weapons or vehicles

	AthenaItemWrap = 81,
	// Calling card displayed when you win/lose a match (theoretical)

	AthenaCallingCard = 82,
	// Topper mesh/fx for the in-world map marker and potentially an icon replacement for the 2D version (theoretical)

	AthenaMapMarker = 83,
	// Music pack for the front end

	AthenaMusicPack = 84,
	// Decorative skin for a pet (theoretical)

	AthenaPetCosmetic = 85,
	// charms that attach to the characters, weapons, pickaxes, 

	AthenaCharmCosmetic = 86,
	// A victory pose is a persistent equipable emote that is automatically played when you win a match (you might not have one though)

	AthenaVictoryPose = 87,
	// A loot chest used in season rewards (potentially distinct from card packs as we show the loot table for these items past a certain point in the season and they may be draw without replacement)

	AthenaSeasonTreasure = 88,
	// The definition of a season in Athena

	AthenaSeason = 89,
	// the definition of a reward graph

	AthenaRewardGraph = 90,
	// some external resource, eg streaming radio or podcast

	AthenaExtResource = 91,
	// The definition of an event in Athena

	EventDescription = 92,
	// MCP tie to BattleLab Devices used in "my playgrounds (ties to BattleLabDevice)"

	BattleLabDeviceAccount = 93,
	// Matchmaking event tokens

	AthenaEventToken = 94,
	// Special item used to track event-based purchases

	EventPurchaseTracker = 95,
	// special token that will grant a cosmetic skin access a variants on the item def

	CosmeticVariantToken = 96,
	// New campaign hero loadout

	CampaignHeroLoadout = 97,
	// Bundle of creative items

	Playset = 98,
	// Container for a prerolled offer

	PrerollData = 99,
	// Creative save slot

	CreativePlot = 100,
	// The right to take a player survey

	PlayerSurveyToken = 101,
	// Locker item holding a set of cosmetics the player may want to use (i.e. Outfit, Backbling, Pickaxe, etc.)

	CosmeticLocker = 102,
	// a physical representation of the banner icon so we can put it in the store and challenge bundles and no longer have dirty hacks.

	BannerToken = 103,
	// a Token that will auto consume once it grants its rested XP amount, if it requires the battle pass but the user does not own it the token will sit on the profile
// until it can be consumed upon the purchase of the battle pass

	RestedXpBoosterToken = 104,
	// token representing ownership of an athena reward graph

	RewardEventGraphPurchaseToken = 105,
	// hardcore modifier object

	HardcoreModifier = 106,
	// Item that grants another item if a specific event is active. Granting these will always either give the target item, or nothing.

	EventDependentItem = 107,
	// Item that represents the ability to access an item, initially to be used for awakening emotes

	ItemAccessToken = 108,
	// Item that will indirectly grant an StW Accolade. These will never persist on the MCP.

	STWAccoladeReward = 109,
	// Item representing player campsite state

	Campsite = 110,
	// Item that represents victory crown state

	VictoryCrown = 111,
	// Item representing player reality sapling state

	RealitySapling = 112,
	// Cosmetic item which represents subcustomization for a larger item (eg, Outfits, Glider)

	Apparel = 113,
	// Item representing a particular layout schema of Apparel within an item

	ApparelLayout = 114,
	// Item representing player augment persisted state

	PlayerAugmentsPersistence = 115,
	// Parent item for Sparks stuff

	SparksCosmeticItem = 116,
	// Special weird item type that isn't saved directly

	SpecialItem = 117,
	Emote = 118,
	Stack = 119,
	CollectionBookPage = 120,
	BGAConsumableWrapper = 121,
	GiftBox = 122,
	GiftBoxUnlock = 123,
	PlaysetProp = 124,
	RegCosmeticDef = 125,
	// Special type, never instantiated. Refers to the profile as a whole

	Profile = 126,
	// DO NOT ADD NEW WORLD OR ACCOUNT ITEMS HERE

	Max_None = 127 UMETA(DisplayName="None"),
};

FORTNITEGAME_API FName EFortItemType_ToName(EFortItemType ItemType);

UCLASS(MinimalAPI)
class UFortItemTypeFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Fort Item Type", meta=(DisplayName="Get Template Type"))
	static EFortItemType GetTemplateType(EFortItemType ItemType);

	UFUNCTION(BlueprintPure, Category="Fort Item Type", meta=(DisplayName="Get Text For Item Type"))
	static FText ToText(EFortItemType ItemType, bool UsePlural = false);

};

