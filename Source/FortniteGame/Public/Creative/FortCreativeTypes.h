// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "OnlineLinkId.h"
#include "FortCreativeTypes.generated.h"

class AFortVolume;
enum class ESpatialLoadingState : uint8;

UENUM(BlueprintType)
enum class ECreativePublishedIslandCodeDisplay : uint8
{
	Off = 0,
	ShowWithWatermark = 1,
	ShowWithoutWatermark = 2,
};

UENUM()
enum class EMMSPlayersPerTeamPreset : uint8
{
	Solos = 1 UMETA(DisplayName="1"),
	Duos = 2 UMETA(DisplayName="2"),
	Trios = 3 UMETA(DisplayName="3"),
	Squads = 4 UMETA(DisplayName="4"),
	SplitEvenly = 5,
	Dynamic = 6,
};

UENUM(BlueprintType)
enum class EMMSPrivacy : uint8
{
	Public = 0,
	// The island is public and its code can be used by anyone

	Private = 1,
};

UENUM()
enum class EMMSRulePreset : uint8
{
	RespectParties = 0,
	// Fill server before game start, respect team requirements, keep parties together

	KeepFull = 1 UMETA(DisplayName="Flexible Teams"),
	// Backfill server, respect team requirements, split parties

	Off = 2,
};

UENUM()
enum class EMMSTeamFillOption : uint8
{
	PartyChoice = 0,
	MustFill = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVolumeStateChanged, ESpatialLoadingState, NewState, AFortVolume*, Volume);

USTRUCT(BlueprintType)
struct FCreativeIslandData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	FString McpId;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	FText IslandName;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	FOnlineLinkId IslandCode;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	FDateTime LastLoadedDate;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	FDateTime DeletedAt;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	bool bIsDeleted;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandData")
	bool bIsVKProject;

};

USTRUCT(BlueprintType)
struct FCreativeIslandDescriptionTag
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandDescriptionTag")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandDescriptionTag")
	FText DisplayText;

};

USTRUCT(BlueprintType)
struct FCreativeIslandInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CreativeIslandInfo")
	FString IslandTitle;

	UPROPERTY(BlueprintReadWrite, Category="CreativeIslandInfo")
	FString IslandIntroduction;

	UPROPERTY()
	FString UserLocale;

	UPROPERTY()
	bool bUseLegacyPublish;

};

USTRUCT(BlueprintType)
struct FCreativeIslandMatchmakingSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 MinimumNumberOfPlayers;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 MaximumNumberOfPlayers;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	FString MmsType;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	FString MmsPrivacy;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	FString Override_Playlist;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 PlayerCount;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 NumberOfTeams;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 PlayersPerTeam;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	bool bAllowJoinInProgress;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	int32 SelectedJoinInProgressType;

	UPROPERTY(BlueprintReadOnly, Category="CreativeIslandMatchmakingSettings")
	uint8 JoinInProgressTeam;

};

USTRUCT(BlueprintType)
struct FCreativePublishOptions
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	FString UserTitle;

	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	FString UserDescription;

	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	TArray<FString> DescriptionTags;

	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	bool bActivateLink;

	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	bool bClearPersistentData;

	UPROPERTY(BlueprintReadWrite, Category="CreativePublishOptions")
	bool bUseLegacyPublish;

	UPROPERTY()
	FString UserLocale;

};

