// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMinigameTypes.generated.h"

UENUM(BlueprintType)
enum class EBuildingMode : uint8
{
	None = 0,
	BuildingsOnly = 1,
	TrapsOnly = 2,
	All = 3,
};

UENUM(BlueprintType)
enum class ECreativeBossDisplayMode : uint8
{
	DontOverride = 0,
	Yes = 1,
	No = 2,
};

UENUM(BlueprintType)
enum class EFortMinigameClassResetType : uint8
{
	Never = 0,
	RoundEnd = 1 UMETA(DisplayName="End of Round"),
	GameEnd = 2 UMETA(DisplayName="End of Game"),
	PlayerDeath = 3 UMETA(DisplayName="Player Eliminated"),
};

UENUM(BlueprintType)
enum class EFortMinigameClassSlot : uint8
{
	ZeroIndex = 0 UMETA(Hidden),
	None = 255 UMETA(DisplayName="None/Invalid"),
};

UENUM(BlueprintType)
enum class EFortMinigamePlayerSpawnLocationSetting : uint8
{
	// Spawn at player placed spawn pads

	SpawnPads = 0,
	// Spawn based on device overrides

	Device = 1,
	// Spawn at preplaced spawn points in the level

	Preplaced = 2,
	// Spawn at island spawns in the air

	Air = 3 UMETA(DisplayName="Sky"),
	// Spawn at the player's current location

	CurrentLocation = 4,
};

UENUM(BlueprintType)
enum class EFortMinigamePostGameSpawnLocationSetting : uint8
{
	IslandStart = 0,
	PreGameLocation = 1 UMETA(DisplayName="Pre-Game Location"),
};

UENUM(BlueprintType)
enum class EFortMinigameSpawnPadSelection : uint8
{
	// After all viable locations are found, select randomly from the list.

	Random = 0,
	// After all viable locations are found, select spawn pad on list that is near Median position of the teammates (excluding yourself)

	NearTeammates = 1,
};

UENUM(BlueprintType)
enum class EFortMinigameState : uint8
{
	// No game has started yet

	PreGame = 0,
	// Setting up players

	Setup = 1,
	// Moving players to starting positions, waiting for important actors to replicate, and potentially waiting on nav mesh to generate

	Transitioning = 2,
	// Allow clients time to turn cameras back on

	WaitingForCameras = 3,
	// Countdown

	Warmup = 4,
	// Playing

	InProgress = 5,
	// After the game during time dilation.

	PostGameTimeDilation = 6,
	// Round ended naturally but the game is continuing

	PostRoundEnd = 7,
	// Game ended naturally

	PostGameEnd = 8,
	// Game was abandoned forcefully

	PostGameAbandon = 9,
	// The minigame and island is currently resetting

	PostGameReset = 10,
	// The minigame is being destroyed

	Teardown = 11,
};

UENUM(BlueprintType)
enum class EFortMinigameTimeAliveTeamTrackingMethod : uint8
{
	// Accumulate stat values for each member of the team

	Accumulate = 0 UMETA(DisplayName="Sum"),
	// Use the highest stat value on the team

	Max = 1 UMETA(DisplayName="Longest"),
	// Use the lowest stat value on the team

	Min = 2 UMETA(DisplayName="Shortest"),
};

UENUM(BlueprintType)
enum class EMinigameGameEndCustomPostGameAnimationColorSet : uint8
{
	Default = 0 UMETA(DisplayName="Default"),
	GoldenYellow = 1 UMETA(DisplayName="Golden Yellow"),
	BlueGreen = 2 UMETA(DisplayName="Blue Green"),
	VibrantPurple = 3 UMETA(DisplayName="Vibrant Purple"),
	FuriousFlame = 4 UMETA(DisplayName="Furious Flame"),
	Monochrome = 5 UMETA(DisplayName="Monochrome"),
	FailureRed = 6 UMETA(DisplayName="Failure Red"),
};

UENUM(BlueprintType)
enum class EMinigameGameEndCustomPostGameAnimationStyle : uint8
{
	LightningBolt = 0 UMETA(DisplayName="Lightning Bolt"),
	Shards = 1 UMETA(DisplayName="Shards"),
	WipeLeftToRight = 2 UMETA(DisplayName="Wipe Left to Right"),
	WipeRightToLeft = 3 UMETA(DisplayName="Wipe Right to Left"),
	WipeTopToBottom = 4 UMETA(DisplayName="Wipe Top to Bottom"),
	WipeBottomToTop = 5 UMETA(DisplayName="Wipe Bottom to Top"),
	None = 6 UMETA(DisplayName="None"),
};

UENUM(BlueprintType)
enum class EMinigameGameEndPostGameType : uint8
{
	/** Follow the traditional Creative / Scoreboard flow. */
	Classic = 0 UMETA(DisplayName="Classic"),
	/** Shows traditional Battle Royale postgame */
	BattleRoyale = 1 UMETA(DisplayName="Battle Royale"),
	/** Shows new Creative Royale postgame */
	Custom = 2 UMETA(DisplayName="Custom"),
};

UENUM(BlueprintType)
enum class EPlayerIndicatorDisplayMode : uint8
{
	DontOverride = 0,
	TeamOnly = 1,
	Enemies = 2,
	Anyone = 3,
	Never = 4,
};

USTRUCT(BlueprintType)
struct FMinigamePostGameAnimationSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameAnimationSettings")
	EMinigameGameEndCustomPostGameAnimationStyle Style;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameAnimationSettings")
	EMinigameGameEndCustomPostGameAnimationColorSet ColorSet;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameAnimationSettings")
	FText Text;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameAnimationSettings")
	FText SubText;

};

USTRUCT(BlueprintType)
struct FMinigamePostGameSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	EMinigameGameEndPostGameType PostGameType;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	float PostGameDelay;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	bool bCustomShowScoreboard;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	FMinigamePostGameAnimationSettings VictoryAnimationSettings;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	FMinigamePostGameAnimationSettings DefeatAnimationSettings;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="MinigamePostGameSettings")
	FMinigamePostGameAnimationSettings TieAnimationSettings;

};

