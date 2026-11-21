// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GameplayTagContainer.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "FortAssetManager.generated.h"

class IFortAccountItemDefinitionOverrideManagerInterface;
class UFortGameData;
class UGameDataBR;
class UGameDataCosmeticGating;
class UGameDataCosmetics;
class UGameDataSTW;
class UObject;

USTRUCT()
struct FFortGameFeatureInstallBundleURLData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GameFeatureName;

	UPROPERTY()
	FString RequiredGameFeaturePluginName;

	UPROPERTY()
	TArray<FString> RequiredBundleNames;

	UPROPERTY()
	bool bShouldUninstallRequiredOnTerminate;

	UPROPERTY()
	FString OptionalGameFeaturePluginName;

	UPROPERTY()
	TArray<FString> OptionalBundleNames;

	UPROPERTY()
	bool bShouldUninstallOptionalOnTerminate;

	UPROPERTY()
	FString BasePluginDirectory;

	UPROPERTY()
	bool bAlwaysAllowDownloadOnCellular;

	UPROPERTY(Transient)
	bool bUserPaused;

};

USTRUCT()
struct FWorldHLODStreamingData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSet<FName> MediumLevelHLODPackageNames;

	UPROPERTY()
	TSet<FName> SplineHLODPackageNames;

	UPROPERTY()
	TArray<FName> MapsToRebuildHLODs;

};

UCLASS(Config=Game, MinimalAPI)
class UFortAssetManager : public UAssetManager
{
	GENERATED_BODY()

	friend class UFortAnimNotifyState_SpawnPickaxe;

private:
	UPROPERTY()
	TMap<TObjectPtr<UObject>, FName> GCPreventionPool;

	UPROPERTY()
	TArray<FName> DefaultBundleState;

	UPROPERTY()
	TArray<FName> PlatformBundleState;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Config)
	TArray<FName> PostImportMigrationStWDataTables;
#endif

	UPROPERTY()
	TObjectPtr<UFortGameData> GameDataCommon;

	UPROPERTY(Config)
	FString GameDataNameCommon;

	UPROPERTY()
	TObjectPtr<UGameDataCosmetics> GameDataCosmetics;

	UPROPERTY()
	TObjectPtr<UGameDataCosmeticGating> GameDataCosmeticGating;

	UPROPERTY(Config)
	FString GameDataNameCosmetics;

	UPROPERTY(Config)
	FString GameDataNameCosmeticGating;

	UPROPERTY()
	TObjectPtr<UGameDataBR> GameDataBR;

	UPROPERTY(Config)
	FString GameDataNameBR;

	UPROPERTY()
	TObjectPtr<UGameDataSTW> GameDataSTW;

	UPROPERTY(Config)
	FString FastCookTheaterPath;

	UPROPERTY(Config)
	FString PerfMemTheaterPath;

	UPROPERTY(Config)
	FString BROnlyTheaterPath;

	UPROPERTY(Config)
	FString DanceRoyaleMapPath;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	FDateTime TimePlayInEditorStarted;
#endif

	UPROPERTY(Config)
	TArray<FFortGameFeatureInstallBundleURLData> GameFeatureInstallBundleURLList;

	UPROPERTY(Transient)
	TMap<FGameplayTag, TScriptInterface<IFortAccountItemDefinitionOverrideManagerInterface>> FortAccountItemDefinitionOverrideManagers;

};

UCLASS(Config=FortStreamingData, DefaultConfig, MinimalAPI)
class UFortHLODStreamingData : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TMap<FName, FWorldHLODStreamingData> WorldData;

	UPROPERTY(Config)
	FWorldHLODStreamingData GlobalData;

};

