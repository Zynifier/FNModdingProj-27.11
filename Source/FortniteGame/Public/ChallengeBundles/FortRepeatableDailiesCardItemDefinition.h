// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "ScalableFloat.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortRepeatableDailiesCardItemDefinition.generated.h"

class UFortAthenaRewardEventGraphPurchaseToken;
class UFortQuestItemDefinition;

USTRUCT()
struct FFortDailyQuestData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	FString GranterQuestPack;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	FString Group;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	int32 Count;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	TArray<FString> Playlists;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	bool bShouldBackfill;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData", meta=(EditCondition="bShouldBackfill", EditConditionHides))
	bool bQuestsDontExpire;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	bool bShouldGrantRestXP;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	FString CalendarEventName;

	UPROPERTY(EditAnywhere, Category="FortDailyQuestData")
	float EmptyQuestWeight;

};

USTRUCT()
struct FRepeatableDailiesCardDateOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="RepeatableDailiesCardDateOverride")
	TSoftObjectPtr<UFortQuestItemDefinition> Quest;

	UPROPERTY(EditAnywhere, Category="RepeatableDailiesCardDateOverride")
	FDateTime Start;

	UPROPERTY(EditAnywhere, Category="RepeatableDailiesCardDateOverride")
	FDateTime End;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "FortItemDefinition", "InventoryLimit", "Rating", "Functionality", "Frontend"))
class UFortRepeatableDailiesCardItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Repeatable Dailies")
	FScalableFloat ReplacedRestedXpValue;

	UPROPERTY(EditAnywhere, Category="Repeatable Dailies")
	FScalableFloat ReducedXPReward;

	UPROPERTY(EditAnywhere, Category="Repeatable Dailies")
	FScalableFloat ReplacedRestedXpValueScalarForMissedDays;

	UPROPERTY(EditDefaultsOnly, Category="FortRepeatableDailiesCardItemDefinition")
	TSoftObjectPtr<UFortAthenaRewardEventGraphPurchaseToken> RequiredItemDef;

	UPROPERTY(EditAnywhere, Category="Repeatable Dailies")
	TArray<FRepeatableDailiesCardDateOverride> DateOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Repeatable Dailies")
	TArray<FFortDailyQuestData> DailyQuestInfo;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Repeatable Dailies")
	bool bReplenishDailyQuests;
#endif

};

