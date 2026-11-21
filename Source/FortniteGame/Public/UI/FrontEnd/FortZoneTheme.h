// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Environment/FortWindManager.h"
#include "FortTimeOfDayCollection.h"
#include "FortZoneTheme.generated.h"

class ABuildingSMActor;
class ADeployableBasePlot;
class AFortGameMode;
class AFortLobbyBeaconHost;
class AFortMusicManager;
class AFortTheaterMapTile;
class UFortCloudSaveItemDefinition;
class UFortDeployableBaseCloudSaveItemDefinition;
class UFortDeployableBaseSkillTreeUnlocks;
class UFortMusicManagerBank;
class UFortTieredCollectionLayout;
class UTexture2D;
class UWorld;

UENUM(BlueprintType)
enum class EDeployableBaseUseType : uint8
{
	/** Neighborhood/building only */
	Neighborhood = 0,
	/** Base deployed for PvE combat */
	PvECombat = 1,
};

UENUM()
enum class EFortZoneType : uint8
{
	// Normal PvE session with persistence

	PVE = 0,
	// PvP session

	PVP = 1,
	// A player owned keep

	Keep = 2,
	// Has a single zone, used for test maps and instant action

	SingleZone = 3,
	Max_None = 4 UMETA(Hidden),
};

USTRUCT()
struct FDeployableBaseSupportSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	bool bUseDeployableBases;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	TSoftObjectPtr<UFortDeployableBaseCloudSaveItemDefinition> DeployableBaseCloudSaveItemDef;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	TSoftClassPtr<ADeployableBasePlot> DeployableBasePlot;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	TSoftObjectPtr<UFortDeployableBaseSkillTreeUnlocks> SupportedUnlocks;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	bool bDeployableBasesReadOnly;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	EDeployableBaseUseType SupportedUseType;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBase")
	TArray<TObjectPtr<UFortTieredCollectionLayout>> TieredCollectionLayouts;

};

USTRUCT()
struct FZoneThemeDifficultyProperties
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ZoneThemeDifficultyProperties", meta=(ShowOnlyInnerProperties))
	TArray<FDataTableRowHandle> ValidDifficulties;

	UPROPERTY(EditDefaultsOnly, Category="ZoneThemeDifficultyProperties", meta=(ShowOnlyInnerProperties))
	FFortTimeOfDayTheme TimeOfDayTheme;

	UPROPERTY(EditDefaultsOnly, Category="ZoneThemeDifficultyProperties", meta=(ShowOnlyInnerProperties))
	FFortGlobalWindInfo GlobalWindInfo;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "Actor", "Advanced", "Navigation"))
class UFortZoneTheme : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Visual", meta=(AssetBundles="Menu"))
	TSoftClassPtr<AFortTheaterMapTile> TheaterMapTileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	FText ZoneName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	FText ZoneDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	FText AbundantResources;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, AssetRegistrySearchable, Category="Zone")
	EFortZoneType ZoneType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	TSoftClassPtr<AFortGameMode> ZoneGameMode;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	FGameplayTagContainer ZoneTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	TSoftClassPtr<AFortLobbyBeaconHost> LobbyBeaconHostClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	TSoftObjectPtr<UFortCloudSaveItemDefinition> CloudSaveItemDefinition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 ZoneIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 PlaylistId;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 TeamSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 TeamCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 MaxPartySize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	int32 MaxPlayers;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	float CriticalMissionEligibilityLength;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Matchmaking")
	float CriticalMissionEligibilityGracePeriodLength;

	UPROPERTY(EditDefaultsOnly, Category="DeployableBases")
	FDeployableBaseSupportSettings DeployableBaseSettings;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Rewards")
	uint8 IgnoreGeneratedRewards : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay Rules", meta=(AssetBundles="Zone"))
	TSoftClassPtr<ABuildingSMActor> PlayerSpawnPadClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay Rules")
	FGameplayTagContainer InitialPlayerSpawnTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Gameplay Rules")
	FGameplayTagContainer BackupPlayerSpawnTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	bool bOverrideConningText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone", meta=(EditCondition="bOverrideConningText"))
	FText ConningOverrideText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Music")
	TSoftClassPtr<AFortMusicManager> MusicManagerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Music")
	TObjectPtr<UFortMusicManagerBank> MusicManagerBank;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Zone")
	TSoftObjectPtr<UTexture2D> BackgroundImage;

protected:
	UPROPERTY(EditAnywhere, Category="Zone")
	TSoftObjectPtr<UWorld> ZoneToUse;

	UPROPERTY(EditDefaultsOnly, Category="Difficulty-RelatedProperties", meta=(ShowOnlyInnerProperties))
	TArray<FZoneThemeDifficultyProperties> DifficultyProperties;

};

