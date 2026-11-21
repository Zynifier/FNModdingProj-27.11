// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "FortDeathCauseEnum.h"
#include "FortMovementEnums.h"
#include "FortReplayTypes.generated.h"

UENUM()
enum class EDroneFollowMode : uint8
{
	None = 0,
	ForceFacingLocation = 1,
	ForceFacingFollowedPlayer = 2,
	TetherToFollowedPlayer = 3,
	MAX = 4,
};

UENUM(BlueprintType)
enum class EEventMatchScreen : uint8
{
	None = 0,
	ActivePlayerGrid = 1,
	EliminatedPlayerGrid = 2,
	MatchStatus = 3,
	Scoreboard = 4,
};

UENUM(BlueprintType)
enum class EFortReplayEventType : uint8
{
	Elimination = 0,
	Eliminated = 1,
	DBNO = 2,
	/** Marker that the user placed during playback. Initially for broadcast only*/
	UserPlaced = 3,
	MAX = 4 UMETA(Hidden),
};

UENUM()
enum class EHighlightFeatures : uint8
{
	INVALID = 0,
	FollowingPlayerKill = 1,
	/*we got a player who was standing and we eliminated or DBNO'd them. Name is wrong but the value are in the DB now!*/
	FollowingPlayerDeath = 2,
	/*from standing, did we get eliminated. Name is wrong but the values are there in the DB now!*/
	InterestingDeathCause = 3,
	BusyBuilder = 4,
	FastMover = 5,
	LongDistanceKill = 6,
	Multikill = 7,
	StormCloudAction = 8,
	WinningMoment = 9,
	//the moment when the player wins the game

	PlacementScore = 10,
	//what rank we got placed

	FollowingPlayerKillDBNO = 11,
	FollowingPlayerDBNOFinished = 12,
	MaxLongKillDistance = 13,
	VehicleMultikill = 14,
	//multiple eliminations within a time range using a vehicle

	VehiclePlayerLaunchDistance = 15,
	//using the vehicles moment to launch the player forward and in the air

	VehicleKills = 16,
	MaxMidFallKillTime = 17,
	MaxMidFallNoScopeKillTime = 18,
	MaxMidFallKillSpeed = 19,
	MaxMidFallNoScopeSpeed = 20,
	FallingElimination = 21,
	VehicleUsage = 22,
	COUNT = 23,
};

UENUM()
enum class EHighlightSignificances : uint8
{
	NotSignificant = 0,
	SomewhatSignificant = 1,
	Significant = 21,
	VerySignificant = 31,
	Critical = 41,
};

UENUM(BlueprintType)
enum class EHudVisibilityState : uint8
{
	/** All widgets (game view, and Replay view) are visible*/
	FullyVisible = 0,
	/** All elements of gameplay and replay huds are hidden */
	FullyHidden = 1,
	/** Gameplay elements only are visible. Replay timeline, transport bar are hidden*/
	GameOnly = 2,
	/** Replay elements only are visible. Game elements are hidden */
	ReplayOnly = 3,
	MAX = 4 UMETA(Hidden),
};

UENUM()
enum class EPlayEventType : int32
{
	None = 0,
	TeamFlight = 1,
	Zone = 2,
	Elimination = 3,
	PlayerMoves = 4,
	SinglePlayerMove = 5,
	ActorsPosition = 6,
	GameHighlights = 7,
	Timecode = 8,
};

UENUM(BlueprintType)
enum class ESpectatorCameraType : uint8
{
	/** 3rd person camera attached to a player pawn */
	ThirdPerson = 0,
	/** Flying hoverdrone */
	DroneFree = 1,
	/** Camera used by main game */
	Gameplay = 2,
	/** Reverse and Followshots are just presets of the ThirdPerson camera*/
	ReverseShot = 3,
	FollowShot = 4,
	/** Drone, but with view direction locked on to a character */
	DroneFollow = 5,
	/** Drone, but locationally constrained to a character */
	DroneAttach = 6,
	/** Drone but highly elevated with battle map visualization */
	BattleMap = 7,
	/** Drone but used to generate material for augmented reality */
	ARDrone = 8,
	MAX = 9,
};

UENUM(BlueprintType)
enum class ESpectatorSquadIdMode : uint8
{
	AlwaysOff = 0,
	AlwaysOn = 1,
	HoldToDisplay = 2,
};

UENUM(BlueprintType)
enum class EThirdPersonAutoFollowMode : uint8
{
	Off = 0,
	Auto = 1,
	Lazy = 2,
};

USTRUCT(BlueprintType)
struct FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="BaseReplayEventInfo")
	float EventTime;

	UPROPERTY()
	int32 VersionNumber;

};

USTRUCT()
struct FMinimalHighlightShot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 VersionNumber;

	UPROPERTY()
	float StartTimeStamp;

	UPROPERTY()
	float ShotDuration;

	UPROPERTY()
	FUniqueNetIdRepl PlayerId;

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	TMap<EHighlightFeatures, float> FeatureScores;

	UPROPERTY()
	int32 NumEliminations;

	UPROPERTY()
	EHighlightSignificances ClipSignificance;

	UPROPERTY()
	float FinalScore;

};

USTRUCT()
struct FReplayDataActorPosition
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize Position;

};

USTRUCT()
struct FReplayActorsPosition : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FReplayDataActorPosition> Chests;

};

USTRUCT()
struct FReplayDataMoveSnapshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize Position;

	UPROPERTY()
	TEnumAsByte<EFortMovementStyle::Type> MovementStyle;

	UPROPERTY()
	uint16 WorldTime;

};

USTRUCT()
struct FReplayDataMoveSnapshotContainer
{
	GENERATED_BODY()

};

USTRUCT()
struct FReplayDataPlayerMoves : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FReplayDataMoveSnapshotContainer> PlayerPersistentIdToMoveSamples;

};

USTRUCT()
struct FReplayDataSinglePlayerMove : public FBaseReplayEventInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FReplayEliminationEventInfo : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FTransform EventLocation;

	UPROPERTY()
	FTransform InstigatorLocation;

	UPROPERTY(BlueprintReadOnly, Category="ReplayEliminationEventInfo")
	FUniqueNetIdRepl Victim;

	UPROPERTY(BlueprintReadOnly, Category="ReplayEliminationEventInfo")
	FUniqueNetIdRepl Instigator;

	UPROPERTY()
	EDeathCause DeathCause;

	UPROPERTY()
	bool bDBNO;

	UPROPERTY(BlueprintReadOnly, Category="ReplayEliminationEventInfo")
	EFortReplayEventType EventType;

};

USTRUCT()
struct FReplayServerHighlights : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FMinimalHighlightShot> Shots;

};

USTRUCT()
struct FReplayTeamFlightEventInfo : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector StartLocation;

	UPROPERTY()
	FRotator StartRotation;

	UPROPERTY()
	FVector EndLocation;

	UPROPERTY()
	uint8 IndexNum;

};

USTRUCT()
struct FReplayTimecodeEventInfo : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int64 UTCTimecode;

};

USTRUCT()
struct FReplayZoneEventInfo : public FBaseReplayEventInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector ZoneCenter;

	UPROPERTY()
	float ZoneRadius;

};

