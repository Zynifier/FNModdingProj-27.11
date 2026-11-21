// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BattlePassTypes.generated.h"

UENUM(BlueprintType)
enum class EBattlePassCurrencyType : uint8
{
	BattleStar = 0,
	CustomSkin = 1,
	TOTAL_CURRENCIES = 2,
};

UENUM(BlueprintType)
enum class EBattlePassFeatures : uint8
{
	None = 0,
	BuyBattlePass = 1,
	GiftBattlePass = 2,
	BuySubscription = 3,
	ViewDetails = 4,
	WatchVideo = 5,
	ShowAbout = 6,
	PurchaseResources = 7,
};

UENUM(BlueprintType)
enum class EBattlePassRewardPrerequisiteType : uint8
{
	RewardCount = 0,
	RequiredItems = 1,
	Quest = 2,
	NeededLevels = 3,
	NONE = 4,
};

UENUM(BlueprintType)
enum class EBattlePassView : uint8
{
	None = 0,
	LandingPage = 1,
	RewardOverview = 2,
	ItemDetails = 3,
	BulkBuyRewards = 4,
	CharacterCustomizer = 5,
	BonusRewards = 6,
	Weekly = 7,
	Quests = 8,
};

UENUM(BlueprintType)
enum class ERewardPageType : uint8
{
	Reward = 0,
	Quest = 1,
	Bonus = 2,
	Customization = 3,
	Weekly = 4,
	MAX = 5,
};

USTRUCT()
struct FORTNITEUI_API FBattlePassShowRewardParams
{
	GENERATED_BODY()

};

USTRUCT()
struct FCycledItemPreviewSettings
{
	GENERATED_BODY()

};

