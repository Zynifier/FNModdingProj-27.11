// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaRewardSchedule.h"
#include "AthenaSeasonItemDefinitionTypes.generated.h"

class UAthenaDailyQuestDefinition;
class UFortItemDefinition;
class UFortQuestItemDefinition;
class UObject;

UENUM(BlueprintType)
enum class EBattlePassRewardSource : uint8
{
	None = 0,
	ChallengeBundle = 1,
	Quest = 2,
};

USTRUCT()
struct FAthenaMidSeasonUpdateItemReq
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdateItemReq")
	TSoftObjectPtr<UFortItemDefinition> Item;

	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdateItemReq")
	int32 Count;

};

USTRUCT()
struct FAthenaMidSeasonUpdateQuestReq
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdateQuestReq")
	TSoftObjectPtr<UFortQuestItemDefinition> Quest;

	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdateQuestReq")
	bool bCompletionRequired;

};

USTRUCT()
struct FAthenaMidSeasonUpdate
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="AthenaMidSeasonUpdate")
	FString Name;
#endif

	UPROPERTY(EditAnywhere, Category="Requirements")
	int32 SeasonLevelRequirement;

	UPROPERTY(EditAnywhere, Category="Requirements")
	int32 BookLevelRequirement;

	UPROPERTY(EditAnywhere, Category="Requirements")
	bool SeasonPurchasedRequirement;

	UPROPERTY(EditAnywhere, Category="Requirements")
	TArray<FAthenaMidSeasonUpdateItemReq> ItemRequirements;

	UPROPERTY(EditAnywhere, Category="Requirements")
	TArray<FAthenaMidSeasonUpdateQuestReq> QuestRequirements;

	UPROPERTY(EditAnywhere, Category="Changes")
	FAthenaRewardScheduleLevel Grants;

	UPROPERTY(EditAnywhere, Category="Changes")
	TArray<TSoftObjectPtr<UFortItemDefinition>> Removals;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="AthenaMidSeasonUpdate")
	int32 InsertionIndex;
#endif

};

USTRUCT()
struct FAthenaSuperChargedBonusQuestLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaSuperChargedBonusQuestLevel", meta=(ClampMax="1", ClampMin="0"))
	float PercentOfGoldenPath;

	UPROPERTY(EditAnywhere, Category="AthenaSuperChargedBonusQuestLevel", meta=(ClampMin="0"))
	int32 MinimumDaysSinceSeasonStart;

	UPROPERTY(EditAnywhere, Category="AthenaSuperChargedBonusQuestLevel")
	TSoftObjectPtr<UAthenaDailyQuestDefinition> BonusQuest;

};

USTRUCT()
struct FBattlePassRewardInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortItemDefinition> ItemDef;

	UPROPERTY()
	int32 Level;

	UPROPERTY()
	bool bIsFree;

	UPROPERTY()
	int32 QuantityRewarded;

	UPROPERTY()
	EBattlePassRewardSource UnlockableSource;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> UnlockableSourceItemDef;

};

USTRUCT(BlueprintType)
struct FTrackCategory
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="TrackCategory", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> CategoryIcon;

	UPROPERTY(EditAnywhere, Category="TrackCategory")
	FText CategoryName;

	UPROPERTY(EditAnywhere, Category="TrackCategory")
	int32 CategoryStartingLevel;

};

USTRUCT(BlueprintType)
struct FXpDisplayConversion
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="XpDisplayConversion")
	TSoftObjectPtr<UFortItemDefinition> XpItemDef;

	UPROPERTY(EditAnywhere, Category="XpDisplayConversion")
	int32 ValueToReplaceAt;

};

