// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Items/AthenaSeasonBattlePassOffer.h"
#include "Items/AthenaSeasonItemPageTypes.h"
#include "Items/ItemPreviewTypes.h"
#include "AthenaSeasonItemRewardEntry.generated.h"

class UAthenaSeasonItemEntryBase;
class UFortChallengeBundleItemDefinition;
class UFortChallengeBundleScheduleDefinition;
class UFortItemDefinition;
class UFortQuestItemDefinition;
class UObject;

USTRUCT()
struct FAthenaSeasonLandingPageData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonLandingPageData")
	FVaultWorldBackgroundData PaidPassPageBackgroundData;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonLandingPageData")
	FVaultWorldBackgroundData FreePassPageBackgroundData;

};

USTRUCT()
struct FAthenaSeasonPageGrid
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	FText CustomGridName;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	int32 LevelsNeededForUnlock;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	int32 RewardsNeededForUnlock;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	bool bForceTimeLock;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid", meta=(EditCondition="bForceTimeLock", EditConditionHides))
	int32 DelayDaysSinceSeasonStart;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	FIntPoint GridSize;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	bool bOverrideZoomLevel;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	bool bIsPrmTracked;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid", meta=(ClampMax="1.000000", ClampMin="0.000000"))
	float ZoomLevel;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	bool bHasCoverPage;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid", meta=(EditCondition="bHasCoverPage", EditConditionHides, MultiLine="true"))
	FText CoverPageTitle;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid", meta=(EditCondition="bHasCoverPage", EditConditionHides, MultiLine="true"))
	FText CoverPageDescription;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	TMap<FName, FLinearColor> RewardTileColors;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	FLinearColor RewardTileOverlayDimColor;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="AthenaSeasonPageGrid")
	TArray<TObjectPtr<UAthenaSeasonItemEntryBase>> RewardEntryList;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid", meta=(ArrayClamp="RewardEntryList"))
	int32 DefaultFocusWidgetIndex;

	UPROPERTY(EditDefaultsOnly, Category="AthenaSeasonPageGrid")
	FVaultWorldBackgroundData PageBackgroundData;

};

USTRUCT()
struct FQuestDisplayInfo
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FRewardPreviewParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bHide3DPreview;

protected:
	UPROPERTY(VisibleAnywhere, Category="RewardPreviewParams")
	TObjectPtr<UFortItemDefinition> ItemDefWeWishToView;

	UPROPERTY(VisibleAnywhere, Category="RewardPreviewParams")
	TObjectPtr<UFortItemDefinition> OriginalItemDef;

	UPROPERTY(VisibleAnywhere, Category="RewardPreviewParams")
	EAthenaRewardVisualImportanceType RewardImportanceType;

	UPROPERTY(VisibleAnywhere, Category="RewardPreviewParams")
	int32 Quantity;

	UPROPERTY(VisibleAnywhere, Category="RewardPreviewParams")
	TArray<FMcpVariantChannelInfo> VariantsToApply;

};

USTRUCT(BlueprintType)
struct FRewardPreviewInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="RewardPreviewInfo")
	FRewardPreviewParams PreviewParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RewardPreviewInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> PreviewIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="RewardPreviewInfo")
	float CycleTimeOverride;

};

UCLASS(Abstract, DefaultToInstanced, EditInlineNew, MinimalAPI)
class UAthenaSeasonItemEntryBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	bool bTreatOwnedAsClaimed;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	EPageItemTileSize TileSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> CustomButtonIcon;

	UPROPERTY(EditDefaultsOnly, Category="PRM")
	bool bIsPRMTracked;

	UPROPERTY(EditDefaultsOnly, Category="PRM")
	FString PRMOwnedParamName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delay", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> DelayedFakeButtonIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delay")
	FAthenaRewardItemReference DelayedFakeRewardItem;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	EBackgroundIntensityLevel BackgroundIntensityLevel;

	UPROPERTY(EditDefaultsOnly, Category="Preview")
	bool bHide3DPreview;

protected:
	UPROPERTY(EditAnywhere, EditFixedSize, Category="Preview")
	TArray<FRewardPreviewInfo> BattlePassPreviewInfoList;

	UPROPERTY(EditAnywhere, EditFixedSize, Category="Preview")
	TArray<FRewardPreviewInfo> DelayedBattlePassPreviewInfoList;

};

UCLASS(Abstract, MinimalAPI)
class UAthenaSeasonItemEntryOfferBase : public UAthenaSeasonItemEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	FAthenaBattlePassOffer BattlePassOffer;

};

UCLASS(MinimalAPI, meta=(DisplayName="Quest"))
class UAthenaSeasonItemEntryQuest : public UAthenaSeasonItemEntryBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(DisplayName="DEPRECATEDQuestBundleOrSchedule"))
	FAthenaRewardItemReference QuestItem;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(DisplayName="ChallengeBundleSchedule"))
	TSoftObjectPtr<UFortChallengeBundleScheduleDefinition> ChallengeScheduleSoftObjPtr;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(DisplayName="ChallengeBundle"))
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> ChallengeBundleSoftObjPtr;

	UPROPERTY(EditDefaultsOnly, Category="Data", meta=(DisplayName="Quest"))
	TSoftObjectPtr<UFortQuestItemDefinition> SpecificQuestItem;

	UPROPERTY(EditDefaultsOnly, Category="Data")
	TSoftObjectPtr<UFortQuestItemDefinition> OverrideProgressableQuest;

};

UCLASS(MinimalAPI, meta=(DisplayName="Reward"))
class UAthenaSeasonItemEntryReward : public UAthenaSeasonItemEntryOfferBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Data")
	bool bIsFreePassReward;

	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	int32 RewardsNeededForUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	int32 TotalRewardsNeededForUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	int32 NeededLevelsToUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	TArray<TSoftObjectPtr<UFortItemDefinition>> RequiredItems;

	UPROPERTY(EditDefaultsOnly, Category="Unlock", meta=(DisplayName="DEPRECATEDLockingBundleOrSchedule"))
	TSoftObjectPtr<UFortItemDefinition> LockingQuest;

	UPROPERTY(EditDefaultsOnly, Category="Unlock", meta=(DisplayName="LockingChallengeBundleSchedule"))
	TSoftObjectPtr<UFortChallengeBundleScheduleDefinition> LockingChallengeScheduleSoftObjPtr;

	UPROPERTY(EditDefaultsOnly, Category="Unlock", meta=(DisplayName="LockingChallengeBundle"))
	TSoftObjectPtr<UFortChallengeBundleItemDefinition> LockingChallengeBundleSoftObjPtr;

	UPROPERTY(EditDefaultsOnly, Category="Unlock")
	TSoftObjectPtr<UFortQuestItemDefinition> LockingSpecificQuest;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delay", meta=(EditCondition="DelayDaysSinceSeasonStart == 0"))
	TObjectPtr<UFortChallengeBundleScheduleDefinition> DelayQuestSchedule;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Delay", meta=(EditCondition="DelayQuestSchedule == nullptr"))
	int32 DelayDaysSinceSeasonStart;

};

UCLASS(MinimalAPI, meta=(DisplayName="Spacer"))
class UAthenaSeasonItemEntrySpacer : public UAthenaSeasonItemEntryBase
{
	GENERATED_BODY()

};

