// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/DateTime.h"
#include "Party/SocialParty.h"
#include "FortGameActivity.h"
#include "Matchmaking/FortMatchmakingGroupData.h"
#include "Matchmaking/FortMatchmakingGroupMemberData.h"
#include "Matchmaking/MatchmakingTypes.h"
#include "Online/FortMatchmakingPolicy.h"
#include "Online/FortOnlineSessionTypes.h"
#include "STW/AI/GameDifficulty/FortGameDifficultyCalculationData.h"
#include "FortSocialParty.generated.h"

class UFortPartyMember;

UENUM(BlueprintType)
enum class EFortActivityContextFeedbackReason : uint8
{
	None = 0,
	PartyLargerThanTeam = 1,
};

UENUM(BlueprintType)
enum class EFortInvalidActivityReason : uint8
{
	None = 0,
	PartyTooBig = 1,
	NotPartyLeader = 2,
	MatchmakingAlready = 3,
	PlaylistDisabled = 4,
	PlayerIsLfg = 5,
	InvalidData = 6,
};

UENUM(BlueprintType)
enum class EFortPartyState : uint8
{
	/** The party state has not been set yet */
	Undetermined = 0,
	/** In the world view */
	WorldView = 1,
	/** In the theater view */
	TheaterView = 2,
	/** Actively matchmaking, no destination yet */
	Matchmaking = 3,
	/** Destination found and beyond (attempting to join, lobby, game, etc) */
	PostMatchmaking = 4,
	/** Returning to the front end (e.g., after a game) */
	ReturningToFrontEnd = 5,
	/** In the Battle Royale Lobby */
	BattleRoyaleView = 6,
	/** Preloading Battle Royale Assets */
	BattleRoyalePreloading = 7,
	/** Actively Battle Royale Matchmaking */
	BattleRoyaleMatchmaking = 8,
	/** Destination found and beyond (attempting to join, lobby, game, etc) */
	BattleRoyalePostMatchmaking = 9,
};

UENUM()
enum class EFortPowerRatingComparison : uint8
{
	InRange = 0,
	// Joining player power rating is within the mission's range

	OverLevel = 1,
	// Joining player power rating is above the mission's range

	UnderLevel = 2,
	// Joining player power rating is below the mission's range

	Unknown = 3,
};

UENUM(BlueprintType)
enum class EInGameReadyCheckStatus : uint8
{
	None = 0,
	Initiated = 1,
	Finished = 2,
};

USTRUCT()
struct FFortCreativeDiscoverySurfaceRevision
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SurfaceName;

	UPROPERTY()
	int32 Revision;

};

USTRUCT()
struct FFortPackedTileStates
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<uint8> TileStates;

	UPROPERTY()
	int32 NumSetBits;

};

USTRUCT()
struct FFortPartyCampaignInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool LobbyConnectionStarted;

	UPROPERTY()
	EMatchmakingCompleteResult MatchmakingResult;

	UPROPERTY()
	TEnumAsByte<EMatchmakingState::Type> MatchmakingState;

	UPROPERTY()
	bool SessionIsCriticalMission;

	UPROPERTY()
	int32 ZoneTileIndex;

	UPROPERTY()
	FString TheaterId;

	UPROPERTY()
	FFortPackedTileStates TileStates;

};

USTRUCT()
struct FFortPartyMatchmakingInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 BuildId;

	UPROPERTY()
	int32 HotfixVersion;

	UPROPERTY()
	FString RegionId;

	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	int32 PlaylistRevision;

	UPROPERTY()
	FString TournamentId;

	UPROPERTY()
	FString EventWindowId;

	UPROPERTY()
	FString LinkCode;

};

USTRUCT()
struct FFortPartySquadAssignment
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl MemberId;

	UPROPERTY()
	int32 AbsoluteMemberIdx;

};

USTRUCT()
struct FFortPartyRepData : public FPartyRepData
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FString PrimaryGameSessionId;

	UPROPERTY()
	EFortPartyState PartyState;

	UPROPERTY()
	FFortPartyCampaignInfo CampaignInfo;

	UPROPERTY()
	FString ZoneInstanceId;

	UPROPERTY()
	TArray<FFortCreativeDiscoverySurfaceRevision> CreativeDiscoverySurfaceRevisions;

	UPROPERTY()
	FString CustomMatchKey;

	UPROPERTY()
	EFortGameActivityType ActivityType;

	UPROPERTY()
	FDateTime LFGTime;

	UPROPERTY()
	bool AthenaSquadFill;

	UPROPERTY()
	bool AthenaPrivateMatch;

	UPROPERTY()
	TArray<FFortPartySquadAssignment> RawSquadAssignments;

	UPROPERTY()
	FString RegionId;

private:
	UPROPERTY()
	FFortPartyMatchmakingInfo PartyMatchmakingInfo;

	UPROPERTY()
	FString ActivityName;

	UPROPERTY()
	bool PartyIsJoinedInProgress;

	UPROPERTY()
	FString GameSessionKey;

	UPROPERTY()
	bool AllowJoinInProgress;

	UPROPERTY()
	FIslandRepData SelectedIsland;

	UPROPERTY()
	FFortCommonMatchmakingData_Coordinator FortCommonMatchmakingData;

	UPROPERTY()
	FFortMatchmakingMemberData_Coordinator FortMatchmakingMemberData;

	UPROPERTY()
	EInGameReadyCheckStatus CreativeInGameReadyCheckStatus;

};

USTRUCT()
struct FFortPartySquad
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TWeakObjectPtr<UFortPartyMember>> SquadMembers;

};

UCLASS(MinimalAPI)
class UFortSocialParty : public USocialParty
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FGameDifficultyInfo CachedZoneDifficultyInfo;

	UPROPERTY()
	FFortPartyRepData PartyRepData;

	UPROPERTY()
	TArray<FFortPartySquad> PartySquads;

	UPROPERTY(Config)
	bool bSendSocialFriendsActiveAnalytics;

	UPROPERTY(Config)
	bool bPromoteMemberWhenBackgrounding;

	UPROPERTY(Config)
	bool bEnableBootToGroup;

};

