// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortItemQuantityPair.h"
#include "FortRarityEnum.h"
#include "FortTypes.generated.h"

class AFortPlayerStateAthena;
class UAthenaDanceItemDefinition;
class UCurveFloat;
class UFortAccountItemDefinition;
class UFortAlterationItemDefinition;
class UFortCardPackItemDefinition;
class UFortItemDefinition;
class UFortWorldItemDefinition;
class UObject;

UENUM(BlueprintType)
enum class EChangeInStructDetected : uint8
{
	Dirty = 0 UMETA(DisplayName="Dirty (something changed)"),
	Clean = 1 UMETA(DisplayName="Clean (no changes)"),
};

UENUM(BlueprintType)
enum class EClampToScreenDirection : uint8
{
	Left = 0,
	Top = 1,
	Right = 2,
	Bottom = 3,
	None = 4,
};

UENUM(BlueprintType, meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class ECraftingUpgradeDataFlags : uint8
{
	None = 0 UMETA(Hidden),
	OverrideWrap = 1,
	Durability = 2,
	PhantomAmmo = 4,
	LoadedAmmo = 8,
	ModSlots = 16,
	All = 255,
};

UENUM(BlueprintType)
enum class EDuelState : uint8
{
	Started = 0,
	Won = 1,
	Lost = 2,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EEndOfMatchReason : uint8
{
	LastManStanding = 0,
	// happens when only 1 player or 1 team is standing for victory

	ScoreReached = 1,
	// happens in Score Based Modes indicating the game's score was reach by 1 or more teams

	TimeRanOut = 2,
	// happens in Timed and Score based modes to indicate time ran out so it will pick the winner

	WinEventOccurred = 3,
	// happens when a mode grants victory due to a special win condition

	AllLoggedOut = 4,
	// happens when all players have logged out of the game

	AllEliminated = 5,
};

UENUM()
enum class EEventTournamentRound : uint8
{
	/** Open-to-all tournament */
	Open = 0,
	/** Qualifying games for a tournament */
	Qualifiers = 1,
	/** Semi-finals (Saturday) */
	SemiFinals = 2,
	/* Finals (Sunday) */
	Finals = 3,
	Unknown = 4,
	/** Arena (ongoing multi-division tournaments) */
	Arena = 5,
};

UENUM()
enum class EEventTournamentType : uint8
{
	/** Online tournament */
	Online = 0,
	/** Local tournament on location */
	Onsite = 1,
	/* Bot test, should not track stats*/
	Test = 2,
	Unknown = 3,
};

UENUM(BlueprintType)
namespace EFortAlteration
{
	enum Type
	{
		// Modifies stats of the weapon

		AttributeSlot = 0,
		// Modifies gameplay of the weapon, such as elemental effects

		GameplaySlot = 1,
		// Modifies material or VFX of the weapon

		ComplexCosmeticSlot = 2,
		// Modifies material or VFX of the weapon (budgeted, OK to not load if we run out of the budget)

		UserPickedCosmeticSlot = 3,
		// Modifies color of the weapon

		ColorSlot = 4,
		// Tier 1 hero specialization

		HeroSpecializationTier1Slot = 5,
		// Tier 2 hero specialization

		HeroSpecializationTier2Slot = 6,
		// Tier 3 hero specialization

		HeroSpecializationTier3Slot = 7,
		// Tier 4 hero specialization

		HeroSpecializationTier4Slot = 8,
		// Tier 5 hero specialization

		HeroSpecializationTier5Slot = 9,
	};
}

UENUM(BlueprintType)
enum class EFortBangType : uint8
{
	Invalid = 0,
	// Do not activate this, it is used to flag a case where the bang will have custom management

	Custom = 1,
	PlayTab = 2,
	VaultTab = 3,
	StoreTab = 4,
	QuestsTab = 5,
	FriendsButton = 6,
	PartyInviteButton = 7,
	SubGameAccessChanged = 8,
	DailyRewardsButton = 9,
	QuestsButton = 10,
	CompletedExpeditions = 11,
	MainMenu = 12,
	HelpMenu = 13,
	// Vault Main Tabs

	VaultSchematics = 14,
	VaultLeadSurvivors = 15,
	VaultSurvivors = 16,
	VaultHeroes = 17,
	VaultDefenders = 18,
	VaultResources = 19,
	// Schematics Tabs

	VaultMelee = 20,
	VaultRanged = 21,
	VaultConsumables = 22,
	VaultIngredients = 23,
	VaultTraps = 24,
	// Battle Pass Tab

	BattlePassTab = 25,
	// Special Events Tabs

	SpecialEventTab = 26,
	WinterfestTab = 27,
	// Cosmetics

	CosmeticsTab = 28,
	CosmeticsOutfit = 29,
	CosmeticGlider = 30,
	CosmeticContrail = 31,
	CosmeticBattleBus = 32,
	CosmeticVehicle = 33,
	CosmeticItemWrap = 34,
	CosmeticCallingCard = 35,
	CosmeticMapMarker = 36,
	CosmeticMusicPack = 37,
	CosmeticPetSkin = 38,
	CosmeticLoadingScreen = 39,
	CosmeticBackpack = 40,
	CosmeticHat = 41,
	CosmeticPickaxe = 42,
	CosmeticDance = 43,
	CosmeticCharm = 44,
	// Item Shop

	AthenaDirectedAcquisitionTab = 45,
	MultiProductItemShop = 46,
	ItemShop_RMTItemOfferTab = 47,
	ItemShop_FeaturedTab = 48,
	ItemShop_DailyTab = 49,
	ItemShop_SpecialFeaturedTab = 50,
	ItemShop_SpecialDailyTab = 51,
	ItemShop_StandaloneTab = 52,
	ItemShop_CommunityVotingTab = 53,
	ItemShop_MegaBundleTab = 54,
	ItemShop_BattlePassTab = 55,
	// 

	AthenaChallengesTab = 56,
	// 
// 

	AthenaShowdownTab = 57,
	// 
// 
//

	AthenaCareerTab = 58,
	// 
// 
//
// Misc

	PlayerBanners = 59,
	// New STW Frontend

	STWCommand = 60,
	STWCommand_Heroes = 61,
	STWCommand_Heroes_Manage = 62,
	STWCommand_Heroes_HeroLoadout = 63,
	STWCommand_Heroes_Defenders = 64,
	STWCommand_Heroes_Expeditions = 65,
	STWCommand_Survivors = 66,
	STWCommand_Survivors_Manage = 67,
	STWCommand_Survivors_Squads = 68,
	STWCommand_Upgrades = 69,
	STWCommand_Research = 70,
	STWCommand_AccountXP = 71,
	STWArmory = 72,
	STWArmory_Schematics = 73,
	STWArmory_Backpack = 74,
	STWArmory_Storage = 75,
	STWArmory_CollectionBook = 76,
	STWArmory_Transform = 77,
	STWArmory_Resources = 78,
	STWLocker = 79,
	//New MPLobby SocialButton Frontend

	SocialButton = 80,
};

UENUM(BlueprintType)
enum class EFortClientAnnouncementQueueType : uint8
{
	Toasts = 0,
	Stickies = 1,
	Max = 2,
};

UENUM()
enum class EFortContentRating : uint8
{
	// placeholder! waiting on actual breakdown

	IARC_Everyone = 0,
	IARC_TenPlus = 1,
	IARC_Teen = 2,
};

UENUM(BlueprintType)
enum class EFortCraftFailCause : uint8
{
	// Cannot craft but not sure why

	Unknown = 0,
	// Missing one of the required resources

	NotEnoughResources = 1,
	// Inventory is full, no space for result

	InventoryFull = 2,
	// Team level isn't high enough

	InsufficientTeamLevel = 3,
	// Crafting Queue is full

	CraftingQueueFull = 4,
	// Used for Onboarding, or cases where we locked.

	CurrentlyLocked = 5,
	// Schematic is in an inventory overflow state

	OverflowSchematic = 6,
};

UENUM(BlueprintType)
enum class EFortCreativeAdColorPreset : uint8
{
	Default = 0,
	Emphasized = 1,
	Common = 2,
	Uncommon = 3,
	Rare = 4,
	Epic = 5,
	Legendary = 6,
};

UENUM(BlueprintType)
enum class EFortCreativeAdType : uint8
{
	Default = 0,
	Playset = 1,
	Toy = 2,
	Game = 3,
	Island = 4,
	Knob = 5,
};

UENUM(BlueprintType)
enum class EFortGliderType : uint8
{
	Glider = 0,
	Umbrella = 1,
};

UENUM()
enum class EFortIndicatorState : uint8
{
	Hidden = 0,
	OnlyFriendsVisible = 1,
	Visible = 2,
};

UENUM(BlueprintType)
enum class EFortItemCategoryOrdinal : uint8
{
	Primary = 0,
	Secondary = 1,
	Tertiary = 2,
};

UENUM(BlueprintType)
enum class EFortItemInspectionMode : uint8
{
	Overview = 0,
	Details = 1,
	View = 2,
	Evolution = 3,
	Upgrade = 4,
	UpgradeRarity = 5,
	Promotion = 6,
};

UENUM(BlueprintType)
enum class EFortItemViewRotationMode : uint8
{
	None = 0,
	BoundsPivot = 1,
	World = 2,
	Relative = 3,
	Self = 4,
};

UENUM(BlueprintType)
namespace EFortJumpStaminaCost
{
	enum Type
	{
		None = 0,
		Trigger = 1,
		SprintTrigger = 2,
		SprintAir = 3,
	};
}

UENUM(BlueprintType)
enum class EFortMatchmakingTileStyle : uint8
{
	None = 0,
	Special = 1,
	HighStakes = 2,
	Showdown = 3,
};

UENUM(BlueprintType)
enum class EFortMatchmakingViolatorStyle : uint8
{
	None = 0,
	Basic = 1,
	HighStakes = 2,
	Showdown = 3,
	FirstTimeUser = 4,
};

UENUM(BlueprintType)
enum class EFortNotificationQueueType : uint8
{
	Toasts = 0,
	Stickies = 1,
	Messages = 2,
	Max = 3,
};

UENUM(BlueprintType)
enum class EFortPickerMode : uint8
{
	// Picker for selecting a category of building pieces

	BuildingCategory = 0,
	// Picker for selecting a category of traps

	TrapCategory = 1,
	// Picker for selecting a category of weapons based on the player's inventory

	WeaponCategory = 2,
	// Picker for selecting a category of social actions

	SocialCategory = 3,
	// Picker for selecting a specific building piece

	Building = 4,
	// Picker for selecting a specific trap

	Trap = 5,
	// Picker for selecting a specific trap from a radial

	TrapRadial = 6,
	// Picker for selecting a specific weapon from the inventory

	Weapon = 7,
	// Picker for selecting a specific social action

	Social = 8,
	// Picker for selecting a specific emote action

	DirectPickEmote = 9,
	// Picker for selecting a specific spray action

	DirectPickSpray = 10,
	// Picker for team comms in Athena duos/squads/LTMs

	SquadQuickChat = 11,
	// Picker for selecting one of the weapons in our weapon slots

	WeaponsSlotted = 12,
	// Picker which wants to select a music source.

	MusicSource = 13,
	// Picker which wants to select NPC command

	NPCCommand = 14,
	// Picker which wants to select Squad command

	SquadRequest = 15,
};

UENUM()
enum class EFortPlayerRole : uint8
{
	Player = 0,
	LiveSpectator = 1,
	ReplaySpectator = 2,
	InactivePlayer = 3,
};

UENUM(BlueprintType)
enum class EFortPlaylistTeamSizeType : uint8
{
	Solo = 0,
	/* 1 player */
	Duo = 1,
	/* 2 players */
	Trio = 2,
	/* 3 players */
	Squad = 3,
	/* 4 players */
	LargeTeam = 4,
	/* > 4 players */
	MAX = 5,
};

UENUM(BlueprintType)
enum class EFortPlaylistType : uint8
{
	Default = 0,
	/* Non-Creative non Playground type */
	Playground = 1,
	/* Playground */
	Creative = 2,
	/* Creative */
	Creative_LTM = 3,
};

UENUM(BlueprintType)
enum class EFortQuickTimeEventResult : uint8
{
	None = 0,
	Miss = 1,
	Good = 2,
	Great = 3,
	Perfect = 4,
};

UENUM()
namespace EFortRequestedGameplayAction
{
	enum Type
	{
		// Continue playing as now

		ContinuePlaying = 0,
		// Player is ready to start gameplay

		StartPlaying = 1,
		// Player wants to end gameplay

		StopPlaying = 2,
		// Player wants to enter a zone

		EnterZone = 3,
		// Player wants to return to the lobby

		LeaveZone = 4,
		// Player wants to return to the main menu

		ReturnToMainMenu = 5,
		// Player wants to quit program entirely

		QuitGame = 6,
		// No valid option

		Invalid = 7,
	};
}

UENUM(BlueprintType)
enum class EFortStartupPhase : uint8
{
	// Engine has not fully initialized 

	InitializingEngine = 0,
	// Sitting in delayed startup state, still loading assets for capture

	EarlyStartupLoading = 1,
	// Sitting in delayed startup state ready to perform captures

	EarlyStartupFinished = 2,
	// Asset manager has started it's initial load

	GameStartupLoading = 3,
	// Asset manager has finished initial load, ready for Frontend/Gameplay

	GameStartupFinished = 4,
	// Unknown

	Invalid = 5,
	Count = 5,
};

UENUM()
namespace EFortTileEdgeType
{
	enum Type
	{
		// This defines an edge that has not yet had its type determined

		Undefined = 0,
		// Outer edge

		Outer_1 = 1,
		// Transition edge

		Transition_2 = 2,
		// Inner edge

		Inner_3 = 3,
		// Border edge

		Border_4 = 4,
		// Transition between border and outer

		BorderTransitionSingle_5 = 5,
		// Transition between outer, to border, then back to outer.

		BorderTransitionDouble_6 = 6,
		// MAXIMUM

		MAX = 7,
	};
}

UENUM()
enum class EHighResTexturesChangeReason : uint8
{
	UserGameSettings = 0,
	QualityLevelSelectScreenSettings = 1,
	ContentOnDemandFreedUpMemorySelection = 2,
	ContentOnDemandDisplayOutOfMemory = 3,
	ContentOnDemandOutOfMemoryErrorClosed = 4,
};

UENUM(BlueprintType)
enum class EItemListViewDisplayType : uint8
{
	World = 0,
	Outpost = 1,
	Account = 2,
	DeployableBase = 3,
	Max = 4,
};

UENUM()
enum class EKeepContainerType : uint8
{
	// Initial resources

	Base = 0,
	// Crafting ingredients

	Storeroom = 1,
	// Healing items

	FirstAid = 2,
	// Weapons of choice

	Armory = 3,
	// Traps of choice

	Workshop = 4,
	// Ammunition

	AmmoStash = 5,
	Max = 6 UMETA(Hidden),
};

UENUM(BlueprintType)
namespace EKeepDefenseState
{
	enum Type
	{
		Inactive = 0,
		Warmup = 1,
		Defense = 2,
		LastAlive = 3,
		Max = 4 UMETA(Hidden),
	};
}

UENUM(BlueprintType)
enum class EMatchmakingCancelReasonV2 : uint8
{
	Explicit = 0,
	JoinedParty = 1,
	LeftParty = 2,
	PartyMemberJoined = 3,
	PartyMemberLeft = 4,
	PartyMemberCanceled = 5,
	PartyLeaderSwap = 6,
	PlayReplay = 7,
	UIDestroyed = 8,
	PCDestroyed = 9,
	AppBackgrounded = 10,
	HotfixOutdated = 11,
	TournamentOver = 12,
	NotInParty = 13,
	CrossplayBlocked = 14,
	TournamentCrossplayBlocked = 15,
	AccountLevelTooLow = 16,
	FillNoCrossplay = 17,
	CreativeCanceledByLeader = 18,
	CreativeMemberLeftIsland = 19,
	CreativeIslandStateChanged = 20,
	JoinInProgressRejected = 21,
	MatchmakingDisabled = 22,
	NotLoggedIn = 23,
	NoIdentityInterface = 24,
	NoSessionInterface = 25,
	TimedOut = 26,
	InvalidPlaylist = 27,
	AttemptedToQueueTooFrequently = 28,
	TournamentBlackout = 29,
	CancelledDuringPreTravelSetup = 30,
	Unknown = 31,
};

UENUM()
enum class EMessageDispatcherErrorMessageType : uint8
{
	FailedToSetTrigger_TooManyTriggers = 0,
	FailedToSetReceiver_TooManyReceivers = 1,
	FailedToSetReceiver_TooManyReceiversOnOneChannel = 2,
	FailedToSetTriggerReceiver_InvalidChannel = 3,
	FailedToEnqueueMessage = 4,
	BuildLimitReached = 5,
	UnknownError = 6,
};

UENUM()
enum class EMissionStormShieldState : uint8
{
	/** The storm shield radius is not changing */
	IDLE = 0,
	/** The storm shield radius is increasing over time */
	GROWING = 1,
	/** The storm shield radius is decreasing over time */
	SHRINKING = 2,
	MAX = 3,
};

UENUM(BlueprintType)
enum class EPTTState : uint8
{
	Enabled = 0,
	MicDisabled = 1,
	AllSoundDisabled = 2,
};

UENUM()
enum class EReadyCheckState : uint8
{
	// Host initiated ready check, waiting for response

	CheckStarted = 0,
	// Responded Yes to ready check 

	Ready = 1,
	// Responded No to ready check

	NotReady = 2,
};

UENUM(BlueprintType)
enum class ESettingTab : uint8
{
	None = 0,
	Video = 1,
	Game = 2,
	GameUI = 3,
	Brightness = 4,
	Audio = 5,
	Accessibility = 6,
	Input = 7,
	MouseAndKeyboard = 8,
	Controller = 9,
	ControllerSensitivity = 10,
	TouchAndMotion = 11,
	TouchWeapon = 12,
	Account = 13,
	CreativeWorld = 14,
	CreativePlayer = 15,
};

UENUM(BlueprintType)
enum class EStormShieldDefense : uint8
{
	NotSSD = 0,
	StormShieldExpansion = 1,
	WargameSimulation = 2,
};

UENUM(BlueprintType)
enum class ETutorialType : uint8
{
	None = 0,
	Callout = 1,
	GuardScreen = 2,
	WidgetIntro = 3,
	Highlight = 4,
};

USTRUCT(BlueprintType)
struct FAmmoItemState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Ammo Item State")
	TObjectPtr<UFortWorldItemDefinition> AmmoItemDefintion;

	UPROPERTY(BlueprintReadOnly, Category="Ammo Item State")
	int32 AmmoLoadedCount;

	UPROPERTY(BlueprintReadOnly, Category="Ammo Item State")
	int32 AmmoMaxCount;

};

USTRUCT(BlueprintType)
struct FDamageDistanceTagEval
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageDistanceTagEval")
	float DistanceLimit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="DamageDistanceTagEval")
	FGameplayTag DistanceTag;

};

USTRUCT(BlueprintType)
struct FDataTableRowHandleQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DataTableRowHandleQuantityPair")
	FDataTableRowHandle DataTableRowHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="DataTableRowHandleQuantityPair")
	int32 Quantity;

};

USTRUCT(BlueprintType)
struct FDuelOverlayData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DuelOverlayData")
	FText ChallengerName;

	UPROPERTY(BlueprintReadWrite, Category="DuelOverlayData")
	FText ChallengedNPCName;

	UPROPERTY(BlueprintReadWrite, Category="DuelOverlayData", meta=(DisplayName="Challenger Icon"))
	TSoftObjectPtr<UObject> ChallengerSocialAvatarBrushPtr;

	UPROPERTY(BlueprintReadWrite, Category="DuelOverlayData", meta=(DisplayName="Challenged NPC Icon"))
	TSoftObjectPtr<UObject> ChallengedNPCSocialAvatarBrushPtr;

	UPROPERTY(BlueprintReadWrite, Category="DuelOverlayData", meta=(DisplayName="Challenged NPC Loot"))
	TObjectPtr<UFortItemDefinition> ChallengedNPCLootDef;

};

USTRUCT(BlueprintType)
struct FFortAlterationSlotStatus
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, SaveGame, Category="Item")
	TObjectPtr<UFortAlterationItemDefinition> Alteration;

	UPROPERTY(BlueprintReadOnly, SaveGame, Category="Item")
	int32 MinRequiredLevel;

	UPROPERTY(BlueprintReadOnly, SaveGame, Category="Item")
	EFortRarity MinHostItemRarity;

};

USTRUCT(BlueprintType)
struct FFortCatalogMeta
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCatalogInfo")
	TArray<TObjectPtr<UFortAccountItemDefinition>> ChaseItems;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCatalogInfo")
	TObjectPtr<UFortCardPackItemDefinition> PackDefinition;

};

USTRUCT(BlueprintType)
struct FFortChangeMonitoringStruct
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="FortChangeMonitoringStruct")
	bool bAnyValueDirty;

};

USTRUCT()
struct FFortCreativeMessageDispatcherErrorMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EMessageDispatcherErrorMessageType ErrorMessageType;

	UPROPERTY()
	FText MessageName;

	UPROPERTY()
	FGameplayTag ChannelId;

	UPROPERTY()
	int32 LimitValue;

};

USTRUCT()
struct FFortGameHotfixUpdateResponse
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Status;

};

USTRUCT(BlueprintType)
struct FFortInGameLeaderboardPlacementData : public FFortChangeMonitoringStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	int32 Score;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	int32 ScoreToWin;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	uint8 TeamNum;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerStateAthena>> TeamMembers;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	int32 Placement;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	int32 SortIndex;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	bool bRepresentsLocalPlayer;

	UPROPERTY(BlueprintReadOnly, Category="FortInGameLeaderboardPlacementData")
	float PctToWin;

};

USTRUCT(BlueprintType)
struct FFortItemViewSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	bool UsesPlacementActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	bool UsesFixedCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	bool SupportsZooming;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	float DefaultZoomLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	FFloatRange ZoomRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	EFortItemViewRotationMode RotationMode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	FRotator CameraRotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortItemViewSettings")
	FVector MeshBoundsCenterOffset;

};

USTRUCT()
struct FFortLoginReward : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LoginReward")
	TSoftObjectPtr<UFortAccountItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, Category="LoginReward")
	int32 ItemCount;

	UPROPERTY(EditAnywhere, Category="LoginReward")
	FText Description;

	UPROPERTY(EditAnywhere, Category="LoginReward")
	bool bIsMajorReward;

};

USTRUCT(BlueprintType)
struct FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPieSliceSpawnData")
	FScalableFloat SpawnDirection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPieSliceSpawnData")
	FScalableFloat SpawnDirectionDeviation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPieSliceSpawnData")
	FScalableFloat MinSpawnDistanceFromCenter;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortPieSliceSpawnData")
	FScalableFloat MaxSpawnDistanceFromCenter;

};

USTRUCT()
struct FFortQuestPackInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Quests")
	FString Name;

	UPROPERTY(EditAnywhere, Category="Quests")
	FString DefaultQuestPack;

	UPROPERTY(EditAnywhere, Category="Quests")
	int32 MaxActiveDailyQuests;

	UPROPERTY(EditAnywhere, Category="Quests")
	int32 MaxRerollsPerDay;

	UPROPERTY(EditAnywhere, Category="Quests")
	int32 DaysToKeepClaimedQuests;

	UPROPERTY(EditAnywhere, Category="Quests")
	int32 DaysToKeepCompletedQuests;

	UPROPERTY(EditAnywhere, Category="Quests")
	int32 MaxUnclaimedQuests;

	UPROPERTY(EditAnywhere, Config, Category="Quests")
	bool IsStreamingQuestPack;

};

USTRUCT(BlueprintType)
struct FFortSelectableRewardOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortSelectableRewardOption")
	TArray<FFortItemQuantityPair> Rewards;

};

USTRUCT(BlueprintType)
struct FFortRewardInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfo")
	TArray<FFortSelectableRewardOption> SelectableRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfo")
	TArray<FFortItemQuantityPair> StandardRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRewardInfo")
	TArray<FFortHiddenRewardQuantityPair> HiddenRewards;

};

USTRUCT()
struct FFortSpecialEventEmoteData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortSpecialEventEmoteData")
	TArray<FName> BoundActions;

	UPROPERTY(EditAnywhere, Category="FortSpecialEventEmoteData")
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> Emotes;

};

USTRUCT()
struct FHotfixVolumePlacement : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	FString Map;

	UPROPERTY(Config)
	FVector Center;

	UPROPERTY(Config)
	FVector Extent;

	UPROPERTY(Config)
	FRotator Rotation;

	UPROPERTY(Config)
	FString GameInclude;

	UPROPERTY(Config)
	FString GameExclude;

	UPROPERTY(Config)
	bool bNeededOnClient;

};

USTRUCT(BlueprintType)
struct FProjectileMovementDrunkConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	TObjectPtr<UCurveFloat> DrunkSpeedScaleCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	TObjectPtr<UCurveFloat> DrunkGravityScaleCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float InitialDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float DirectionChangeRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float TurnAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float MinPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="ProjectileMovementDrunkConfig")
	float TurnAngleClamp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingLookaheadDist;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingTurnAngleBlendOut;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingDrunkDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingRandomTargetPositionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingPassedTargetSlackTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingDrunkBlendOutRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingDrunkBlendOutTimeThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingDrunkBlendOutTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingDrunkBlendOutTurnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Homing")
	float HomingAimPointMaxRange;

};

USTRUCT()
struct FPurchasedBattlePassInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Count;

	UPROPERTY()
	FString Id;

};

USTRUCT(BlueprintType)
struct FRecipe : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	TArray<FFortItemQuantityPair> RecipeResults;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	bool bIsConsumed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	TArray<FFortItemQuantityPair> RecipeCosts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	FGameplayTagContainer RequiredCatalysts;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	int32 Score;

};

USTRUCT(BlueprintType)
struct FTransmogSacrifice : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Recipe")
	int32 TransmogSacrificePoints;

};

