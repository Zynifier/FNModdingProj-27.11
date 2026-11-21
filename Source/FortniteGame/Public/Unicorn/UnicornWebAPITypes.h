// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Misc/DateTime.h"
#include "FortDeathCauseEnum.h"
#include "Items/FortItemTypeEnum.h"
#include "Replay/FortReplayTypes.h"
#include "Unicorn/Social/UnicornSocialTypes.h"
#include "Unicorn/UnicornTypes.h"
#include "UnicornWebAPITypes.generated.h"

USTRUCT()
struct FCosmeticLoadoutPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EFortItemType, FString> UCRN_CharacterVarients;

};

USTRUCT()
struct FUnicornSocialMetaPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<EUnicornSocialFeatures, float> UCRN_FeatureScores;

	UPROPERTY()
	TSet<FUniqueNetIdRepl> UCRN_FriendsInvolved;

	UPROPERTY()
	float UCRN_SocialScore;

};

USTRUCT()
struct FVictimGameplayInfoPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<EDeathCause> UCRN_DeathCauses;

	UPROPERTY()
	TSet<FString> UCRN_VictimTags;

	UPROPERTY()
	TSet<FString> UCRN_KillerTags;

	UPROPERTY()
	TSet<FString> UCRN_DeathTags;

};

USTRUCT()
struct FHighlightClipPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 UCRN_HighlightId;

	UPROPERTY()
	float UCRN_StartTimestamp;

	UPROPERTY()
	float UCRN_Duration;

	UPROPERTY()
	TMap<EHighlightFeatures, float> UCRN_GameplayFeatures;

	UPROPERTY()
	float UCRN_GameplayScore;

	UPROPERTY()
	FUnicornSocialMetaPayload UCRN_SocialMeta;

	UPROPERTY()
	float UCRN_NetworkingFidelityAverage;

	UPROPERTY()
	TArray<FString> UCRN_POITags;

	UPROPERTY()
	FVictimGameplayInfoPayload UCRN_FollowingPlayerKill_VictimGameplayInfo;

	UPROPERTY()
	FVictimGameplayInfoPayload UCRN_FollowingPlayerDeath_VictimGameplayInfo;

	UPROPERTY()
	TMap<FString, FString> UCRN_UnicornTags;

};

USTRUCT()
struct FHighlightReelPlayerInfoPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FCosmeticLoadoutPayload UCRN_CosmeticInfo;

};

USTRUCT()
struct FHighlightReelPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl UCRN_PlayerId;

	UPROPERTY()
	FString UCRN_PlayerName;

	UPROPERTY()
	int32 UCRN_MMR;

	UPROPERTY()
	FHighlightReelPlayerInfoPayload UCRN_PlayerInfo;

	UPROPERTY()
	EHighlightReelIds UCRN_HighlightReelId;

	UPROPERTY()
	TArray<FHighlightClipPayload> UCRN_Clips;

};

USTRUCT()
struct FHighlightsPayloadMeta
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString UCRN_ReplayId;

	UPROPERTY()
	FString UCRN_BuildVersion;

	UPROPERTY()
	FString UCRN_McpDeployment;

	UPROPERTY()
	uint8 UCRN_PayloadVersion;

	UPROPERTY()
	FDateTime UCRN_GenerationDate;

	UPROPERTY()
	FString UCRN_McpBackendEnvironment;

	UPROPERTY()
	FString UCRN_McpAppName;

	UPROPERTY()
	FString UCRN_McpGameBackendName;

	UPROPERTY()
	FString UCRN_PlaylistName;

	UPROPERTY()
	bool UCRN_bIsCustomMatch;

};

USTRUCT()
struct FHighlightsPayload
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FHighlightsPayloadMeta UCRN_Meta;

	UPROPERTY()
	TArray<FHighlightReelPayload> UCRN_HighlightReels;

};

