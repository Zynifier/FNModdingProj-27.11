// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTypes.h"
#include "FortMatchmakingUtilityDataTypes.generated.h"

UENUM(BlueprintType)
enum class EFortTournamentAlertType : uint8
{
	Warning = 0,
	Info = 1,
};

USTRUCT(BlueprintType)
struct FAthenaPlaylistEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString PlaylistName;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString DisplayName;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString DisplaySubName;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString Violator;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	FString Image;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	TArray<FString> ExtraImages;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	int32 CropOffset;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	EFortMatchmakingTileStyle SpecialBorderId;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	bool bShowRevealAnimation;

	UPROPERTY(BlueprintReadOnly, Category="AthenaPlaylistEntry")
	bool bIsCMSDataHidden;

};

USTRUCT(BlueprintType)
struct FLeaderboardEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	FString LeaderboardId;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	FString LeaderboardName;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	FString DisplayedAlternativeTrackedStat;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	TArray<FString> DetailsPanelAlternativeTrackedStats;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	TArray<FString> MatchHistoryAlternativeTrackedStats;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	bool ShowDetailsPanel;

	UPROPERTY(BlueprintReadOnly, Category="LeaderboardEntry")
	bool bIsArena;

};

USTRUCT(BlueprintType)
struct FLatestLeaderboardData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LastModified;

	UPROPERTY()
	TArray<FLeaderboardEntry> Entries;

};

USTRUCT(BlueprintType)
struct FShowdownTournamentEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString TournamentDisplayId;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString TitleLine1;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString TitleLine2;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString ScheduleInfo;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PosterFrontImage;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PosterBackImage;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString FlavorDescription;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString DetailsDescription;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString ShortFormatTitle;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString LongFormatTitle;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString BackgroundTitle;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	int32 PinScoreRequirement;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PinEarnedText;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString BaseColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PrimaryColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString SecondaryColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString HighlightColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString TitleColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString ShadowColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString BackgroundLeftColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString BackgroundRightColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString BackgroundTextColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PosterFadeColor;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PlaylistTileImage;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString LoadingScreenImage;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString StyleInfoId;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString AlertText;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString SeriesPointLeaderboardName;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	FString PlaylistDescription;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	EFortTournamentAlertType AlertType;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentEntry")
	TArray<FText> RoundDisplayNames;

};

USTRUCT(BlueprintType)
struct FShowdownLatestTournamentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString LastModified;

	UPROPERTY()
	TMap<FString, FShowdownTournamentEntry> Entries;

};

