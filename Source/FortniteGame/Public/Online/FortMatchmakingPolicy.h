// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "UObject/NoExportTypes.h"
#include "FortTypes.h"
#include "FortMatchmakingPolicy.generated.h"

class UFortSearchPass;

UENUM()
enum class EFortMatchmakingPool : uint8
{
	Any = 0,
	Desktop = 1,
	PS4 = 2,
	XboxOne = 3,
	Mobile = 4,
	Test = 5,
	//Should never really be used but needed for EFortMatchmakingPool FromString

	Switch = 6,
	Console = 7,
	All = 8,
};

UENUM()
enum class EFortMatchmakingPrivacyConfiguration : uint8
{
	/** Using privacy settings of user party */
	UserPartyConfigured = 0,
	/** Forcing matchmaking privacy to private */
	ForcePrivate = 1,
	/** Forcing matchmaking privacy to public */
	ForcePublic = 2,
};

UENUM(BlueprintType)
enum class EMatchmakingCompleteResult : uint8
{
	/** matchmaking not started */
	NotStarted = 0,
	/** An update is needed */
	UpdateNeeded = 1,
	/** outpost was not found */
	OutpostNotFound = 2,
	/** matchmaking was canceled */
	Cancelled = 3,
	/** matchmaking returned no results */
	NoResults = 4,
	/** matchmaking failed internally */
	Failure = 5,
	/** matchmaking failed creating a new session */
	CreateFailure = 6,
	/** matchmaking is complete */
	Success = 7,
};

UENUM()
enum class EMatchmakingFlags : uint8
{
	None = 0,
	// No flags

	CreateNewOnly = 1,
	// Matchmaking should only search for new sessions

	NoReservation = 2,
	// No reservation beacon connection is required (party leader already made one)

	Private = 4,
	// Make a private game

	UseWorldDataOwner = 8,
};

UENUM()
enum class EMatchmakingStartLocation : uint8
{
	/** Start with a lobby search */
	Lobby = 0,
	/** Start with an existing game search */
	Game = 1,
	/** Start by creating a new game */
	CreateNew = 2,
	/** Find a single session */
	FindSingle = 3,
};

USTRUCT()
struct FMatchmakingParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 ControllerId;

	UPROPERTY()
	int32 PartySize;

	UPROPERTY()
	FString DatacenterId;

	UPROPERTY()
	int32 PlaylistId;

	UPROPERTY()
	int32 MatchmakingLevel;

	UPROPERTY()
	int32 MissionDifficultyMin;

	UPROPERTY()
	int32 MissionDifficultyMax;

	UPROPERTY()
	EStormShieldDefense StormShieldDefenseType;

	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	FString ZoneInstanceId;

	UPROPERTY()
	FString WUID;

	UPROPERTY()
	FUniqueNetIdRepl WorldOwnerId;

	UPROPERTY()
	FString SessionId;

	UPROPERTY()
	EMatchmakingStartLocation StartWith;

	UPROPERTY()
	EMatchmakingFlags Flags;

	UPROPERTY()
	float ChanceToHostOverride;

	UPROPERTY()
	float ChanceToHostIncrease;

	UPROPERTY()
	int32 NumAttempts;

	UPROPERTY()
	int32 MaxSearchResultsOverride;

	UPROPERTY()
	int32 MaxProcessedSearchResults;

};

UCLASS(Config=Game)
class UFortMatchmakingPolicy : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	bool bMatchmakingInProgress;

	UPROPERTY(Transient)
	FName SessionName;

	UPROPERTY(Transient)
	FMatchmakingParams CurrentParams;

	UPROPERTY(Transient)
	TObjectPtr<UFortSearchPass> MMPass;

	UPROPERTY(Transient)
	int32 ChanceToHostAttempt;

	UPROPERTY(Config)
	bool bShouldCampaignForceCrossplayConfig;

};

