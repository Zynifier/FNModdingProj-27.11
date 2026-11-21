// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/AthenaRewardSchedule.h"
#include "Items/AthenaSeasonItemDefinitionTypes.h"
#include "Items/FortAccountItemDefinition.h"
#include "AthenaSeasonItemDefinition.generated.h"

class UAthenaMidSeasonUpdatesDataAsset;
class UAthenaProfileItemsToRemoveAtSeasonEndDataAsset;
class UAthenaRewardScheduleLevelDataAsset;
class UAthenaSeasonItemData;
class UAthenaSeasonItemDefinition;
class UAthenaSeasonItemDefinitionSubDataAsset;
class UAthenaSuperChargedBonusQuestDataAsset;
class UDataAsset;
class UDataTable;
class UFortChallengeBundleItemDefinition;
class UFortChallengeBundleScheduleDefinition;
class UFortCollectionsDataTable;
class UFortGiftBoxItemDefinition;
class UFortItemDefinition;
class UFortMedalsPunchCardItemDefinition;
class UFortPersistentResourceItemDefinition;
class UFortPlayerAugmentsAccountItemDefinition;
class UFortRepeatableDailiesCardItemDefinition;
class UFortSharedQuestData;
class UFortTokenType;

USTRUCT(BlueprintType)
struct FSeasonCurrencyMcpData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SeasonCurrencyMcpData")
	TSoftObjectPtr<UFortPersistentResourceItemDefinition> CurrencyDefinition;

	UPROPERTY(EditDefaultsOnly, Category="SeasonCurrencyMcpData")
	FCurveTableRowHandle CurrencySeasonTotalCollectionLimit;

	UPROPERTY(EditDefaultsOnly, Category="SeasonCurrencyMcpData")
	TSoftObjectPtr<UFortGiftBoxItemDefinition> GiftBoxDefinition;

	UPROPERTY(EditDefaultsOnly, Category="SeasonCurrencyMcpData")
	TSoftObjectPtr<UFortGiftBoxItemDefinition> FriendChestGiftBoxDefinition;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Frontend", "Tooltips", "Functionality", "OwnedTags", "FortItemDefinition"))
class UAthenaSeasonItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure, Category="MidSeason")
	bool IsUsingMidSeasonUpdatesDataAsset() const;

	UFUNCTION(BlueprintPure, Category="EndOfSeason")
	bool IsUsingProfileItemsToRemoveAtSeasonEndDataAsset() const;

	UFUNCTION(BlueprintPure, Category="SeasonConfig")
	bool IsUsingSeasonGrantsToEveryoneDataAsset() const;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	bool bXpOnlySeason;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	bool bCapFreeBattlePassLevels;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	bool bUseSeasonCurveForBattlePassRewards;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false", RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaExtendedXPCurveEntry"))
	TObjectPtr<UDataTable> SeasonXpOnlyExtendedCurve;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UFortMedalsPunchCardItemDefinition> DailyPunchCard;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UFortRepeatableDailiesCardItemDefinition> RepeatableDailiesCard;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false", RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaDynamicRestedXpProgression"))
	TObjectPtr<UDataTable> RestedXpCatchupProgression;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false", RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaDynamicRestedXpGoldenPath"))
	TObjectPtr<UDataTable> RestedXpCatchupGoldenPath;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false", RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaReengagementRestedXp"))
	TObjectPtr<UDataTable> ReengagementRestXP;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TSoftObjectPtr<UAthenaSuperChargedBonusQuestDataAsset> SuperChargedBonusQuests;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TArray<TSoftObjectPtr<UFortChallengeBundleScheduleDefinition>> TutorialSchedulesToGrant;
#endif

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UFortPlayerAugmentsAccountItemDefinition> PlayerAugmentDefinition;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FString SeasonUICalendarEventTag;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	int32 SeasonStartCalendarOffsetDays;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	int32 SeasonNumber;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(ClampMax="1000", ClampMin="1"))
	int32 NumSeasonLevels;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	int32 SeasonLevelPurchaseMax;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false", RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaSeasonalXpCurveEntry"))
	TObjectPtr<UDataTable> SeasonXpCurve;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	FString SeasonStorefront;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	FString BattlePassOfferId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	FString BattlePassBundleOfferId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	FString BattlePassLevelOfferId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	int32 BattlePassLevelOffer_MaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	FString BattlePassLevelBundleOfferID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	int32 BattlePassLevelBundleOffer_MaxLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	int32 BattlePassLevelBundleOffer_NumLevels;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SeasonConfig", meta=(DisplayAfter="BattlePassOfferId"))
	FString BattlePassOfferId_CatalogDevName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SeasonConfig", meta=(DisplayAfter="BattlePassBundleOfferId"))
	FString BattlePassBundleOfferId_CatalogDevName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SeasonConfig", meta=(DisplayAfter="BattlePassLevelOfferId"))
	FString BattlePassLevelOfferId_CatalogDevName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SeasonConfig", meta=(DisplayAfter="BattlePassLevelBundleOfferID"))
	FString BattlePassLevelBundleOfferID_CatalogDevName;
#endif

	UPROPERTY(EditDefaultsOnly, Category="SeasonConfig")
	FCurveTableRowHandle LogFireRestXPCap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SeasonConfig")
	TArray<FPrimaryAssetId> FreeTokenItemPrimaryAssetIds;

	UPROPERTY(EditAnywhere, Category="HiddenProperties")
	FAthenaRewardSchedule SeasonXpScheduleFree;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FAthenaSeasonBannerLevelSchedule SeasonBannerSchedule;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UFortChallengeBundleItemDefinition> SeasonalGlyphChallengeBundle;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FString GlyphTokenTemplateId;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(DisplayThumbnail="false"))
	TObjectPtr<UDataTable> SeasonalGlyphRewards;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UFortChallengeBundleScheduleDefinition> ChallengeSchedulePaid;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TArray<TObjectPtr<UFortChallengeBundleScheduleDefinition>> ChallengeSchedulesAlwaysShown;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UAthenaRewardScheduleLevelDataAsset> SeasonGrantsToEveryoneDataAsset;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(EditCondition="SeasonGrantsToEveryoneDataAsset == nullptr"))
	FAthenaRewardScheduleLevel SeasonGrantsToEveryone;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FAthenaRewardScheduleLevel SeasonFirstWinRewards;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FAthenaRewardScheduleLevel BattleStarSubstitutionReward;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag FreeSeasonItemContentTag;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag SeasonGrantsToEveryoneItemContentTag;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(Categories="Cosmetics.Source"))
	FGameplayTag SeasonFirstWinItemContentTag;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TArray<FXpDisplayConversion> XpDisplayOverride;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TSoftObjectPtr<UFortItemDefinition> XpItemDef;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TSoftObjectPtr<UFortItemDefinition> LevelUpItemDef;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TArray<FSeasonCurrencyMcpData> SeasonCurrencyMcpDataList;

	UPROPERTY(EditAnywhere, Category="EndOfSeason")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ExpiringRewardTypes;

	UPROPERTY(EditAnywhere, Category="EndOfSeason")
	TObjectPtr<UAthenaProfileItemsToRemoveAtSeasonEndDataAsset> ProfileItemsToRemoveAtSeasonEndDataAsset;

	UPROPERTY(EditAnywhere, Category="EndOfSeason", meta=(DisplayName="ProfileItemsToRemoveAtSeasonEnd", EditCondition="ProfileItemsToRemoveAtSeasonEndDataAsset == nullptr"))
	TArray<TSoftObjectPtr<UFortItemDefinition>> TokensToRemoveAtSeasonEnd;

	UPROPERTY(EditAnywhere, Category="MidSeason", meta=(TitleProperty="Name"))
	TObjectPtr<UAthenaMidSeasonUpdatesDataAsset> MidSeasonUpdatesDataAsset;

	UPROPERTY(EditAnywhere, Category="MidSeason", meta=(EditCondition="MidSeasonUpdatesDataAsset == nullptr", TitleProperty="Name"))
	TArray<FAthenaMidSeasonUpdate> MidSeasonUpdates;

	UPROPERTY(EditAnywhere, Category="EndOfSeason")
	bool bRemoveAllDailyQuestsAtSeasonEnd;

	UPROPERTY(EditAnywhere, Category="EndOfSeason")
	bool bRemoveAllTransientQuestsAtSeasonEnd;

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(AssetBundles="MenuAthena"))
	TSoftObjectPtr<UFortTokenType> NoBattleBundleToken;

	UPROPERTY(EditAnywhere, Category="Collection", meta=(AssetBundles="MenuAthena,ServerAthena"))
	TSoftObjectPtr<UFortCollectionsDataTable> CollectionsDataTable;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	FGameplayTagContainer FirstTimeTrackedBitTagContainer;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="EndOfSeason")
	TArray<FString> TokensToRemoveWhitelist;
#endif

	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.NPCQuestRow"))
	TObjectPtr<UDataTable> NPCConversationQuests;

	UPROPERTY(EditDefaultsOnly, Category="SeasonConfig")
	TMap<FGameplayTag, TObjectPtr<UDataTable>> SeasonDataTables;

	UPROPERTY(EditDefaultsOnly, Category="SeasonConfig")
	TMap<FGameplayTag, TObjectPtr<UDataAsset>> SeasonDataAssets;

	UPROPERTY()
	TArray<FGameplayTag> FirstTimeTrackedBitFlags;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="AdditionalSeasonData")
	TArray<TObjectPtr<UAthenaSeasonItemData>> AdditionalSeasonData;

	UPROPERTY()
	FAthenaRewardSchedule BookXpScheduleFree_DEPRECATED;

	UPROPERTY()
	FGameplayTag BattlePassFreeItemContentTag_DEPRECATED;

	UPROPERTY()
	FAthenaRewardSchedule BookXpSchedulePaid_DEPRECATED;

	UPROPERTY()
	FGameplayTag BattlePassPaidItemContentTag_DEPRECATED;

	UPROPERTY()
	FAthenaRewardSchedule AdditionalBookSchedule_DEPRECATED;

	UPROPERTY()
	FGameplayTag BattlePassAdditionalItemContentTag_DEPRECATED;

	UPROPERTY()
	TArray<int32> FreeLevelsThatNavigateToBattlePass_DEPRECATED;

	UPROPERTY()
	TArray<FTrackCategory> TrackCategories_DEPRECATED;

	UPROPERTY()
	TObjectPtr<UDataTable> BookXpCurve_DEPRECATED;

	UPROPERTY()
	int32 NumBookLevels_DEPRECATED;

	UPROPERTY()
	int32 NumAdditionalBookLevels_DEPRECATED;

	UPROPERTY()
	TObjectPtr<UFortSharedQuestData> SharedQuestData;

private:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Exec, Category="Event", meta=(CallInEditor="true"))
	void CleanupScratchAssets();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Exec, Category="Event", meta=(CallInEditor="true"))
	UAthenaSeasonItemDefinition* NextSeasonCreate();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Exec, Category="Event", meta=(CallInEditor="true"))
	void NextSeasonPostCopy();
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Exec, Category="Event", meta=(CallInEditor="true"))
	void SaveScratchAssets(bool bIncludeSelf = true, bool bWaitForCompletion = true);
#endif

#if WITH_EDITOR
	UFUNCTION(Exec, Category="Event", meta=(CallInEditor="true"))
	void ShowBattlePassCurrenciesAndCosts() const;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="EndOfSeason")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ReferencesForAdvancedCopy;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaSeasonItemDefinitionSubDataAsset>> SeasonCopyScratchAssets;
#endif

};

