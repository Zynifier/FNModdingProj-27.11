// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "CatalogTypes.h"
#include "Online/FortPlaylistCuratedContent.h"
#include "OnlineLinkId.h"
#include "FortSeasonalEventManager.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActiveEventFlagsChanged, const TArray<FString>&, ActiveEventFlags);

USTRUCT()
struct FFortRotationalContentEventsState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<FName> ActiveStorefronts;

	UPROPERTY()
	TSet<FName> ActiveEventFlags;

	UPROPERTY()
	TMap<FName, double> EventNamedWeights;

	UPROPERTY()
	TSet<FDateTime> ExpirationTimes;

};

USTRUCT()
struct FFortClientEventsState : public FFortRotationalContentEventsState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 SeasonNumber;

	UPROPERTY()
	FString SeasonTemplateId;

private:
	UPROPERTY()
	float MatchXpBonusPoints;

	UPROPERTY()
	FDateTime SeasonBegin;

	UPROPERTY()
	FDateTime SeasonEnd;

	UPROPERTY()
	FDateTime SeasonDisplayedEnd;

	UPROPERTY()
	FDateTime WeeklyStoreEnd;

	UPROPERTY()
	FDateTime DailyStoreEnd;

	UPROPERTY()
	FDateTime StwDailyStoreEnd;

	UPROPERTY()
	FDateTime StwEventStoreEnd;

	UPROPERTY()
	FDateTime StwWeeklyStoreEnd;

	UPROPERTY()
	TMap<FName, FDateTime> SectionStoreEnds;

};

USTRUCT()
struct FFortCommunityVotesState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ElectionId;

	UPROPERTY()
	TArray<FCatalogOffer> Candidates;

	UPROPERTY()
	FDateTime ElectionEnds;

	UPROPERTY()
	int32 NumWinners;

	UPROPERTY()
	int32 WinnerStateHours;

};

USTRUCT()
struct FFortCrewTemporaryItemsState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> AvailableItems;

	UPROPERTY()
	FDateTime AvailableItemsEnd;

	UPROPERTY()
	TArray<FString> NextAvailableItems;

};

USTRUCT()
struct FFortFeaturedIslandsState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FOnlineLinkId> IslandCodes;

	UPROPERTY()
	TMap<FString, FFortPlaylistCuratedContent> PlaylistCuratedContent;

	UPROPERTY()
	TMap<FString, FString> PlaylistCuratedHub;

	UPROPERTY()
	TArray<FOnlineLinkId> IslandTemplates;

};

USTRUCT()
struct FFortMatchmakingRegionState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<FName> EventFlagsForcedOn;

	UPROPERTY()
	TSet<FName> EventFlagsForcedOff;

};

USTRUCT()
struct FFortMatchmakingEventsState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FString, FFortMatchmakingRegionState> Region;

};

USTRUCT()
struct FFortStandaloneStoreState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FDateTime StoreEnd;

};

USTRUCT()
struct FFortTimedKeysState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FString> K;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortSeasonalEventManager : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetBRXPBonusPoints() const;

	UFUNCTION(BlueprintPure, Category="Quests")
	bool IsEventFlagActive(const FString& QueriedEventFlagName) const;

	UPROPERTY(BlueprintAssignable, Category="Quests")
	FOnActiveEventFlagsChanged OnActiveEventFlagsChanged;

};

