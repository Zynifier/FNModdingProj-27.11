// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/ChallengeGiftBoxData.h"
#include "FortReleaseVersion.h"
#include "Items/FortAccountItemDefinition.h"
#include "Quests/LockedQuestData.h"
#include "FortChallengeBundleScheduleDefinition.generated.h"

class UFortChallengeBundleItemDefinition;
class UUserWidget;

UENUM(BlueprintType)
enum class EChallengeScheduleUnlockType : uint8
{
	// Unlocked manually via other means

	Manually = 0,
	// Unlock as soon as the schedule is granted

	OnScheduleGranted = 1,
	// Unlocked a certain number of days after the associated event has started

	DaysSinceEventStart = 2,
};

USTRUCT(BlueprintType)
struct FFortChallengeBundleScheduleEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleScheduleEntry")
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> ChallengeBundle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleScheduleEntry")
	EChallengeScheduleUnlockType UnlockType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortChallengeBundleScheduleEntry")
	int32 UnlockValue;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleScheduleEntry")
	FFortReleaseVersion ChallangeMinBuild;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortChallengeBundleScheduleEntry")
	FChallengeGiftBoxData GiftBox;
#endif

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "OwnedTags", "InventoryLimit", "Rating", "Functionality"))
class UFortChallengeBundleScheduleDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	bool DoesChallengeBundleScheduleExpire() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	TArray<UFortChallengeBundleItemDefinition*> GetBundleDefinitions() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	FString GetCalendarEventName() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	FString GetEventName(bool bGetExpirationEvent = false) const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	int32 GetNumBundles() const;

	UFUNCTION(BlueprintPure, Category="ChallengeBundleSchedule")
	int32 GetSortPriority() const;

private:
	UPROPERTY(EditAnywhere, Category="ChallengeBundleSchedule")
	TArray<FFortChallengeBundleScheduleEntry> ScheduleEntries;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	FString CalendarEventTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	FString CalendarEventName;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	bool bUseSeasonEventForExpiration;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule", meta=(Categories="ChallengeDetails"))
	bool bHideInLegacyAllChallengesEscapeMenu;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	bool bSeperateEachBundleForDisplay;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	bool bHideCountdownFromMapChallenges;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	FGameplayTag RequiredMcpContextTags;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="ChallengeBundleSchedule")
	FChallengeGiftBoxData GrantedBundleGiftBox;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	bool CleanUpOnBundleCompletion;
#endif

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule", meta=(Categories="ChallengeCategory"))
	FGameplayTag CategoryTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule", meta=(Categories="ChallengeDetails"))
	FGameplayTag ChallengeDetailsTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule", meta=(Categories="Schedule.Source"))
	FGameplayTag SourceTag;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	int32 SortPriority;

	UPROPERTY(EditDefaultsOnly, Category="ChallengeBundleSchedule")
	FText UnlockTextOverride;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<TSoftClassPtr<UUserWidget>> CustomChallengeHeaderExtensions;

	UPROPERTY(EditAnywhere, Category="Locked Quests")
	FLockedQuestConfigData LockedQuestConfigData;

};

