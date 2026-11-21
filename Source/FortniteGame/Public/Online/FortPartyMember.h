// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Party/PartyMember.h"
#include "Cosmetics/Stats/FortCosmeticStatTypes.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortSubGameTypes.h"
#include "Items/FortItemTypeEnum.h"
#include "Matchmaking/FortMatchmakingGroupData.h"
#include "Matchmaking/FortMatchmakingGroupMemberData.h"
#include "Matchmaking/MatchmakingTypes.h"
#include "OnlineLinkId.h"
#include "FortPartyMember.generated.h"

class UAthenaBackpackItemDefinition;
class UAthenaCharacterItemDefinition;
class UAthenaPickaxeItemDefinition;
class UAthenaSkyDiveContrailItemDefinition;
class UFortFeatItemDefinition;
class UFortHeroType;
class UFortMontageItemDefinitionBase;

UENUM()
enum class EFortPartyMemberInGameMode : uint8
{
	/** Not in a specific mode */
	None = 0,
	/** Playing Battle Royale */
	InBattleRoyale = 1,
	/** Playing Creative */
	InCreative = 2,
	/** Playing Save the World */
	InSaveTheWorld = 3,
};

UENUM()
enum class EFortPartyMemberLocation : uint8
{
	/** No destination yet */
	PreLobby = 0,
	/** Destination found and attempting to join */
	ConnectingToLobby = 1,
	/** Properly connected to the lobby */
	Lobby = 2,
	/** Launching the game */
	JoiningGame = 3,
	/** Processing a rejoin */
	ProcessingRejoin = 4,
	/** Successfully in the game */
	InGame = 5,
	/** Spectating a game */
	Spectating = 6,
	/** Watching a replay */
	WatchingReplay = 7,
	/** Returning to the front end */
	ReturningToFrontEnd = 8,
};

UENUM()
enum class EFortPartyMemberReadyCheckStatus : uint8
{
	/** No ready check is active or completed at this time. */
	None = 0,
	/** A ready check is active and in progress. */
	InProgress = 1,
	/** A ready check has been completed, after we are done with matchmaking this should go back to None. */
	Complete = 2,
	/** A ready check has been canceled, after we are done with matchmaking this should go back to none. */
	Canceled = 3,
};

UENUM()
enum class EPartyMemberVoiceChatStatus : uint8
{
	/** Voice chat is disabled */
	Disabled = 0,
	/** Voice chat is enabled */
	Enabled = 1,
	/** Party member is in party voice */
	PartyVoice = 2,
	/** Party member is in game voice */
	GameVoice = 3,
	/** Party member is in platform voice */
	PlatformVoice = 4,
};

UENUM()
enum class ESquadChangeType : uint8
{
	JoinSquad = 0,
	BenchSelf = 1,
	UnbenchSelf = 2,
	Swap = 3,
	None = 4,
};

USTRUCT()
struct FPartyMemberAthenaBannerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString BannerIconId;

	UPROPERTY()
	FString BannerColorId;

	UPROPERTY()
	int32 SeasonLevel;

};

USTRUCT()
struct FPartyMemberBattlePassInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bHasPurchasedPass;

	UPROPERTY()
	int32 PassLevel;

	UPROPERTY()
	int32 SelfBoostXp;

	UPROPERTY()
	int32 FriendBoostXp;

};

USTRUCT()
struct FPartyMemberCampaignHero
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString HeroItemInstanceId;

	UPROPERTY()
	TSoftObjectPtr<UFortHeroType> HeroType;

};

USTRUCT()
struct FPartyMemberCampaignInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 MatchmakingLevel;

	UPROPERTY()
	FString ZoneInstanceId;

	UPROPERTY()
	int64 HomeBaseVersion;

};

USTRUCT()
struct FPartyMemberScratchEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 T;

	UPROPERTY()
	int32 V;

};

USTRUCT()
struct FPartyMemberCosmeticLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<UAthenaCharacterItemDefinition> CharacterDef;

	UPROPERTY()
	FString CharacterEKey;

	UPROPERTY()
	TSoftObjectPtr<UAthenaBackpackItemDefinition> BackpackDef;

	UPROPERTY()
	FString BackpackEKey;

	UPROPERTY()
	TSoftObjectPtr<UAthenaPickaxeItemDefinition> PickaxeDef;

	UPROPERTY()
	FString PickaxeEKey;

	UPROPERTY()
	TSoftObjectPtr<UAthenaSkyDiveContrailItemDefinition> ContrailDef;

	UPROPERTY()
	FString ContrailEKey;

	UPROPERTY(Transient)
	TArray<FMcpVariantChannelInfo> CosmeticVariants;

	UPROPERTY()
	TArray<FPartyMemberScratchEntry> Scratchpad;

	UPROPERTY()
	TArray<FFortCosmeticStatEntry> CosmeticStats;

};

USTRUCT()
struct FPartyMemberFrontEndMapMarker
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector2D MarkerLocation;

	UPROPERTY()
	bool bIsSet;

};

USTRUCT()
struct FPartyMemberFrontendEmote
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSoftObjectPtr<UFortMontageItemDefinitionBase> EmoteItemDef;

	UPROPERTY()
	FString EmoteEKey;

	UPROPERTY()
	int8 EmoteSection;

};

USTRUCT()
struct FPartyMemberLobbyState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortPartyMemberReadyCheckStatus InGameReadyCheckStatus;

	UPROPERTY()
	EGameReadiness GameReadiness;

	UPROPERTY()
	ECommonInputType ReadyInputType;

	UPROPERTY()
	ECommonInputType CurrentInputType;

	UPROPERTY()
	int32 HiddenMatchmakingDelayMax;

	UPROPERTY()
	bool HasPreloadedAthena;

};

USTRUCT()
struct FPartyMemberPackedState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	ESubGame SubGame;

	UPROPERTY()
	EFortPartyMemberLocation Location;

	UPROPERTY()
	EFortPartyMemberInGameMode GameMode;

	UPROPERTY()
	EPartyMemberVoiceChatStatus VoiceChatStatus;

	UPROPERTY()
	bool HasCompletedSTWTutorial;

	UPROPERTY()
	bool HasPurchasedSTW;

	UPROPERTY()
	bool PlatformSupportsSTW;

	UPROPERTY()
	bool bReturnToLobbyAndReadyUp;

	UPROPERTY()
	bool bAnyoneChangeSelectedExperience;

	UPROPERTY()
	bool bDownloadOnDemandActive;

	UPROPERTY()
	bool bIsPartyLFG;

	UPROPERTY()
	bool bShouldRecordPartyChannel;

	UPROPERTY()
	bool bReadyForTravel;

	UPROPERTY()
	bool bIsInAllSelectExperiment;

};

USTRUCT()
struct FPartyMemberSharedQuestInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Qst;

	UPROPERTY()
	TArray<int32> Objs;

};

USTRUCT()
struct FPartyMemberBucketData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPartyMemberSharedQuestInfo> Qsts;

};

USTRUCT()
struct FPartyMemberSharedQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FPartyMemberBucketData> BcktMap;

	UPROPERTY()
	FString PndQst;

};

USTRUCT()
struct FPartyMemberSpectateInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GameSessionId;

	UPROPERTY()
	FString GameSessionKey;

};

USTRUCT()
struct FPartyMemberSquadAssignmentRequest
{
	GENERATED_BODY()

private:
	UPROPERTY()
	int32 StartingAbsoluteIdx;

	UPROPERTY()
	int32 TargetAbsoluteIdx;

	UPROPERTY()
	FUniqueNetIdRepl SwapTargetMemberId;

	UPROPERTY()
	uint8 Version;

};

USTRUCT()
struct FPartyVariantRep
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString c;

	UPROPERTY()
	FString v;

	UPROPERTY()
	int32 dE;

};

USTRUCT()
struct FNestedPartyVariantRep
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FPartyVariantRep> i;

};

USTRUCT()
struct FPartyMemberVariantCache
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TMap<EFortItemType, FNestedPartyVariantRep> vL;

	UPROPERTY()
	bool fT;

};

USTRUCT()
struct FFortPartyMemberRepData : public FPartyMemberRepData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FIslandRepData CurrentIsland;

	UPROPERTY()
	FOnlineLinkId SuggestedLink;

	UPROPERTY()
	FPartyMemberSpectateInfo SpectateInfo;

	UPROPERTY()
	FPartyMemberPackedState PackedState;

	UPROPERTY()
	FPartyMemberCampaignHero CampaignHero;

	UPROPERTY()
	FPartyMemberCampaignInfo CampaignInfo;

	UPROPERTY()
	FPartyMemberFrontendEmote FrontendEmote;

	UPROPERTY()
	uint8 NumAthenaPlayersLeft;

	UPROPERTY()
	FDateTime UtcTimeStartedMatchAthena;

	UPROPERTY()
	FPartyMemberLobbyState LobbyState;

	UPROPERTY()
	TObjectPtr<UFortFeatItemDefinition> FeatDefinition;

	UPROPERTY()
	FPartyMemberSquadAssignmentRequest MemberSquadAssignmentRequest;

	UPROPERTY()
	FPartyMemberFrontEndMapMarker FrontEndMapMarker;

	UPROPERTY()
	FPartyMemberCosmeticLoadout AthenaCosmeticLoadout;

	UPROPERTY()
	FPartyMemberVariantCache AthenaCosmeticLoadoutVariants;

	UPROPERTY()
	TArray<FString> ArbitraryCustomDataStore;

	UPROPERTY()
	FPartyMemberAthenaBannerInfo AthenaBannerInfo;

	UPROPERTY()
	FPartyMemberBattlePassInfo BattlePassInfo;

	UPROPERTY()
	FPartyMemberSharedQuestData SharedQuests;

	UPROPERTY()
	float DownloadOnDemandProgress;

	UPROPERTY()
	bool bIsPartyUsingPartySignal;

	UPROPERTY()
	FFortCommonMatchmakingData_Participant FortCommonMatchmakingData;

	UPROPERTY()
	FFortMatchmakingMemberData_Participant FortMatchmakingMemberData;

};

UCLASS(MinimalAPI)
class UFortPartyMember : public UPartyMember
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FFortPartyMemberRepData MemberRepData;

};

