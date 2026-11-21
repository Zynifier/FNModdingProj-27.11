// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortQuestGlobals.generated.h"

USTRUCT()
struct FChallengeObjectiveCountHotifx
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Quest;

	UPROPERTY()
	int32 Count;

};

USTRUCT()
struct FChallengeObjectiveHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Quest;

	UPROPERTY()
	FName Stat;

	UPROPERTY()
	int32 Count;

	UPROPERTY()
	int32 NewCount;

};

USTRUCT()
struct FChallengeSuppressedHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Quest;

	UPROPERTY()
	bool bSuppressed;

	UPROPERTY()
	FName Replacing;

	UPROPERTY()
	bool bCopyExpiration;

};

USTRUCT()
struct FDiscoverPOIIncrementCountHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTag POITag;

	UPROPERTY()
	int32 Count;

};

USTRUCT()
struct FIslandCodeHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString QuestTemplateID;

	UPROPERTY()
	FString NewIslandCode;

	UPROPERTY()
	FName PlaylistName;

};

USTRUCT()
struct FXPEventEntryHotfix
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Entry;

	UPROPERTY()
	int32 CountThreshhold;

	UPROPERTY()
	int32 MaxCount;

};

UCLASS(Config=game)
class FORTNITEGAME_API UFortQuestGlobals : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortQuestGlobals")
	static bool IsNonBusrideChallengeVOHotfixedOff(const FGameplayTagContainer& ChallengeAssetTags);

	UPROPERTY(Config)
	TArray<FChallengeObjectiveHotfix> ChallengeObjectiveHotfixes;

	UPROPERTY(Config)
	TArray<FChallengeSuppressedHotfix> ChallengeSuppressedHotfixes;

	UPROPERTY(Config)
	TArray<FChallengeObjectiveCountHotifx> ChallengeObjectiveCountHotfixes;

	UPROPERTY(Config)
	TArray<FDiscoverPOIIncrementCountHotfix> DiscoverPOIIncrementCountHotfixes;

	UPROPERTY(Config)
	TArray<FString> NonBusrideChallengeVOHotfixes;

	UPROPERTY(Config)
	TArray<FString> BusrideChallengeVOHotfixes;

	UPROPERTY(Config)
	TArray<FXPEventEntryHotfix> XPEventEntryHotfixes;

	UPROPERTY(Config)
	TArray<FIslandCodeHotfix> IslandCodeTemplateOverrides;

	UPROPERTY(Config)
	bool bEnableQuestContentCheckOnSave;

	UPROPERTY(Config)
	bool bEnableSeasonalQuestline;

};

