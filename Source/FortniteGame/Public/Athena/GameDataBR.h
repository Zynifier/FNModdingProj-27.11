// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "DataRegistryId.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "FortCreativeItemData.h"
#include "FortGameData.h"
#include "Online/FortCreativeBetaPermission.h"
#include "UI/FortElevationData.h"
#include "GameDataBR.generated.h"

class AFortAIDirector;
class AFortAIGoalManager;
class AFortFeedbackManager;
class AFortPawn;
class UAthenaDailyQuestDefinition;
class UAthenaMapPreloadData;
class UAthenaMemoryCostRegister;
class UAthenaQuestCategoryGlobalData;
class UAthenaSeasonItemDefinition;
class UCreativeBetaPermissionsDataAsset;
class UCreativeDynamicXpDataAsset;
class UCreativePlaysetPropsDataAsset;
class UCurveLinearColor;
class UCurveTable;
class UDataRegistry;
class UDataTable;
class UFortAbilitySet;
class UFortAnalyticsItemExclusions;
class UFortCreativeActorCollection;
class UFortFactionMapping;
class UFortGameplayFeedbackEventData;
class UFortHeroType;
class UFortItemDefToItemVariantDataMapping;
class UFortItemToBuildingGameplayActorPickupMapping;
class UFortItemWrapMappingData;
class UFortItemsForEventMapping;
class UFortLootGroupWeightedRollingData;
class UFortPlayerGliderAnimSet;
class UFortRepeatableDailiesCardItemDefinition;
class UFortResourceItemDefinition;
class UFortRespawnDataTable;
class UFortTokenType;
class UFortUIFeedbackBank;
class UFortWeaponPickupSpawnAmmoData;
class UFortWeaponRangedItemDefinition;
class UFortWeaponReticleExtensionData;
class UGameStateComponent;
class UPoiNamedWeights;
class UReverbEffect;
class USlateBrushAsset;
class USoundMix;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortWeaponUpgradeCosts : uint8
{
	NotSet = 0,
	WoodUncommon = 1,
	WoodRare = 2,
	WoodVeryRare = 3,
	WoodSuperRare = 4,
	MetalUncommon = 5,
	MetalRare = 6,
	MetalVeryRare = 7,
	MetalSuperRare = 8,
	BrickUncommon = 9,
	BrickRare = 10,
	BrickVeryRare = 11,
	BrickSuperRare = 12,
	HorizontalWoodCommon = 13,
	HorizontalWoodUncommon = 14,
	HorizontalWoodRare = 15,
	HorizontalWoodVeryRare = 16,
	HorizontalWoodSuperRare = 17,
	HorizontalMetalCommon = 18,
	HorizontalMetalUncommon = 19,
	HorizontalMetalRare = 20,
	HorizontalMetalVeryRare = 21,
	HorizontalMetalSuperRare = 22,
	HorizontalBrickCommon = 23,
	HorizontalBrickUncommon = 24,
	HorizontalBrickRare = 25,
	HorizontalBrickVeryRare = 26,
	HorizontalBrickSuperRare = 27,
};

UENUM(BlueprintType)
enum class EFortWeaponUpgradeDirection : uint8
{
	NotSet = 0,
	Vertical = 1,
	Horizontal = 2,
};

UENUM(BlueprintType)
enum class EFortWeaponUpgradeInteractionResult : uint8
{
	Upgradable = 0,
	NotEnoughResources = 1,
	CannotUpgrade = 2,
	CannotInteract = 3,
};

UENUM()
enum class EPlayerAttributeClampType : uint8
{
	Minimum = 0,
	Maximum = 1,
};

USTRUCT(BlueprintType)
struct FAthenaLevelUpData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XpToNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 XpTotal;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	int32 CurrencyReward;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LevelUp")
	FString ChaseRewardTemplateId;

};

USTRUCT(BlueprintType)
struct FGameplayTagMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="GameplayTagMessage")
	FGameplayTagContainer Tags;

	UPROPERTY(EditAnywhere, Category="GameplayTagMessage")
	FText Text;

};

USTRUCT()
struct FPlayerAttributeClampRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PlayerAttributeClampRow")
	FGameplayAttribute Attribute;

	UPROPERTY(EditDefaultsOnly, Category="PlayerAttributeClampRow")
	EPlayerAttributeClampType ClampType;

	UPROPERTY(EditDefaultsOnly, Category="PlayerAttributeClampRow")
	float ClampValue;

};

USTRUCT()
struct FWeaponUpgradeItemRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	TObjectPtr<UFortWeaponRangedItemDefinition> CurrentWeaponDef;

	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	TObjectPtr<UFortWeaponRangedItemDefinition> UpgradedWeaponDef;

	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	EFortWeaponUpgradeCosts WoodCost;

	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	EFortWeaponUpgradeCosts MetalCost;

	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	EFortWeaponUpgradeCosts BrickCost;

	UPROPERTY(EditDefaultsOnly, Category="WeaponUpgradeItemRow")
	EFortWeaponUpgradeDirection Direction;

};

UCLASS(MinimalAPI)
class UGameDataBR : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SeasonConfig", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.AthenaSeasonTitleEntry"))
	TObjectPtr<UDataTable> SeasonTitleDefinitions;

	UPROPERTY(EditAnywhere, Category="SeasonConfig")
	TObjectPtr<UAthenaSeasonItemDefinition> FallbackSeason;

	UPROPERTY(EditAnywhere, Category="GameDataBR")
	TObjectPtr<UFortRepeatableDailiesCardItemDefinition> FallbackRepeatableDailiesCard;

	UPROPERTY(EditAnywhere, Category="Messages")
	TArray<FGameplayTagMessage> UnableToPerformActionMessages;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FSettingsHUDVisibilityAndText> HUDVisibilityGameplayTags;

	UPROPERTY(EditDefaultsOnly, Category="Peripheral")
	TObjectPtr<UCurveLinearColor> TimeOfDayRGBForPeripherals;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundMix> AthenaSoundMix;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<UReverbEffect> AthenaReverbEffect;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	FName AthenaReverbEffectTag;

	UPROPERTY(EditDefaultsOnly, Category="Sounds")
	TObjectPtr<USoundMix> VisualizationSoundMix;

	UPROPERTY(EditAnywhere, Category="Visual")
	TObjectPtr<UFortRespawnDataTable> RespawnDataTable;

	UPROPERTY(EditAnywhere, Category="Loot")
	TObjectPtr<UPoiNamedWeights> NamedWeightsByPoi;

	UPROPERTY(EditAnywhere, Category="GameDataBR")
	TObjectPtr<UAthenaMemoryCostRegister> AthenaMemoryCostRegister;

	UPROPERTY(EditAnywhere, Category="giftBox")
	FText DefaultDisplayNameForGiftBoxes;

private:
	UPROPERTY(EditAnywhere, Category="Analytics", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortAnalyticsItemExclusions> AnalyticsItemExclusionDataBR;

	UPROPERTY(EditAnywhere, Category="Loot Data | Default Data", meta=(AssetBundles="ClientAthena, Server"))
	TArray<TSoftObjectPtr<UDataTable>> LootTierDataTablesBR;

	UPROPERTY(EditAnywhere, Category="Loot Data | Default Data", meta=(AssetBundles="ClientAthena, Server"))
	TArray<TSoftObjectPtr<UDataTable>> LootPackageDataTablesBR;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> QuestEventXPTable;

	UPROPERTY(EditAnywhere, Category="Quests", meta=(AssetBundles="Server"))
	FDataRegistryType QuestEventXPRegistry;

	UPROPERTY(EditAnywhere, Category="Quests")
	TArray<TSoftObjectPtr<UFortTokenType>> RarityTokens;

	UPROPERTY(EditAnywhere, Category="TagQueries", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataTable> NamedWeightTagQueryTable;

	UPROPERTY(EditAnywhere, Category="AIGoalManager", meta=(AssetBundles="Server"))
	TSoftClassPtr<AFortAIGoalManager> AIGoalManagerBR;

	UPROPERTY(EditAnywhere, Category="AIDirector", meta=(AssetBundles="Server"))
	TSoftClassPtr<AFortAIDirector> AIDirectorBR;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ClientAthena"))
	TSoftClassPtr<AFortPawn> DefaultDamageReceiverClassBR;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(AssetBundles="ClientAthena,ServerAthena"))
	TSoftClassPtr<AFortFeedbackManager> FeedbackManagerClassBR;

	UPROPERTY(EditAnywhere, Category="Feedback", meta=(AssetBundles="ClientAthena,ServerAthena"))
	TSoftObjectPtr<UFortUIFeedbackBank> UIFeedbackBankBR;

	UPROPERTY(EditAnywhere, Category="HeroType", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortHeroType> DefaultHeroBR;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="ClientAthena,Server"))
	TSoftObjectPtr<UFortAbilitySet> PlayerAbilitySetBR;

	UPROPERTY(EditDefaultsOnly, Category="Competitive", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UDataTable> CompetitiveIdentityDataTable;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortItemsForEventMapping> FortItemsForEventMapping;

	UPROPERTY(EditAnywhere, Category="Pickups", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortItemToBuildingGameplayActorPickupMapping> FortItemToPickupBGAMapping;

	UPROPERTY(EditAnywhere, Category="Pickups", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortWeaponReticleExtensionData> WeaponReticleExtensions;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortGameplayFeedbackEventData> FeedbackEventData;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ClientAthena"))
	TSoftClassPtr<UUserWidget> DefaultRebootVanIndicatorClass;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ClientAthena"))
	TSoftClassPtr<UUserWidget> DefaultContextTutorialIndicatorClass;

	UPROPERTY(EditAnywhere, Category="Tooltips", meta=(AssetBundles="ClientAthena"))
	TSoftClassPtr<UUserWidget> DefaultEliminationIndicatorClass;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UDataRegistry> CreativeRealEstatePlotTable;

	UPROPERTY(EditAnywhere, Category="Creative")
	TObjectPtr<UFortCreativeActorCollection> CreativeInventoryCollection;

	UPROPERTY(EditAnywhere, Category="Creative")
	TObjectPtr<UFortCreativeActorCollection> AllowedCreativeDeviceCollection;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Server"))
	TObjectPtr<UCreativeBetaPermissionsDataAsset> CreativeBetaPermissions;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UCreativeDynamicXpDataAsset> CreativeDynamicXp;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UCreativePlaysetPropsDataAsset> CreativePlaysetProps;

	UPROPERTY(Transient)
	TMap<FPrimaryAssetId, FCreativeItemMetaData> CachedCreativeInventory;

	UPROPERTY(Transient)
	TArray<FPrimaryAssetId> CachedCreativeRealEstatePlots;

	UPROPERTY(Transient)
	TMap<FPrimaryAssetId, FCreativeBetaPermission> CachedCreativeBetaPermissions;

	UPROPERTY(Transient)
	TSet<FName> CachedCreativePlaysetProps;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> CreativeTagsTable;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> CreativeTagCategoriesTable;

	UPROPERTY(EditAnywhere, Category="Level", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UAthenaMapPreloadData> MapPreloadData;

	UPROPERTY(EditAnywhere, Category="Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortWeaponPickupSpawnAmmoData> FortWeaponPickupSpawnAmmoData;

	UPROPERTY(EditAnywhere, Category="FrontEnd", meta=(AssetBundles="Menu"))
	TArray<TSoftClassPtr<UGameStateComponent>> FrontendGameStateComponents;

	UPROPERTY(EditAnywhere, Category="Faction", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortFactionMapping> FortFactionMapping;

	UPROPERTY(EditAnywhere, Category="Cosmetics", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<UFortItemWrapMappingData> ItemWrapConfigAsset;

	UPROPERTY(EditAnywhere, Category="Cosmetics")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> DefaultGliderAnimSet;

	UPROPERTY(EditAnywhere, Category="Cosmetics")
	TSoftObjectPtr<UFortPlayerGliderAnimSet> UmbrellaGliderAnimSet;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Calendar Events", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.FortCalendarEventInventoryTransformData"))
	TSoftObjectPtr<UDataTable> AthenaCalendarEventInventoryTransforms;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Quests")
	TSoftObjectPtr<UAthenaDailyQuestDefinition> EmptyQuestAsset;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Pickup Visuals", meta=(AssetBundles="ServerAthena"))
	TSoftObjectPtr<UFortItemDefToItemVariantDataMapping> ItemDefToItemVariantDataMappingAsset;

	UPROPERTY(EditAnywhere, Category="Loot Data | Weapon Upgrades", meta=(AssetBundles="ClientAthena, ServerAthena"))
	TSoftObjectPtr<UDataTable> WeaponUpgradeTable;

	UPROPERTY(EditAnywhere, Category="Stash | Global Currency")
	TSoftObjectPtr<UFortResourceItemDefinition> DefaultGlobalCurrencyItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="Stash | Global Currency")
	TSoftObjectPtr<UCurveTable> DefaultCurrencyPayoutTable;

	UPROPERTY(EditDefaultsOnly, Category="Loot Data | Loot Groups")
	TSoftObjectPtr<UFortLootGroupWeightedRollingData> DefaultLootGroupData;

	UPROPERTY(EditDefaultsOnly, Category="Attributes", meta=(AssetBundles="ClientAthena,ServerAthena"))
	TSoftObjectPtr<UDataTable> PlayerAttributesClampingDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Bots", meta=(AssetBundles="ClientAthena"))
	TSoftObjectPtr<UDataTable> BotItemDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Quests", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UAthenaQuestCategoryGlobalData> QuestCategoryGlobalData;

	UPROPERTY(EditDefaultsOnly, Category="Elevation Arrows", meta=(AssetBundles="Client"))
	TSoftObjectPtr<USlateBrushAsset> ElevationArrowBrush;

	UPROPERTY(EditDefaultsOnly, Category="Elevation Arrows")
	FElevationArrowData DefaultElevationArrowData;

	UPROPERTY(Transient)
	FGameplayTagContainer BotSupportedItemTags;

};

