// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Timespan.h"
#include "LockedQuestData.generated.h"

class UFortQuestItemDefinition;
class UMaterialInstance;

UENUM(BlueprintType)
enum class ELockedWidgetDisplayQuantity : uint8
{
	ShowAll = 0,
	ShowNextOnly = 1,
};

UENUM(BlueprintType)
enum class ELockedWidgetUnlockType : uint8
{
	QuestDaysFromEventStart = 0,
	QuestChallengesCompleteUntilUnlocked = 1,
	BundleDaysFromEventStart = 2,
	PrerequisiteQuest = 3,
};

USTRUCT(BlueprintType)
struct FLockedQuestOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestOverrideData")
	FText DisplayText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestOverrideData")
	FText CategoryName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestOverrideData")
	TObjectPtr<UMaterialInstance> DisplayIcon;

};

USTRUCT(BlueprintType)
struct FLockedQuestConfigData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestConfigData")
	bool bShowLockedQuestWidgets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestConfigData", meta=(EditCondition="bShowLockedQuestWidgets"))
	ELockedWidgetDisplayQuantity DisplayQuantity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestConfigData", meta=(EditCondition="bShowLockedQuestWidgets"))
	bool bOnlyShowWithNoAvailableContent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestConfigData", meta=(EditCondition="bShowLockedQuestWidgets"))
	bool bShowRewards;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LockedQuestConfigData")
	FLockedQuestOverrideData OverrideData;

};

USTRUCT(BlueprintType)
struct FLockedQuestRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	FLockedQuestConfigData ConfigData;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	FGameplayTagContainer SourceTags;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	ELockedWidgetUnlockType UnlockType;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	int64 UnlockNumber;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	TObjectPtr<UFortQuestItemDefinition> UnlockQuest;

	UPROPERTY(Transient)
	int64 UnlockUID;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	FTimespan UnlockTime;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	FString EventName;

	UPROPERTY(BlueprintReadOnly, Category="LockedQuestRuntimeData")
	FLockedQuestOverrideData RuntimeOverrideData;

};

