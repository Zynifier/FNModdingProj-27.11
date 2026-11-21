// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortGameData.h"
#include "FortItemQuantityPair.h"
#include "Items/FortQuickBars.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Items/FortStatCategoryEnum.h"
#include "UI/FrontEnd/FortPlayerSpawnPadPlacementData.h"
#include "GameDataSTW.generated.h"

class ABuildingFoundation;
class AFortAIDirector;
class AFortAIGoalManager;
class AFortAIPawn;
class AFortBluGloManager;
class AFortClientAnnouncement_Conversation;
class AFortConstructorBASE;
class AFortFeedbackManager;
class AFortInGameMapManager;
class AFortMusicManager;
class AFortPlayerPawn;
class AFortTheaterMapViewer;
class AFortThreatVisualsManager;
class AFortWindManager;
class UAthenaMusicPackItemDefinition;
class UCombatManagerComponentSTW;
class UCurveTable;
class UCustomCharacterPart;
class UDataTable;
class UFortAIEncounterInfo;
class UFortAbilitySet;
class UFortAccountItemDefinition;
class UFortAnalyticsItemExclusions;
class UFortCollectionBookData;
class UFortDailyRewardScheduleDefinitions;
class UFortHeroData;
class UFortHeroType;
class UFortHomebaseManager;
class UFortItemDefinition;
class UFortItemWrapMappingData;
class UFortMusicManagerBank;
class UFortNeverPersistItemDefinition;
class UFortOutpostData;
class UFortQuestItemDefinition;
class UFortQuestMapData;
class UFortScoreStylingData;
class UFortSharedMissionLists;
class UFortStatEventManager;
class UFortSurvivorData;
class UFortTeamPerkItemDefinition;
class UFortTimeOfDayData;
class UFortTokenType;
class UFortUIFeedbackBank;
class UFortUINotification;
class UFortWeaponMeleeItemDefinition;
class UFortWeaponReticleExtensionData;
class UFortWorldItemDefinition;
class UGameStateComponent;
class UGameplayEffect;
class UMyTownData;
class USoundBase;
class USoundMix;
class UUserWidget;

USTRUCT()
struct FConditionalFoundationQuotaTier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Data", meta=(AssetBundles="Client,Server"))
	TArray<TSoftClassPtr<ABuildingFoundation>> FoundationClasses;

	UPROPERTY(EditAnywhere, Category="Data")
	int32 MinFoundations;

	UPROPERTY(EditAnywhere, Category="Data")
	int32 MaxFoundations;

};

USTRUCT()
struct FConditionalFoundationQuota
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FConditionalFoundationQuotaTier> Tiers;

};

USTRUCT()
struct FDefaultCharacterPartsForPawnClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Defaults")
	FGameplayTag ClassTag;

	UPROPERTY(EditAnywhere, Category="Defaults")
	TArray<TSoftObjectPtr<UCustomCharacterPart>> CharacterParts;

};

USTRUCT(BlueprintType)
struct FFortIronCityDifficultyData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 DifficultyLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 LootLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	FName SuggestedStatClamp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	FString MissionRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	FGameplayTag RewardBadgeTag;

};

USTRUCT(BlueprintType)
struct FFortRewardQuantityPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FString TemplateId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 Quantity;

};

USTRUCT(BlueprintType)
struct FFortLevelUpDataV2 : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 DifficultyLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	float XPDisplayMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	TArray<FFortRewardQuantityPair> Rewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rest")
	int32 RestXPCap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Rest")
	int32 RestXPRechargeRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Boost")
	int32 BoostXPPerConsumable;

};

USTRUCT(BlueprintType)
struct FFortPhoenixLevelRewardData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	int32 TotalRequiredXP;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	bool bIsMajorReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	TArray<FFortRewardQuantityPair> VisibleReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	TArray<FFortRewardQuantityPair> HiddenRewards;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	FString EventTag;

};

USTRUCT(BlueprintType)
struct FFortPostMaxAccountLevelRewardData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PostMaxLevelReward")
	TArray<FFortRewardQuantityPair> Rewards;

};

USTRUCT(BlueprintType)
struct FFortPostMaxPhoenixLevelRewardData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	bool bIsMajorReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	TArray<FFortRewardQuantityPair> VisibleReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PhoenixLevelReward")
	FString EventTag;

};

USTRUCT()
struct FFortReplicatedStatMapping
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Category="Score")
	TEnumAsByte<EFortReplicatedStat::Type> StatID;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Score")
	EStatCategory StatCategory;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	FText DisplayName;

};

USTRUCT(BlueprintType)
struct FTagRestrictedTable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TagRestrictedTable")
	TSoftObjectPtr<UDataTable> SoftTablePtr;

	UPROPERTY(EditDefaultsOnly, Category="TagRestrictedTable")
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FFortSTWLootData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="LootData", meta=(AssetBundles="ServerCampaign"))
	TArray<FTagRestrictedTable> LootTierData;

	UPROPERTY(EditDefaultsOnly, Category="LootData", meta=(AssetBundles="ServerCampaign"))
	TArray<FTagRestrictedTable> LootPackageData;

};

USTRUCT(BlueprintType)
struct FFortWeaponAlterationRarityMappingData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon", meta=(DisplayName="High Slot Rarity Values"))
	FString SlotRarityValues;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Weapon", meta=(DisplayName="Low Slot Rarity Values"))
	FString LowSlotRarityValues;

};

USTRUCT(BlueprintType)
struct FHomebaseRatingDifficultyMappingData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="HomebaseRatingDifficultyMappingData")
	int32 Difficulty;

};

USTRUCT(BlueprintType)
struct FIronCityDifficultyInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 AccountLevel;

	UPROPERTY(BlueprintReadOnly, Category="IronCityDifficultyInfo")
	int32 Difficulty;

	UPROPERTY(BlueprintReadOnly, Category="IronCityDifficultyInfo")
	int32 LootLevel;

	UPROPERTY()
	FName StatClamp;

	UPROPERTY()
	FString MissionRewards;

	UPROPERTY(BlueprintReadOnly, Category="IronCityDifficultyInfo")
	FGameplayTag RewardBadgeTag;

};

USTRUCT(BlueprintType)
struct FIronCityMatchmakingBuckets
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 Difficulty;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Outpost")
	int32 RecommendedRating;

};

USTRUCT()
struct FIronCityRowToRating
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Difficulty;

	UPROPERTY()
	int32 RecommendedRating;

	UPROPERTY()
	int32 MinRating;

	UPROPERTY()
	int32 MaxRating;

};

USTRUCT()
struct FItemDefinitionAndCount
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Item")
	int32 Count;

	UPROPERTY(EditAnywhere, Category="Item")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

};

USTRUCT(BlueprintType)
struct FItemPromotionCosts : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ItemPromotionCosts")
	TArray<FFortItemQuantityPair> PromotionCosts;

};

USTRUCT()
struct FPhoneixXPStats
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString CalendarEventFlag;

	UPROPERTY()
	int32 MaxLevelXP;

	UPROPERTY()
	int32 MaxLevel;

	UPROPERTY()
	int32 NumOverlevelRewards;

};

USTRUCT()
struct FScoreMultiplierRow : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	float CombatMultiplier;

	UPROPERTY()
	float BuildingMultiplier;

	UPROPERTY()
	float UtilityMultiplier;

	UPROPERTY()
	float BadgeMultiplier;

	UPROPERTY()
	int32 MonsterKills;

	UPROPERTY()
	int32 MonsterDamagePoints;

	UPROPERTY()
	int32 PlayerKills;

	UPROPERTY()
	int32 WoodGathered;

	UPROPERTY()
	int32 StoneGathered;

	UPROPERTY()
	int32 MetalGathered;

	UPROPERTY()
	int32 Deaths;

	UPROPERTY()
	int32 BluGloActivity;

	UPROPERTY()
	int32 BuildingsBuilt;

	UPROPERTY()
	int32 BuildingsBuilt_Wood;

	UPROPERTY()
	int32 BuildingsBuilt_Stone;

	UPROPERTY()
	int32 BuildingsBuilt_Metal;

	UPROPERTY()
	int32 BuildingsUpgraded_Wood2;

	UPROPERTY()
	int32 BuildingsUpgraded_Wood3;

	UPROPERTY()
	int32 BuildingsUpgraded_Stone2;

	UPROPERTY()
	int32 BuildingsUpgraded_Stone3;

	UPROPERTY()
	int32 BuildingsUpgraded_Metal2;

	UPROPERTY()
	int32 BuildingsUpgraded_Metal3;

	UPROPERTY()
	int32 BuildingsDestroyed;

	UPROPERTY()
	int32 Repair_Wood;

	UPROPERTY()
	int32 Repair_Stone;

	UPROPERTY()
	int32 Repair_Metal;

	UPROPERTY()
	int32 FlagsCaptured;

	UPROPERTY()
	int32 FlagsReturned;

	UPROPERTY()
	int32 ContainersLooted;

	UPROPERTY()
	int32 CraftingPoints;

	UPROPERTY()
	int32 TrapPlacementPoints;

	UPROPERTY()
	int32 TrapActivationPoints;

};

USTRUCT(BlueprintType)
struct FTieredModifierSetData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	int32 WaveNumber;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	int32 ModifierDuration;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FName ModifierLootTierGroup;

};

USTRUCT()
struct FTieredModifierSet : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FTieredModifierSetData> ModifierData;

};

USTRUCT()
struct FTieredWaveCollectionLootSetData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FName> StartOfCollectionItemTierGroups;

	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FName> SuccessfulWaveItemTierGroups;

};

USTRUCT()
struct FTieredWaveCollectionLootSet : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FTieredWaveCollectionLootSetData> LootSetData;

};

USTRUCT(BlueprintType)
struct FTieredWaveSetCollectionData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FText DefenseText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FText LevelText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FText WaveText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Data")
	FText BreatherText;

	UPROPERTY(VisibleAnywhere, Category="Data")
	int32 MinLvl;

	UPROPERTY(VisibleAnywhere, Category="Data")
	int32 MaxLvl;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName BaseWaveLengthRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName BaseNumOfKillsRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName BaseNumOfKillPointsRowName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName BaseNumRiftKillsRowName;

	UPROPERTY(VisibleAnywhere, Category="Data")
	FName WaveSet;

};

USTRUCT()
struct FTieredWaveSetCollection : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Data")
	TArray<FTieredWaveSetCollectionData> CollectionData;

};

USTRUCT(BlueprintType)
struct FWorldItemAndMinMaxCount
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	FCurveTableRowHandle MinCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	FCurveTableRowHandle MaxCurveTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item")
	TObjectPtr<UFortWorldItemDefinition> Item;

};

UCLASS(MinimalAPI)
class UGameDataSTW : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Game Data")
	static float GetPersonalXpBoost();

	UFUNCTION(BlueprintPure, Category="Game Data")
	static TSoftObjectPtr<UFortTeamPerkItemDefinition> GetRecruitmentRewardForHero(UFortHeroType* Hero);

	UFUNCTION(BlueprintPure, Category="Game Data")
	static float GetTeamXpBoost();

	UFUNCTION(BlueprintPure, Category="Game Data")
	static int32 GetXpPerAccountLevel();

	UPROPERTY(EditAnywhere, Category="HeroType")
	FText DefaultHeroName;

	UPROPERTY(EditAnywhere, Category="QuickBar", meta=(ArraySizeEnum="/Script/FortniteGame.EFortQuickBars"))
	FQuickBarData QuickBarDefinitions[3];

	UPROPERTY(EditAnywhere, Category="Score")
	float ScoreDisplayFactor;

	UPROPERTY(EditAnywhere, Category="ScoreToXP")
	int32 ScoreDivisor;

	UPROPERTY(EditAnywhere, Category="ScoreToXP")
	int32 XPMult;

	UPROPERTY(EditAnywhere, Category="ScoreToXP")
	float GroupScoreRates[5];

	UPROPERTY(EditAnywhere, Category="ScoreToXP")
	float ScoreToXPLinearRate;

	UPROPERTY(EditAnywhere, Category="ScoreToXP")
	int32 LinearEnd;

	UPROPERTY(EditAnywhere, Category="XP")
	int32 XpPerAccountLevel;

	UPROPERTY(EditAnywhere, Category="XP")
	float CriticalMatch_XpBonusPercent;

	UPROPERTY(EditAnywhere, Category="XP")
	float PersonalBoost_XpBonusPercent;

	UPROPERTY(EditAnywhere, Category="XP")
	float GroupBoost_XpBonusPercent;

	UPROPERTY(EditAnywhere, Category="XP")
	float GroupBoost_BuffMultiplier;

	UPROPERTY(EditAnywhere, Category="XP")
	float Rest_XpBonusPercent;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	float LowXpConningValue;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	float VeryLowXpConningValue;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	float NoXpConningValue;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	FText FullXpConningMsg;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	FText LowXpConningMsg;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	FText VeryLowXpConningMsg;

	UPROPERTY(EditAnywhere, Category="DifficultyData")
	FText NoXpConningMsg;

	UPROPERTY(EditAnywhere, Category="Crafting")
	int32 MaxCraftQueueSize;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(RowType="/Script/FortniteGame.FortQuestObjectiveStatTableRow"))
	FDataTableRowHandle OnboardingCompleteZoneObjective;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(RowType="/Script/FortniteGame.FortQuestObjectiveStatTableRow"))
	FDataTableRowHandle ArmoryCollectionBookGatingQuestObjectiveStat;

	UPROPERTY(EditAnywhere, Category="UI")
	FCurveTableRowHandle PowerPointToRatingConversion;

	UPROPERTY(EditAnywhere, Category="GameDifficulty")
	FDataTableRowHandle GameDifficultyRowPIE;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FSettingsHUDVisibilityAndText> HUDVisibilityGameplayTags;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TArray<FItemDefinitionAndCount> DefaultInventoryList;

	UPROPERTY(EditAnywhere, Category="Inventory")
	TArray<FItemDefinitionAndCount> FastLoadDefaultInventoryList;

	UPROPERTY(EditDefaultsOnly, EditFixedSize, Category="Score")
	TArray<FFortReplicatedStatMapping> StatMappings;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates")
	float SquadMemberStatBonusMultiplier;

	UPROPERTY(EditAnywhere, Category="UI")
	TSoftObjectPtr<USoundBase> PlayerIdleWarningSound;

	UPROPERTY(VisibleAnywhere, Category="Expedition")
	FGameplayTag ExpeditionUnlockedTag;

	UPROPERTY(VisibleAnywhere, Category="Expedition")
	FGameplayTagContainer ExpeditionVehicleTags;

	UPROPERTY(EditAnywhere, Category="MissionAlerts")
	int32 DailyMissionAlertQuota;

	UPROPERTY(EditDefaultsOnly, Category="World")
	FConditionalFoundationQuota ConditionalFoundationQuota;

	UPROPERTY(EditDefaultsOnly, Category="Promotion")
	int32 MinLevelToPromoteItem;

	UPROPERTY(EditDefaultsOnly, Category="Promotion")
	int32 LevelsPerItemPromotion;

	UPROPERTY(EditDefaultsOnly, Category="Promotion")
	int32 MaxPromotionsPerItem;

private:
	UPROPERTY(EditAnywhere, Category="AIDirector", meta=(AssetBundles="Client, Server"))
	TSoftClassPtr<UFortAIEncounterInfo> TestEncounter;

	UPROPERTY(EditAnywhere, Category="Combat", meta=(AssetBundles="Client, Server"))
	TSoftClassPtr<UCombatManagerComponentSTW> CombatManager;

	UPROPERTY(EditAnywhere, Category="Camera", meta=(AssetBundles="ClientCampaign, Server"))
	TSoftClassPtr<AFortInGameMapManager> UIMapManagerSTW;

	UPROPERTY(EditAnywhere, Category="Music", meta=(AssetBundles="ClientCampaign, ServerCampaign"))
	TSoftObjectPtr<UAthenaMusicPackItemDefinition> DefaultStWLobbyMusic;

	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortAnalyticsItemExclusions> StWAnalyticsItemExclusionData;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ClientCampaign"))
	TSoftClassPtr<AFortAIPawn> DefaultDamageReceiverClass;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortTokenType> AccountInventoryBonusToken;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortTokenType> WorldInventoryBonusToken;

	UPROPERTY(EditAnywhere, Category="Inventory", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortTokenType> FounderChatUnlockToken;

	UPROPERTY(EditAnywhere, Category="Score", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortScoreStylingData> ScoreStylingData;

	UPROPERTY(EditDefaultsOnly, Category="Score", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> ScoreMultiplierDataTable;

	UPROPERTY(Transient)
	TObjectPtr<UDataTable> CachedScoreMultiplierDataTable;

	UPROPERTY(EditAnywhere, Category="Sounds", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<USoundMix> StWSoundMix;

	UPROPERTY(EditAnywhere, Category="Harvesting", meta=(AssetBundles="ClientCampaign,Server"))
	TArray<TSoftObjectPtr<UFortWeaponMeleeItemDefinition>> HarvestingTools;

	UPROPERTY(EditAnywhere, Category="PlayerSpawnPad")
	FFortPlayerSpawnPadPlacementData DefaultPlayerSpawnPadPlacementData;

	UPROPERTY(EditAnywhere, Category="CharacterCustomization", meta=(AssetBundles="ClientCampaign,Server"))
	TArray<FDefaultCharacterPartsForPawnClass> DefaultCharacterPartOverridesPerPawnClass;

	UPROPERTY(EditAnywhere, Category="Data", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TArray<TSoftClassPtr<AFortPlayerPawn>> CampaignPlayerPawnClasses;

	UPROPERTY(EditAnywhere, Category="GameMode", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<AFortAIGoalManager> AIGoalManagerClass;

	UPROPERTY(EditAnywhere, Category="GameMode", meta=(AssetBundles="Server"))
	TSoftClassPtr<UFortSharedMissionLists> SharedMissionListsClass;

	UPROPERTY(EditAnywhere, Category="Balance")
	float FORTAttributeToPowerMultiplier;

	UPROPERTY(EditAnywhere, Category="AmmoAndResources", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortNeverPersistItemDefinition> BluGloItemDefinition;

	UPROPERTY(EditAnywhere, Category="Score", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortItemDefinition> CriticalMissionRewardItemDefinition;

	UPROPERTY(EditAnywhere, Category="Score", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemDefinition> ScoreBonusMultiplerItemDefinition;

	UPROPERTY(EditAnywhere, Category="EventCurrency", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemDefinition> GenericCampaignEventCurrency;

	UPROPERTY(EditDefaultsOnly, Category="Backpack", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UFortWorldItemDefinition> BackpackItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="MissionRewards", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UFortWorldItemDefinition> MissionRewardPackItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="Outpost")
	FText OutpostRefundDialogTitle;

	UPROPERTY(EditDefaultsOnly, Category="Outpost")
	FText OutpostRefundDialogText;

	UPROPERTY(EditDefaultsOnly, Category="Outpost")
	FText OutpostRefundButtonText;

	UPROPERTY(EditAnywhere, Category="StatEvent", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortHeroData> FortHeroData;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UDataTable> AlterationMigrationMapping;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UDataTable> AlterationIntrinsicMapping;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> AlterationNamedExclusions;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> AlterationGroups;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> AlterationSlotDefinitions;

	UPROPERTY(EditDefaultsOnly, Category="Alterations", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UDataTable> AlterationSlotsLoadouts;

	UPROPERTY(EditDefaultsOnly, Category="Promotion", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UDataTable> BasePromotionCosts;

	UPROPERTY(EditAnywhere, Category="LootData", meta=(AssetBundles="Server"))
	TArray<FTagRestrictedTable> LootTierDataTablesSTW;

	UPROPERTY(EditAnywhere, Category="LootData", meta=(AssetBundles="Server"))
	TArray<FTagRestrictedTable> LootPackageDataTablesSTW;

	UPROPERTY(EditDefaultsOnly, Category="WaveEncounterData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> WaveSetCollectionData;

	UPROPERTY(EditDefaultsOnly, Category="WaveEncounterData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> WaveSetData;

	UPROPERTY(EditDefaultsOnly, Category="WaveEncounterData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> ModifierSetData;

	UPROPERTY(EditDefaultsOnly, Category="WaveEncounterData", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> WaveSetCollectionLootData;

	UPROPERTY(EditDefaultsOnly, Category="DifficultyData", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> PlayerStatClampingData;

	UPROPERTY(EditDefaultsOnly, Category="GameplayTags")
	FGameplayTagContainer NonGameplayRelevantTags;

	UPROPERTY(EditAnywhere, Category="Crafting", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UCurveTable> CraftingTimeTable;

	UPROPERTY(EditAnywhere, Category="Crafting", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<USoundBase> DefaultCraftingSuccessSound;

	UPROPERTY(EditDefaultsOnly, Category="TeamStats", meta=(AssetBundles="Client,Server"))
	TSoftClassPtr<UGameplayEffect> TeamStatsGameplayEffect;

	UPROPERTY(EditAnywhere, Category="LootData", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortDailyRewardScheduleDefinitions> DailyRewardSchedules;

	UPROPERTY(EditAnywhere, Category="Expedition", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> ExpeditionCriteriaRequirementsData;

	UPROPERTY(EditAnywhere, Category="DifficultyData", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> DifficultyData;

	UPROPERTY(EditAnywhere, Category="Weapon", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortWeaponReticleExtensionData> WeaponReticleExtensions;

	UPROPERTY(EditAnywhere, Category="RewardOverrides", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> RewardOverrides;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="NamedWeights")
	TSoftObjectPtr<UDataTable> NamedWeightsDataTable;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Catalog")
	TSoftObjectPtr<UDataTable> ProceduralCatalogOfferPriceFactorDataTable;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Catalog")
	TSoftObjectPtr<UDataTable> StreakBreakerDataTable;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Calendar Events")
	TSoftObjectPtr<UDataTable> STWCalendarEventInventoryTransforms;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Catalog")
	TSoftObjectPtr<UDataTable> ItemToQuestDataTable;

	UPROPERTY(Transient)
	TArray<FIronCityRowToRating> IronCityRatingArray;

	UPROPERTY(Transient)
	TArray<FIronCityDifficultyInfo> IronCityDifficultyLevels;

	UPROPERTY(EditDefaultsOnly, Category="Outpost")
	TArray<FIronCityMatchmakingBuckets> IronCityMatchmakingBuckets;

	UPROPERTY(EditDefaultsOnly, Category="Outpost", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> IronCityDifficultyTable;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> QuestObjectiveStatData;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> XPAccountLevelsTable;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> PostMaxAccountLevelRewardsTable;

	UPROPERTY(Transient)
	TArray<FTagRestrictedTable> CachedLootTierData;

	UPROPERTY(Transient)
	TArray<FTagRestrictedTable> CachedLootPackageData;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> PhoenixLevelRewardsTable;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> PostMaxPhoenixLevelRewardsTable;

	UPROPERTY(Transient)
	TMap<FString, FPhoneixXPStats> CachedPhoenixStats;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	TArray<FString> PhoenixEventFlags;

	UPROPERTY(EditDefaultsOnly, Category="Balance")
	TMap<FString, int32> PhoenixEventOverlevelXPPerLevel;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UFortAccountItemDefinition> PhoenixXpItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCurveTable> XPAccountItemLevelsTable;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCurveTable> XPAccountItemRewardsTable;

	UPROPERTY(EditDefaultsOnly, Category="Balance", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCurveTable> XPConningTable;

	UPROPERTY(EditDefaultsOnly, Category="Weapon", meta=(AssetBundles="ClientCampaign,Server"))
	TSoftObjectPtr<UDataTable> WeaponAlterationRarityMappingTable;

	UPROPERTY(Transient)
	TArray<float> CachedWeaponAlterationRarityMappingInfo;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortQuestItemDefinition> OnboardingQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortQuestItemDefinition> ManualSurvivorSlottingQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortQuestItemDefinition> ArmoryCollectionBookGatingQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortQuestItemDefinition> ArmoryResourcesGatingQuestItemDefinition;

	UPROPERTY(EditAnywhere, Category="Achievements")
	TSoftObjectPtr<UDataTable> QuestAchievementData;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Menu"))
	TSoftObjectPtr<UFortQuestMapData> QuestMapData;

	UPROPERTY(EditDefaultsOnly, Category="SkillTree", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemDefinition> SkillPointItemDef;

	UPROPERTY(EditDefaultsOnly, Category="SkillTree", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemDefinition> ResearchPointItemDef;

	UPROPERTY(EditAnywhere, Category="CheatInventory")
	TArray<TSoftObjectPtr<UFortWorldItemDefinition>> CheatInventoryItems;

	UPROPERTY(EditAnywhere, Category="Theater", meta=(AssetBundles="Client"))
	TSoftClassPtr<AFortTheaterMapViewer> TheaterMapViewerClass;

	UPROPERTY(EditAnywhere, Category="MissionAlert", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> MissionAlertCategories;

	UPROPERTY(EditAnywhere, Category="Homebase", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UMyTownData> MyFortData;

	UPROPERTY(EditAnywhere, Category="Homebase", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortHomebaseManager> HomebaseManager;

	UPROPERTY(EditAnywhere, Category="CollectionBook", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UFortCollectionBookData> CollectionBookData;

	UPROPERTY(EditAnywhere, Category="Survivors", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortSurvivorData> SurvivorData;

	UPROPERTY(EditAnywhere, Category="Outpost", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortOutpostData> OutpostData;

	UPROPERTY(EditAnywhere, Category="Outpost", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UCurveTable> OutpostPrepTimeData;

	UPROPERTY(EditAnywhere, Category="AIDirector", meta=(AssetBundles="ServerCampaign"))
	TSoftClassPtr<AFortAIDirector> AIDirectorSTW;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<AFortFeedbackManager> FeedbackManagerClass;

	UPROPERTY(EditAnywhere, Category="BluGlo", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<AFortBluGloManager> BluGloManagerClass;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortUIFeedbackBank> UIFeedbackBankSTW;

	UPROPERTY(EditAnywhere, Category="StatEvent", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<UFortStatEventManager> StatEventManagerClass;

	UPROPERTY(EditAnywhere, Category="HeroType", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortHeroType> DefaultHero;

	UPROPERTY(EditAnywhere, Category="GameMode", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<AFortThreatVisualsManager> ThreatVisualsManager;

	UPROPERTY(EditAnywhere, Category="GameMode", meta=(AssetBundles="ClientCampaign"))
	TSoftClassPtr<AFortWindManager> WindManager;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortAbilitySet> GenericPlayerAbilitySet;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<UGameplayEffect> SquadMemberStatBonusGE;

	UPROPERTY(EditAnywhere, Category="GameplayEffectTemplates", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftClassPtr<UGameplayEffect> TeamTrapBonusGE;

	UPROPERTY(EditAnywhere, Category="Effects", meta=(AssetBundles="ClientCampaign"))
	TSoftClassPtr<AFortConstructorBASE> BASEClass;

	UPROPERTY(EditAnywhere, Category="UI", meta=(AssetBundles="ClientCampaign"))
	TSoftClassPtr<UFortUINotification> MissionVoteNotificationClass;

	UPROPERTY(EditDefaultsOnly, Category="SessionXP", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UCurveTable> SessionXPCurveTable;

	UPROPERTY(EditAnywhere, Category="TieredWaves", meta=(AssetBundles="ServerCampaign"))
	TSoftObjectPtr<UCurveTable> TieredWavesDefenseReqTable;

	UPROPERTY(EditDefaultsOnly, Category="Expedition", meta=(AssetBundles="ClientCampaign"))
	TSoftClassPtr<UUserWidget> ExpeditionMasterWidgetClass;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AssetBundles="ClientCampaign,ServerCampaign"))
	TSoftObjectPtr<UFortTimeOfDayData> FortTimeOfDayData;

	UPROPERTY(EditAnywhere, Category="FrontEnd", meta=(AssetBundles="Menu"))
	TArray<TSoftClassPtr<UGameStateComponent>> FrontendGameStateComponents;

	UPROPERTY(EditAnywhere, Category="Music", meta=(AssetBundles="ClientCampaign, ServerCampaign"))
	TSoftClassPtr<AFortMusicManager> MusicManager;

	UPROPERTY(EditAnywhere, Category="Music", meta=(AssetBundles="ClientCampaign, ServerCampaign"))
	TSoftObjectPtr<UFortMusicManagerBank> MusicManagerBank;

	UPROPERTY(EditAnywhere, Category="Cosmetics", meta=(AssetBundles="ClientCampaign"))
	TSoftObjectPtr<UFortItemWrapMappingData> ItemWrapConfigAsset;

	UPROPERTY(EditAnywhere, Category="Cosmetics", meta=(AssetBundles="ClientCampaign"))
	TMap<FGameplayTag, FText> UpgradeRarityUnlockRequirementsText;

	UPROPERTY(EditAnywhere, Category="Cosmetics", meta=(AssetBundles="ClientCampaign"))
	TMap<FGameplayTag, FText> UpgradeTierUnlockRequirementsText;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="ServerCampaign"))
	TSoftClassPtr<AFortClientAnnouncement_Conversation> DefaultQuestStatConversationClass;

};

