// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeTypes.h"
#include "DynamicXp/FortDynamicXpCalculatorData.h"
#include "FortLocalizationServiceTypes.h"
#include "Online/FortMatchmakingPublicConfig.h"
#include "OnlineLinkId.h"
#include "OnlineLinkModerationStatus.h"
#include "FortCreativeLoadedLinkData.generated.h"

UENUM()
enum class ECreativeLinkPreviewSize : uint8
{
	Small = 0,
	Medium = 1,
	Large = 2,
	Extra_Small = 3,
	NUM_SIZES = 4,
};

USTRUCT(BlueprintType)
struct FCreativeLoadedLinkData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString CreatorName;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString SupportCode;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FOnlineLinkId LinkId;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FOnlineLinkId BuildCodeLinkId;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString QueryIslandCode;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	EMMSPrivacy Privacy;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	TArray<FLocalizedStringPair> LinkTitle;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FText AltTitle;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	TArray<FLocalizedStringPair> LinkTagline;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	TArray<FString> DescriptionTags;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	TArray<FLocalizedStringPair> IslandIntroduction;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString ImageUrl;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString LobbyBackgroundUrl;

	UPROPERTY()
	FString IslandType;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString QuestContextTag;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString AccountId;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FCreativeIslandMatchmakingSettings MatchmakingSettings;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FFortMatchmakingPublicConfig MatchmakingV2Settings;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	TArray<FString> PlaylistOptions;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString LinkType;

	UPROPERTY(NotReplicated)
	TSet<FString> CreatorPermissions;

	UPROPERTY(NotReplicated)
	TSet<FString> CreatorEntitlements;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	EOnlineLinkModerationStatus ModerationStatus;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="CreativeLoadedLinkData")
	FDynamicXpAggregatedStats CreativeIslandXPStats;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FPublicDynamicXpStats PublicCreativeIslandXPStats;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	bool bActive;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString LinkMode;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString PlaytestGroupId;

	UPROPERTY(BlueprintReadOnly, Category="CreativeLoadedLinkData")
	FString ProjectId;

};

