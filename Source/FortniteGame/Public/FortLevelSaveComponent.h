// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Misc/Guid.h"
#include "AsyncTaskQueue.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "LevelSaveComponent.h"
#include "ValkyriePaletteProviderInterface.h"
#include "FortLevelSaveComponent.generated.h"

class UFortCreativeRealEstatePlotItem;
class UFortCreativeRealEstatePlotItemDefinition;
enum class EBackupSaveState : uint8;

UENUM(BlueprintType)
enum class EBackupSaveState : uint8
{
	Ready = 0,
	InProgress = 1,
	OnCooldown = 2,
};

UENUM(BlueprintType)
enum class ELevelManagementTerrainType : uint8
{
	Level = 0,
	// Created using the Level Instance Device.

	Terrain = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBackupRestoreStateChanged, EBackupSaveState, SaveState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBackupSaveStateChanged, EBackupSaveState, SaveState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnClientLevelListUpdated);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDateChanged, FDateTime, DateValue);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSavingStateChanged, bool, SaveActive);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUnloadComplete);

USTRUCT()
struct FCachedLinkAnalyticsData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FString IslandTitle;

	UPROPERTY(Transient)
	FString IslandMnemonic;

	UPROPERTY(Transient)
	int32 IslandVersion;

	UPROPERTY(Transient)
	bool bIsInDiscovery;

	UPROPERTY(Transient)
	bool bIsValid;

	UPROPERTY(Transient)
	FString IslandAccountID;

	UPROPERTY(Transient)
	float IslandThermometerValue;

};

USTRUCT(BlueprintType)
struct FLevelInstanceListElement
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGuid Guid;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	FString Name;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	ELevelManagementTerrainType TerrainType;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	int32 MaxMemory;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	int32 CurrentMemory;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	int32 NumPortals;

	UPROPERTY(BlueprintReadOnly, Category="LevelInstanceListElement")
	int32 NumRefs;

};

USTRUCT()
struct FLevelInstanceList
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FLevelInstanceListElement> ElementList;

};

USTRUCT()
struct FModerationObjectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ObjectName;

	UPROPERTY()
	FVector ObjectLocation;

	UPROPERTY()
	TArray<FString> TextStrings;

};

USTRUCT()
struct FModerationIslandInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FModerationObjectInfo> Objects;

};

USTRUCT()
struct FSharedPersistenceRequest
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ProjectId;

	UPROPERTY()
	bool bWritable;

};

USTRUCT()
struct FVKEditProjectInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString VKProjectId;

	UPROPERTY()
	FString VKModuleId;

	UPROPERTY()
	int32 VKModuleVersion;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortLevelSaveComponent : public ULevelSaveComponent, public IValkyriePaletteProvider
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool DestroyLevelInstance(FGuid LevelInstanceGuid);

	UFUNCTION(BlueprintPure)
	FUniqueNetIdRepl GetAccountIdOfOwner() const;

	UFUNCTION(BlueprintPure)
	bool IsCurated() const;

	UFUNCTION(BlueprintPure)
	bool IsLoaded() const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Loaded Link Data"))
	void K2_GetLoadedLinkData(FCreativeLoadedLinkData& LinkData) const;

	UFUNCTION(BlueprintCallable)
	bool RenameLevelInstance(FGuid LevelInstanceGuid, const FString& NewLevelName);

	UPROPERTY(Transient, BlueprintAssignable)
	FOnSavingStateChanged OnClientSaveStateChanged;

	UPROPERTY(Transient, BlueprintAssignable)
	FOnBackupSaveStateChanged OnClientBackupSaveStateChanged;

	UPROPERTY(Transient, BlueprintAssignable)
	FOnBackupRestoreStateChanged OnClientBackupRestoreStateChanged;

	UPROPERTY(Transient, BlueprintAssignable)
	FOnDateChanged OnClientCheckpointDateChanged;

	UPROPERTY(Transient, Replicated)
	FVKEditProjectInfo CurrentVkProjectInfo;

protected:
	UFUNCTION()
	void OnRep_AccountIdOfOwner();

	UFUNCTION()
	void OnRep_BackupSaveState(EBackupSaveState OldValue);

	UFUNCTION()
	void OnRep_IsAutoSaving(bool bOldValue);

	UFUNCTION()
	void OnRep_LastCheckpointDate(FDateTime OldValue);

	UFUNCTION()
	void OnRep_LevelInstanceList();

	UFUNCTION()
	void OnRep_Loaded();

	UFUNCTION()
	void OnRep_LoadedLinkData();

	UFUNCTION()
	void OnRep_LoadedPlotInstanceId();

	UFUNCTION()
	void OnRep_OwnerCreativePermissions();

	UFUNCTION()
	void OnRep_RestoringStateChanged(EBackupSaveState OldValue);

	UPROPERTY(EditAnywhere, Category="Volume")
	TObjectPtr<UFortCreativeRealEstatePlotItemDefinition> RestrictedPlotDefinition;

	UPROPERTY(EditAnywhere, Category="Volume")
	bool bAutoLoadFromRestrictedPlotDefinition;

	UPROPERTY(EditAnywhere, Category="Volume")
	int32 LinkCodeNumberToAutoLoad;

	UPROPERTY(EditAnywhere, Category="Volume")
	bool bLoadRandomLinkCode;

	UPROPERTY(EditAnywhere, Category="Volume")
	bool bLoadMatchAssignedCode;

	UPROPERTY(EditAnywhere, Category="Volume")
	bool bCuratedHub;

	UPROPERTY(EditAnywhere, Category="Volume")
	bool bLoadPlaysetFromPlot;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_AccountIdOfOwner)
	FUniqueNetIdRepl AccountIdOfOwner;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OwnerCreativePermissions)
	TArray<FString> OwnerCreativePermissions;

	UPROPERTY(Transient)
	TObjectPtr<UFortCreativeRealEstatePlotItem> LoadedPlot;

	UPROPERTY(Transient)
	bool bPermissionsSaveInProgress;

	UPROPERTY(Transient, Replicated)
	bool bCurated;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LoadedPlotInstanceId)
	FString LoadedPlotInstanceId;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LoadedLinkData)
	FCreativeLoadedLinkData LoadedLinkData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CachedAnalyticsData)
	FCachedLinkAnalyticsData CachedAnalyticsData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_Loaded)
	bool bIsLoaded;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsAutoSaving)
	bool bIsAutoSaving;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_BackupSaveState)
	EBackupSaveState BackupSaveState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RestoringStateChanged)
	EBackupSaveState RestoringState;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LastCheckpointDate)
	FDateTime LastCheckpointDateUtc;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LevelInstanceList)
	FLevelInstanceList LevelInstanceList;

	UPROPERTY(Transient, Replicated)
	bool bOptedInForDeviceUpgrades;

	UPROPERTY(Transient, Replicated)
	bool bOptedInForMemorySystemUpgrades;

private:
	UFUNCTION()
	void CloudSaveFinished(const FAsyncTaskResult& Result);

	UFUNCTION()
	void OnRep_CachedAnalyticsData();

	UFUNCTION()
	void OnRep_PaletteLinkCodes();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PaletteLinkCodes)
	TArray<FString> PaletteLinkCodes;

	UPROPERTY(Config)
	int32 PublishRateLimitSeconds;

	UPROPERTY(Config)
	int32 BackupRateLimitSeconds;

	UPROPERTY(Config)
	int32 RestoreRateLimitSeconds;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, float> ReporterUniqueIds;

};

