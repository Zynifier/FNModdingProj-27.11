// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortQuestObjectiveType.generated.h"

class UFortItemDefinition;

UENUM(BlueprintType)
enum class EFortQuestObjectiveItemEvent : uint8
{
	/** Create a specific item using the Crafting skill */
	Craft = 0,
	/** Collect an item in zone for the first time, does not count for gifted items */
	Collect = 1,
	/** Gain one or more of a specific item, on the backend */
	Acquire = 2 UMETA(DisplayName="Mcp Acquire"),
	/** Use up one or more of a specific item, on the backend */
	Consume = 3 UMETA(DisplayName="Mcp Consume"),
	/** Open and use up a card pack */
	OpenCardPack = 4 UMETA(DisplayName="Mcp Open Card Pack"),
	/** Purchase a card pack */
	PurchaseCardPack = 5 UMETA(DisplayName="Mcp Purchase Card Pack"),
	/** Convert/Evolve an item into a new item */
	Convert = 6 UMETA(DisplayName="Mcp Convert"),
	/** Upgrade/Level up an item */
	Upgrade = 7 UMETA(DisplayName="Mcp Upgrade"),
	/** Upgrade Rarity of an item */
	UpgradeRarity = 8 UMETA(DisplayName="Mcp Upgrade Rarity"),
	/** Complete the specified number of quests */
	QuestComplete = 9 UMETA(DisplayName="Mcp Quest Complete"),
	/** Assign a worker to a squad.  */
	AssignWorker = 10 UMETA(DisplayName="Mcp Assign Worker"),
	/** Player advanced the collection book to a new level */
	LevelUpCollectionBook = 11 UMETA(DisplayName="Level Up Collection Book"),
	/** Player advanced the battle pass to a new level */
	LevelUpAthenaSeason = 12 UMETA(DisplayName="Level Up Athena Season"),
	/** Player advanced the battle pass to a new level */
	LevelUpBattlePass = 13 UMETA(DisplayName="Level Up Battle Pass"),
	/** Player gained season xp */
	GainAthenaSeasonXp = 14 UMETA(DisplayName="Gain Athena Season XP"),
	/** Advance the objective if the player has the specified item when the quest is granted */
	HasItem = 15 UMETA(DisplayName="Mcp Has Item"),
	/** Advance the objective if the player has the specified item when the quest is granted */
	HasAccumulatedItem = 16 UMETA(DisplayName="Mcp Has Accumulated Item"),
	/** Slot an item in the collection book */
	SlotInCollection = 17 UMETA(DisplayName="Mcp Slot Item"),
	/** Respec an alteration */
	AlterationRespec = 18 UMETA(DisplayName="Mcp Alteration Respec"),
	/** Upgrade an alteration */
	AlterationUpgrade = 19 UMETA(DisplayName="Mcp Alteration Upgrade"),
	/** Player has ever completed quests of specified type */
	HasCompletedQuest = 20 UMETA(DisplayName="Mcp Has Completed Quest"),
	/** Player has assigned a worker at time of quest grant or while quest active */
	HasAssignedWorker = 21 UMETA(DisplayName="Mcp Has Assigend Worker"),
	/** Player has an upgraded (leveled up) item of the specified type */
	HasUpgraded = 22 UMETA(DisplayName="Mcp Has Upgraded Item"),
	/** Player has an evolved item of the specified type */
	HasConverted = 23 UMETA(DisplayName="Mcp Has Converted Item"),
	/** Player has an upgraded item rarity of the specified type */
	HasUpgradedRarity = 24 UMETA(DisplayName="Mcp Has Upgraded Item Rarity"),
	/** Player has advanced the collection book to at least the given level */
	HasLeveledUpCollectionBook = 25 UMETA(DisplayName="Has Leveled Up Collection Book"),
	/** Slot a hero in a loadout slot */
	SlotHeroInLoadout = 26 UMETA(DisplayName="Slot Hero In Loadout"),
	/** Player has advanced the battle pass to at least the given level */
	HasLeveledUpAthenaSeason = 27 UMETA(DisplayName="Has Leveled Up Athena Season"),
	/** Player has advanced the battle pass to at least the given level */
	HasLeveledUpBattlePass = 28 UMETA(DisplayName="Has Leveled Up Battle Pass"),
	/** Player has gained Athena seasonal xp */
	HasGainedAthenaSeasonXp = 29 UMETA(DisplayName="Has Gained Athena Season XP"),
	/** Time the player has spent in the minigame */
	MinigameTime = 30,
	/** Invalid Type */
	Max_None = 31,
};

UENUM(BlueprintType)
enum class EFortQuestObjectiveStatEvent : uint8
{
	/** Player eliminated something (wildlife, npc, loot llama, etc). Target is the Actor that was killed. Sent for player that is credited with the elim.
	SourceTagContainer contains Tags from Killer - Players tamed wildlife that scores a kill will have tags from wildlife, not the player. */
	Kill = 0 UMETA(DisplayName="Kill Credit"),
	/** Sent to all players on team of player that eliminated something (wildlife, npc, loot llama, etc). The tags sent are the raw Source/Target tags with no contextual (Quest.Metadata...) tags added.
	Blocked if ASC of target has tag Stat.IgnoreKillScore. Target is the Actor that was killed. */
	TeamKill = 1 UMETA(DisplayName="Team Kill Credit"),
	/** If this player contributed damage toward a kill. Target is the actor that was killed. Solo eliminations will have Quest.Metadata.SingleDamager in SourceTags*/
	KillContribution = 2,
	/** Player has done a defined amount damage to an object, player, or creatures. The target is the object, player, or creature which was damaged. */
	Damage = 3 UMETA(DisplayName="Player Dealt Damage"),
	/** Will be called on the players quest manager when any squadmate or themselves deal damage. The target is the object, player, or creature which was damaged. */
	SquadDamage = 4 UMETA(DisplayName="Squadmember Dealt Damage"),
	/** Player entered a POI volume. TargetTagContainer has Gameplay.Action.Player.Discover on discovery.
	SourceTags are tags from player and POI volume. */
	Visit = 5,
	/** Player entered a POI volume and is discovering it - separated from Visit so we can manage reset counts differently for reseting map area exploration.
	TargetTagContainer has Gameplay.Action.Player.Discover on discovery. SourceTags are tags from player and POI volume. */
	VisitDiscoverPOI = 6 UMETA(DisplayName="Discover POI"),
	/** landing after using a parachute. Target is empty. */
	Land = 7,
	/** player using an emote. Target is empty, emote asset tags are passed in Source tags. */
	Emote = 8,
	/** player using a spray. Target is empty, spray asset tags are passed in Source tags. */
	Spray = 9,
	/** player using a toy. Target is empty, toy asset tags are passed in Source tags. */
	Toy = 10 UMETA(DisplayName="Used Toy"),
	/** Team building. Target is the building that was constructed.
	TargetTags have Buildings OwnedTags and BuildingTypeTag that is defined in FortGameData, and Quest.Metadata.AlliedStructure if allied. */
	Build = 11,
	/** Team edit building. Target is the building that was edited.
	TargetTags have Buildings OwnedTags and BuildingTypeTag that is defined in FortGameData, and Quest.Metadata.AlliedStructure if allied. */
	BuildingEdit = 12,
	/** Team repair building. Target is the building that was repaired.
	TargetTags have Buildings OwnedTags and BuildingTypeTag that is defined in FortGameData, and Quest.Metadata.AlliedStructure if allied. */
	BuildingRepair = 13,
	/** Team upgrade building. Target is the building that was upgraded. 
	TargetTags have Buildings OwnedTags and BuildingTypeTag that is defined in FortGameData, and Quest.Metadata.AlliedStructure if allied. */
	BuildingUpgrade = 14,
	/** Team placed Trap. Target is the tags from the item def of the launcher. */
	PlaceTrap = 15,
	/** Complete the specified number of missions. Target is the mission completion tags. */
	Complete = 16 UMETA(DisplayName="Complete Mission"),
	/** Create a specific item using the Crafting skill. Target is the tags of the schematic item definition that was crafted. */
	Craft = 17,
	/** STW: Collect an item in zone for the first time, does not count for gifted items
		BR: An item went into the players inventory. Target is the item that was collected and has all tags from the ItemDefinition picked up in TargetTagContainer.
		Possible TargetTagContainer context: Quest.Metadata.AthenaMaxResources, Quest.Metadata.BrandNewItem (if not tossed, or dropped, or dropped from death)
		To avoid drop/pickup abuse, we decide in code when to fire this, can be overriden to always fire by changing bAlwaysCountForCollectionQuest on the ItemDefinition */
	Collect = 18,
	/** Win the specified number of PvP battles. Target is empty. */
	Win = 19,
	/** Interact with an object.  I.E. Search, use, etc. Target is the focus object of our interact. */
	Interact = 20,
	/** Anyone on team interacts with an object.  I.E. Search, use, etc. Target is the focus object of our teams interact. */
	TeamInteract = 21,
	/** Player destroyed Building Actor(s). Target is the building that was destroyed. Quest.Metadata.AlliedStructure if allied. */
	Destroy = 22 UMETA(DisplayName="Destroy Building"),
	/** Player pawn performs a specified ability. Target is the tags of the used ability spec. */
	Ability = 23,
	/** Player completed a wave. Target is the mission tags of the active mission. */
	WaveComplete = 24,
	/** Catch-all type for less common objectives, e.g. find an NPC's dog. Target is chosen by caller. */
	Custom = 25,
	/** a better use than custom, allows BP to still pass in gameplay tags and use gamecontext so we they dont have to do a ton of extra logic the quest manager already does. Target is chosen by caller. */
	ComplexCustom = 26,
	/** Client authoritative custom objective. Target is chosen by caller. */
	Client = 27,
	/** Rank held at the end of an Athena match. Target is empty. */
	AthenaRank = 28,
	/** Outlive other players in an Athena match. Target is empty.
	 * 
	 * NOTES: This verb doesn't update progress mid-match. Grants all progress after the player has been eliminated.
	 *
	 * Does NOT grant progress if the player quits the match before dying (Return to Lobby included).
	 *
	 * This verb will NOT grant any progress if there isn't an Aircraft phase (e.g. PIE Gameplay).
	 */
	AthenaOutlive = 29,
	/** Revive other players. Target is the player that was revived. */
	RevivePlayer = 30,
	/** Use/Receive healing effects. Trait.Restoration.Health for HP, Trait.Restoration.Shields for Shields
	Possible SourceTags/TargetTags: Quest.Metadata.HealedToFull, Quest.Metadata.HealedTeammate, Quest.Metadata.HealedFromTeammate
	SourceTags captured from the InstigatingPlayer. TargetTags captured from the HealedPlayer, which could be yourself or another player.
	*/
	Heal = 31,
	/** Earn points by performing tricks while operating a vehicle. Target is the vehicle. */
	EarnVehicleTrickPoints = 32,
	/** Earn air time from a jump while operating a vehicle. Target is the vehicle. */
	VehicleAirTime = 33,
	/** Some amount of mission time has elapsed (currently triggered every minute about .0004 seconds after the minute.) 
	 * StW: In order for this to trigger the Mission this objective is part of MUST contain a UFortMissionTimerComponent with bUpdateQuestsTimeElapsed == true
	 * BR/Athena: this will fire every minute on the server quest manager. Target is empty. */
	TimeElapsed = 34,
	/** Player death event. Target is the player that killed another player. */
	Death = 35,
	/** AthenaMarkerComponent calls this when we mark something with an ItemDefinition with Tags. Target is the FortPickup or BuildingContainer that was marked. */
	AthenaMarker = 36,
	/** Called we TeamLeft in the match has changed due to the death of a player or bot. Use Athena.TeamPlacement when evaluating quest & xp row conditions. Target is empty. */
	PlacementUpdate = 37,
	/** when the game storm phase changes. Target is empty. */
	StormPhase = 38 UMETA(DisplayName="Storm Phase Change"),
	/** On an interval track the distance the player has moved over that time. Target is empty. */
	DistanceTraveled = 39,
	/** Sent only for Player Elims/downs, not wildlife, does not give double credit to the same player for both Down/Elim.
	Target is the player who was downed or eliminated. TargetTagContainer will have either Quest.Metadata.Player.Downed or Quest.Metadata.Player.Finished */
	DownOrElim = 40 UMETA(DisplayName="Player Eliminated Or Downed"),
	/** Sent when an Accolade is complete, and the accolade def has tag 'Accolade.Metadata.AdditionalStatEvent'. All tags of the accolade will be sent as Source tags container. Target is empty. */
	Accolade = 41,
	/** Player has taken a defined amount damage from an object, player, or creatures. Target is either empty or the player that dealt damage. */
	TakeDamage = 42,
	/** Player completed an entry to their athena collection book (like fishing), entry tag of the collected item from the collection book will be passed to the Source tags container. Target is empty. */
	AthenaCollection = 43,
	/**
	 * Player found a new entry in their athena collection book (like fish), Following tags will be passed to the source tag container:
	 *  * tag for the collected item
	 *  * tag identifying the collection (Collections.<collection_name>)
	 * Verb has retroactive processing support on MCP when granted, so any previous items in collection will count toward this goal
	 * Verb has game server support to verify quest count matches collection count every time player joins an athena match. 
	 * Target is empty.
	 */
	AthenaCollectionFoundItem = 44,
	/** Player used an NPC service e.g. Duel / Hire / Grantquest / Sellitem / upgradeitem / Bounty / Intel. Target is the NPC service object. */
	UsedNPCService = 45,
	/** Player received an NPC gift e.g. Health / XP / Item etc. Target is the NPC service object. */
	ReceivedNPCGift = 46,
	/** Player began a conversation with an NPC. Target is the NPC that we started a conversation with. */
	InitiatedNPCConversation = 47,
	/** Create a specific item using Crafting in BR. Target is the item that was crafted. */
	AthenaCraft = 48,
	/** Player Turned in the quest to the NPC. Target is empty. */
	AthenaTurnInQuest = 49,
	/** Player modded a vehicle. Target is the vehicle mod that was applied. */
	AthenaVehicleMod = 50,
	/** Player has helped with open a friend chest. Target is empty. */
	AthenaOpenedFriendChest = 51,
	/** Custom athena verb for acquiring an item. This is processed on the server instead of MCP. Target is empty. */
	AthenaAcquire = 52,
	/** Player began a conversation with an Service Station (e.g. payphone/vending machine). Target is the service station object. */
	InitiatedServiceStationConversation = 53,
	/** Custom athena verb for accumulating items. This is processed on the server instead of MCP. Target is empty. */
	AthenaAccumulatedItem = 54,
	/** Player flipped a vehicle. Target is empty. */
	AthenaVehicleFlip = 55,
	/** Player popped a tire on a vehicle. Target is empty. */
	AthenaVehicleTirePopped = 56,
	/** Player revealed a pawns disguise. (i.e. brawny smasher reveal via damage/conversation progress) Target is the player that reveled the disguise. */
	RevealedPawnDisguise = 57,
	/** This quest will only progress when it is manually completed by another quest. Target is empty. */
	ManuallyCompleted = 58,
	/** Player spent bars to use an NPC service e.g. Sellitem / upgradeitem / Bounty / Intel. Quantity indicates bars spent. Target is the NPC service object. */
	SpentBarsOnNPCService = 59,
	/** Player has hit another player with a damage causing source. Target is the player that was hit. */
	Hit = 60,
	/** XP that comes from a Creative Device in a published Island. Target is only the XPAward tag. */
	CreativeDevice = 61,
	/** Player has fed an item to an AI pawn. Target is the item that was fed to the AI pawn. */
	Feed = 62,
	/** Player hits a weak point. Target is empty. Weakpoints are not team/squad, only for player hitting the weak point. A GA is typically used for more precise tracking for their quest */
	HitWeakpoint = 63,
	/** Player placed a tent. Target is the tent that was placed. */
	PlaceTent = 64,
	/** Player has converted an AI pawn. TargetTagContainer is tags of the pawn of the player converting the NPC. Target object is null. */
	ConvertNPC = 65,
	/** Player's tamed pawn has discovered loot. Target is the tamed pawn that discovered loot. */
	DiscoverLoot = 66,
	/** On an interval track, the distance the player has glided after being launched into the air. Target is the player. Source is the object that launched the player. */
	GlideDistance = 67,
	/** Player has thrown an object. Target is the object that was thrown. */
	Throw = 68,
	/** Player has repaired an item */
	Repair = 69,
	/** Player has ignited a structure */
	Ignite = 70,
	/** Sent when Refueling occurs. SourceTags=Tags from actor that's spawning the gas proj or refueling an itemdef. TargetTags=tags from the actor that received the fuel */
	Refuel = 71,
	/** Player damaged a vehicle part enough to disable it. Target is the vehicle. */
	AthenaVehiclePartDisabled = 72,
	/** Player was revived from down but not out */
	RevivedFromDBNO = 73,
	/** Player performed an action and received Xp */
	AthenaGainXp = 74,
	/** Distance traveled in BR. This only takes into account X and Y coordinate changes */
	AthenaDistanceTraveled = 75,
	/** Fires when a match starts (i.e. players enter the battle bus) */
	MatchStarted = 76,
	/** When a player finishes a DBNO player, but was not the killer */
	Finish = 77,
	/** Sent to TeamMembers of Player that dealt a defined amount damage to an object, player, or creatures. The target is the object, player, or creature which was damaged. */
	TeammateDealtDamage = 78,
	/** Player has collected currency. */
	CurrencyCollected = 79,
	/** Sent to who was credited with the elimination (not who finished them off) */
	ScoredPlayerElimination = 80,
	/** Sent to SquadMembers of Player that scored the Elim (did it give an increase in your kill score) */
	SquadScoredPlayerElimination = 81,
	/** Eliminated Wildlife that has the Pawn.Athena.NPC.Wildlife tag*/
	SlayWildlife = 82,
	/** Sent to Teammates of Player that scored the Elim.*/
	TeamScoredPlayerElimination = 83,
	/** Player gained a level */
	AthenaLevelUp = 84,
	/** Player has attached an Augment*/
	AugmentAttached = 85,
	/** Player Earned points in a mini game */
	AthenaEarnMiniGameScore = 86,
	/** Player has augment selections available */
	AugmentsAvailable = 87,
	/** Player has hatched an AI (such as wildlife) */
	HatchedAI = 88,
	/** Same as the generic Kill but only sent when the player is on a ridden creature. Target is the Actor that was killed while Source is the players tags PLUS the tags of the mount (for identifying what the player was riding). */
	KillWhileMounted = 89,
	/** On an interval, track the distance the player has moved over that time if riding a tamed mount. Distance is in METERS and NOT unreal units (centimeters) as opposed to the generic DistanceTraveled. Target is the gameplay tags of the mounted creature. */
	DistanceTraveledWhileMounted = 90,
	/** End of list of gameplay events, these are handled on the dedicated server */
	NumGameplayEvents = 91 UMETA(Hidden),
	/** Gain one or more of a specific item */
	Acquire = 92 UMETA(DisplayName="Mcp Acquire"),
	/** Use up one or more of a specific item */
	Consume = 93 UMETA(DisplayName="Mcp Consume"),
	/** Open and use up a card pack */
	OpenCardPack = 94 UMETA(DisplayName="Mcp Open Card Pack"),
	/** Purchase a card pack */
	PurchaseCardPack = 95 UMETA(DisplayName="Mcp Purchase Card Pack"),
	/** Convert/Evolve an item into a new item */
	Convert = 96 UMETA(DisplayName="Mcp Convert"),
	/** Upgrade/Level up an item */
	Upgrade = 97 UMETA(DisplayName="Mcp Upgrade"),
	/** Upgrade Rarity of an item */
	UpgradeRarity = 98 UMETA(DisplayName="Mcp Upgrade Rarity"),
	/** Complete the specified number of quests */
	QuestComplete = 99 UMETA(DisplayName="Mcp Quest Complete"),
	/** Assign a worker to a squad.  */
	AssignWorker = 100 UMETA(DisplayName="Mcp Assign Worker"),
	/** Collect an expedition.  */
	CollectExpedition = 101 UMETA(DisplayName="Mcp Collect Expedition"),
	/** Collect a successful expedition.  */
	CollectSuccessfulExpedition = 102 UMETA(DisplayName="Mcp Collect Successful Expedition"),
	/** Player advanced the collection book to a new level */
	LevelUpCollectionBook = 103 UMETA(DisplayName="Level Up Collection Book"),
	/** Player advanced the athena season to a new level */
	LevelUpAthenaSeason = 104 UMETA(DisplayName="Level Up Athena Season (NOT WORKING)"),
	/** Player advanced the battle pass to a new level */
	LevelUpBattlePass = 105 UMETA(DisplayName="Level Up Battle Pass"),
	/** Player gained season xp */
	GainAthenaSeasonXp = 106 UMETA(DisplayName="Mcp Gain Athena Season XP"),
	/** An item already exists in the player's inventory when the objective becomes active. */
	HasItem = 107 UMETA(DisplayName="Mcp HasItem"),
	/** tracks how many items the player has gained, on first update we will check what the player already owns to seed */
	HasAccumulatedItem = 108 UMETA(DisplayName="Mcp HasAccumulatedItem"),
	/** Slot up an item in a collection */
	SlotInCollection = 109 UMETA(DisplayName="Mcp Slot Item"),
	/** Respec an alteration */
	AlterationRespec = 110 UMETA(DisplayName="Mcp Alteration Respec"),
	/** Upgrade an alteration */
	AlterationUpgrade = 111 UMETA(DisplayName="Mcp Alteration Upgrade"),
	/** Player has ever completed quests of specified type */
	HasCompletedQuest = 112 UMETA(DisplayName="Mcp Has Completed Quest"),
	/** Player has assigned a worker at time of quest grant or while quest active */
	HasAssignedWorker = 113 UMETA(DisplayName="Mcp Has Assigend Worker"),
	/** Player has an upgraded (leveled up) item of the specified type */
	HasUpgraded = 114 UMETA(DisplayName="Mcp Has Upgraded Item"),
	/** Player has an evolved item of the specified type */
	HasConverted = 115 UMETA(DisplayName="Mcp Has Converted Item"),
	/** Player has an upgraded item rarity of the specified type */
	HasUpgradedRarity = 116 UMETA(DisplayName="Mcp Has Upgraded Item Rarity"),
	/** Player has advanced the collection book to at least the given level */
	HasLeveledUpCollectionBook = 117 UMETA(DisplayName="Has Leveled Up Collection Book"),
	/** Slot a hero in a loadout slot */
	SlotHeroInLoadout = 118 UMETA(DisplayName="Slot Hero In Loadout"),
	/** Player has advanced the athena season to at least the given level */
	HasLeveledUpAthenaSeason = 119 UMETA(DisplayName="Has Leveled Up Athena Season"),
	/** Player has advanced the battle pass to at least the given level */
	HasLeveledUpBattlePass = 120 UMETA(DisplayName="Has Leveled Up Battle Pass"),
	/** Player has gained Athena seasonal xp */
	HasGainedAthenaSeasonXp = 121 UMETA(DisplayName="Has Gained Battle Pass"),
	/** Context specific minigame event */
	MinigameDynamicEvent = 122 UMETA(DisplayName="Non Gameplay Minigame Dynamic Event"),
	/** Player has participated in a minigame to it's completion */
	MinigameComplete = 123 UMETA(DisplayName="Non Gameplay Minigame Completion"),
	/** Player has died, only tracked for minigame purposes */
	MinigameDeath = 124 UMETA(DisplayName="Non Gameplay Minigame Death"),
	/** Player has helped with a kill, only tracked for minigame purposes */
	MinigameAssist = 125 UMETA(DisplayName="Non Gameplay Minigame Assist"),
	/** Invalid Type */
	Max_None = 126,
};

USTRUCT(BlueprintType)
struct FStatEventFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StatEventFilter")
	EFortQuestObjectiveStatEvent StatEvent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StatEventFilter")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEventFilter")
	FGameplayTagContainer TargetTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEventFilter")
	FGameplayTagContainer SourceTagsQuery;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="StatEventFilter")
	FGameplayTagContainer ContextTagsQuery;

};

