// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction_AddComponents.h"
#include "GameFeatureData.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "UObject/SoftObjectPath.h"
#include "AI/Goals/FortAIGoalSelectionCriteria.h"
#include "FortUIExtension.h"
#include "GameData/FortTableCache.h"
#include "FortGameFeatureData.generated.h"

class AActor;
class AFortInGameMapManager;
class UCheatManagerExtension;
class UCurveTable;
class UDataTable;
class UFortAbilitySet;
class UFortContextualTutorialDefinition;
class UFortDeathCauseData;
class UFortFactionMapping;
class UFortGameSettingRegistryExtensionBase;
class UFortLevelOverlayConfig;
class UFortMobileHUDPresetExtensionContainer;
class UFortMobileHUDWidgetRegistryBase;
class UFortWeaponReticleExtensionData;
class UGameFeatureData;
class UWorld;

USTRUCT()
struct FFortGameFeatureGameDataMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Playlist")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditAnywhere, Category="Playlist")
	TSoftObjectPtr<UCurveTable> OverrideGameData;

};

USTRUCT()
struct FFortGameFeatureItemsToFullyLoadData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureItemsToFullyLoadData")
	FGameplayTagContainer PlaylistTags;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureItemsToFullyLoadData")
	TArray<FPrimaryAssetId> ItemIdsToFullyLoad;

};

USTRUCT()
struct FFortGameFeatureLootTableData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureLootTableData")
	TSoftObjectPtr<UDataTable> LootTierData;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureLootTableData")
	TSoftObjectPtr<UDataTable> LootPackageData;

};

USTRUCT(BlueprintType)
struct FPluginCheatMenuEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plugin Cheat Config")
	bool bIgnoreRunAllSeasonCheatsCommand;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plugin Cheat Config")
	FString SectionName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plugin Cheat Config")
	FString DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Plugin Cheat Config")
	TArray<FString> ConsoleCommands;

};

USTRUCT()
struct FVkMapExperienceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Experience")
	TSoftObjectPtr<UWorld> Map;

	UPROPERTY(EditAnywhere, Category="Experience")
	TArray<TSoftObjectPtr<UWorld>> BaseMaps;

};

USTRUCT()
struct FVkExperienceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Experience")
	TSoftObjectPtr<UWorld> DefaultMap;

	UPROPERTY(meta=(DeprecatedProperty, DeprecationMessage="Use MapData instead."))
	TSoftObjectPtr<UWorld> BaseMap_DEPRECATED;

	UPROPERTY(EditAnywhere, Category="Experience")
	TArray<FVkMapExperienceData> MapData;

};

UCLASS(MinimalAPI)
class UFortGameFeatureData : public UGameFeatureData
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API static TArray<FSoftObjectPath> SimulateScanningForPrimaryAssets(UGameFeatureData* GFD);
#endif

protected:
	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Encryption")
	FString EncryptionOverrideName;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | UI", meta=(DisplayName="UI Extensions"))
	TArray<FUIExtension> UIExtensions;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | UI", meta=(DisplayName="UI Reticle Extensions"))
	TSoftObjectPtr<UFortWeaponReticleExtensionData> WeaponReticleExtensions;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | UI", meta=(AllowAbstract="false", AllowedClasses="/Script/DynamicUI.DynamicUIDirectorBase", DisplayName="Dynamic UI Director Class"))
	TSoftClassPtr<AActor> DynamicUIDirectorClass;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | UI", meta=(DisplayName="UI Map Manager Override Class"))
	TSoftClassPtr<AFortInGameMapManager> UIMapManagerOverrideClass;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Mobile UI", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMobileHUDWidgetRegistryBase> MobileHUDWidgetRegistry;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Mobile UI", meta=(AssetBundles="Client"))
	TSoftObjectPtr<UFortMobileHUDPresetExtensionContainer> MobileHUDPresetExtensionContainer;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="Game Feature | Settings", meta=(DisplayName="Settings Registry Class"))
	TObjectPtr<UFortGameSettingRegistryExtensionBase> GameSettingRegistryExtensionClass;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Gameplay Cues")
	TArray<FString> GameplayCueNotifyPaths;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TArray<FFortGameFeatureDataBaseCurveTableOverrides> PlaylistBaseCurveTableOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TArray<FFortGameFeatureDataBaseDataTableOverrides> PlaylistBaseDataTableOverrides;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables")
	FFortGameFeatureLootTableData DefaultLootTableData;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables")
	TMap<FGameplayTag, FFortGameFeatureLootTableData> PlaylistOverrideLootTableData;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables")
	TSoftObjectPtr<UDataTable> DefaulAILootOnDeathDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UCurveTable> DefaultGameData;

	UPROPERTY(meta=(AssetBundles="Client,Server"))
	TMap<FGameplayTag, TSoftObjectPtr<UCurveTable>> PlaylistOverrideGameData_DEPRECATED;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TArray<FFortGameFeatureGameDataMapping> PlaylistOverrideGameDataMappings;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> DefaultRangedWeapons;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TMap<FGameplayTag, TSoftObjectPtr<UDataTable>> PlaylistOverrideRangedWeapons;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Data Tables", meta=(AssetBundles="Client,Server"))
	TMap<FGameplayTag, TSoftObjectPtr<UDataTable>> PlaylistOverrideAILootOnDeathDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Level", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortLevelOverlayConfig> LevelOverlayConfig;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game Feature | Level")
	TArray<TSoftObjectPtr<UWorld>> AdditionalLevels;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Game Feature | Level")
	TArray<TSoftObjectPtr<UWorld>> AdditionalLevelsServerOnly;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortAbilitySet> PlayerAbilitySet;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Ability", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortDeathCauseData> FortDeathCauseData;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Contextual tutorial", meta=(AssetBundles="Client,Server"))
	TArray<TSoftObjectPtr<UFortContextualTutorialDefinition>> ContextualTutorials;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Faction Mapping", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UFortFactionMapping> FactionMapping;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Weapon Upgrades", meta=(AssetBundles="Client,Server"))
	TSoftObjectPtr<UDataTable> WeaponUpgradesDataTable;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | AI", meta=(AssetBundles="Client, Server"))
	TArray<FPawnGoalSelectionTableEntry> PawnGoalSelectionTable;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Item Loading")
	TArray<FPrimaryAssetId> SharedItemIdsToFullyLoad;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature | Item Loading")
	TArray<FFortGameFeatureItemsToFullyLoadData> PlaylistItemsToFullyLoad;

	UPROPERTY(EditDefaultsOnly, Category="Experience")
	FVkExperienceData ExperienceData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Feature | Cheat Menu Entries", meta=(TitleProperty="DisplayName"))
	TArray<FPluginCheatMenuEntry> PluginCheats;

	UPROPERTY(EditDefaultsOnly, Category="Game Feature")
	bool bSkipPrimaryAssetScanningDuringSparseCooks;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<FGameFeatureComponentEntry> ComponentList_DEPRECATED;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TArray<TSubclassOf<UCheatManagerExtension>> CheatManagers_DEPRECATED;
#endif

};

