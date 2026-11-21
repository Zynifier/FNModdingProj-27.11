// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ChallengeGiftBoxData.h"
#include "Cosmetics/Variants/FortCosmeticVariantInfo.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "AthenaRewardSchedule.generated.h"

class UFortItemDefinition;
class UMaterialInterface;
class UTexture2D;

UENUM(BlueprintType)
enum class EAthenaRewardItemType : uint8
{
	// Visible and exported to MCP

	Normal = 0,
	// This reward will not be shown anywhere in the UI (note: this is not a 'mystery' item, it is not shown at all), THIS IS STILL PLACED IN GIFTBOXES!

	HiddenReward = 1,
	// This reward will not be shown anywhere in the UI (note: this is not a 'mystery' item, it is not shown at all), THIS IS NOT PLACED IN GIFTBOXES!

	GiftboxHiddenReward = 2,
	// This reward is purely for UI display and will not be exported to MCP (typically used in conjunction with hidden rewards to show a merged entry for several hidden rewards)

	NonExportedFakeReward = 3,
};

UENUM(BlueprintType)
enum class EAthenaRewardVisualImportanceType : uint8
{
	// Rewards that are expected to not be the highlights of the battle pass

	Normal = 0,
	// Rewards that are expected to eye-grabbers

	Hot = 1,
	// Rewards that are expected to eye-grabbers and have new features

	CrazyHot = 2,
	// rewards that have new features

	Crazy = 3,
};

UENUM(BlueprintType)
enum class EAthenaSeasonRewardTrack : uint8
{
	Invalid = 0,
	// Rewards for account XP

	SeasonProgressionTrack = 1,
	// Rewards for book XP that everyone gets

	CompendiumFreeTrack = 2,
	// Rewards for book XP that are only granted if you have VIP status

	CompendiumPaidTrack = 3,
	// Rewards that are typically defined by challenges

	CompendiumAdditionalTrack = 4,
};

USTRUCT(BlueprintType)
struct FAdditionalVariantSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AdditionalVariantSet")
	TArray<FCosmeticVariantInfo> VariantsToApply;

};

USTRUCT(BlueprintType)
struct FAthenaRewardItemReference
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Data")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, Category="Data")
	FString TemplateId;

	UPROPERTY(EditAnywhere, Category="Data")
	int32 Quantity;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Data")
	FChallengeGiftBoxData RewardGiftBox;
#endif

	UPROPERTY(EditAnywhere, Category="Data")
	bool IsChaseReward;

	UPROPERTY(EditAnywhere, Category="Data")
	EAthenaRewardItemType RewardType;

	UPROPERTY(EditAnywhere, Category="Data")
	EAthenaRewardVisualImportanceType RewardVisualImportanceType;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FAdditionalVariantSet> PreviewVariantSets;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FMcpVariantChannelInfo> AdditionalPreviewVariants;

};

USTRUCT()
struct FAthenaRewardScheduleLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LevelUp")
	TArray<FAthenaRewardItemReference> Rewards;

};

USTRUCT()
struct FAthenaRewardSchedule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, EditFixedSize, Category="AthenaRewardSchedule")
	TArray<FAthenaRewardScheduleLevel> Levels;

};

USTRUCT(BlueprintType)
struct FAthenaSeasonBannerLevel
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	TSoftObjectPtr<UTexture2D> SurroundImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	TSoftObjectPtr<UMaterialInterface> BannerMaterial;

};

USTRUCT()
struct FAthenaSeasonBannerLevelSchedule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, EditFixedSize, Category="AthenaSeasonBannerLevelSchedule")
	TArray<FAthenaSeasonBannerLevel> Levels;

};

USTRUCT(BlueprintType)
struct FAthenaSeasonRewardLevelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AthenaSeasonRewardLevelInfo")
	EAthenaSeasonRewardTrack Track;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSeasonRewardLevelInfo")
	int32 Level;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSeasonRewardLevelInfo")
	int32 XpToNextLevel;

	UPROPERTY(BlueprintReadOnly, Category="AthenaSeasonRewardLevelInfo")
	TArray<FAthenaRewardItemReference> Rewards;

};

