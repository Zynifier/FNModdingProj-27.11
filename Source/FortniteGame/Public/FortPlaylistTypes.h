// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Creative/FortCreativeTypes.h"
#include "OnlineLinkId.h"
#include "FortPlaylistTypes.generated.h"

class UFortPlaylistAthena;

UENUM()
enum class EPlaylistAdvertisementType : uint8
{
	None = 0,
	New = 1,
	Updated = 2,
};

UENUM()
enum class EPlaylistVisibilityState : uint8
{
	Enabled = 1,
	Disabled = 2,
	//~ this is so that we can do ((int32)Visibility % 2) == 1 to check for being enabled
//~ and also to preserve ordering so that Visibility <= Disabled works as a check for "show to user".
//~ We need this so that we can have enabled playlists (bot fill) that don't appear in the
//~ actual menu.

	EnabledButInvisible = 3,
	//~ this is so that we can do ((int32)Visibility % 2) == 1 to check for being enabled
//~ and also to preserve ordering so that Visibility <= Disabled works as a check for "show to user".
//~ We need this so that we can have enabled playlists (bot fill) that don't appear in the
//~ actual menu.

	Hidden = 4,
};

USTRUCT()
struct FPlaylistAccess
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bForcePlaylistOff;

	UPROPERTY()
	bool bEnabled;

	UPROPERTY()
	bool bVisibleWhenDisabled;

	UPROPERTY()
	bool bInvisibleWhenEnabled;

	UPROPERTY()
	bool bIsDefaultPlaylist;

	UPROPERTY()
	EPlaylistAdvertisementType AdvertiseType;

	UPROPERTY()
	bool bDisplayAsLimitedTime;

	UPROPERTY()
	int32 DisplayPriority;

	UPROPERTY()
	int32 CategoryIndex;

};

USTRUCT()
struct FPlaylistAccessOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> Regions;

	UPROPERTY()
	TArray<FString> Platforms;

	UPROPERTY()
	FPlaylistAccess OverrideAccess;

};

USTRUCT()
struct FPlaylistData
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	FString TournamentId;

	UPROPERTY()
	FString EventWindowId;

	UPROPERTY()
	FOnlineLinkId LinkId;

	UPROPERTY()
	bool bGracefullyUpgraded;

	UPROPERTY()
	EMMSRulePreset MatchmakingRulePreset;

};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FPlaylistFrontEndData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	TWeakObjectPtr<UFortPlaylistAthena> WeakPlaylistData;

	UPROPERTY()
	EPlaylistVisibilityState Visibility;

	UPROPERTY()
	bool bDisplayAsDefault;

	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	EPlaylistAdvertisementType AdvertiseType;

	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	bool bDisplayAsLimitedTime;

	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	int32 CategoryIndex;

	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	FDateTime EndDateUTC;

	UPROPERTY(BlueprintReadOnly, Category="PlaylistFrontEndData")
	FOnlineLinkId LinkId;

};

USTRUCT()
struct FPlaylistFrontEndSettings
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	FPlaylistAccess PlaylistAccess;

	UPROPERTY()
	TArray<FPlaylistAccessOverride> AccessOverrides;

};

USTRUCT()
struct FPlaylistOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName PlaylistName;

	UPROPERTY()
	bool bEnabled;

	UPROPERTY()
	TArray<FString> RegionsDisabled;

};

