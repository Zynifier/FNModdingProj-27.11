// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortUserCloudHelperComponent.h"
#include "STW/Building/DeployableBasePlot.h"
#include "STW/FortTieredCollectionLayout.h"
#include "UI/FrontEnd/FortZoneTheme.h"
#include "FortDeployableBaseManager.generated.h"

class ABuildingActor;
class ADeployableBasePlot;
class AFortDeployableBaseManager;
class AFortPlayerPawn;
class UFortDeployableBaseCloudSaveItemDefinition;
class UFortDeployableBaseRecord;
class UFortDeployableBaseSkillTreeUnlocks;
class UFortTieredCollectionLayout;
class UObject;
enum class EDeployableBaseUseType : uint8;
enum class EHordeWaveStingerType : uint8;

UENUM()
enum class EHordeWaveStingerType : uint8
{
	WaveSuccess = 0,
	WaveFailure = 1,
	WaveIncoming = 2,
	WaveStarted = 3,
};

UENUM()
enum class EQueueActionType : uint8
{
	Plot = 0,
	ZoneCleanup = 1,
	EnvironmentActorRestoration = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDeployableBasePlotsSpawned);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLocalDeployablePlotInventoryChanged, ADeployableBasePlot*, Plot);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocalPlayerEntersDeployablePlot, AFortPlayerPawn*, PlayerPawn, ADeployableBasePlot*, Plot);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLocalPlayerLeavesDeployablePlot, AFortPlayerPawn*, PlayerPawn, ADeployableBasePlot*, Plot);

USTRUCT()
struct FActiveTieredCollectionLayout : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortTieredCollectionLayout> Layout;

	UPROPERTY(Transient)
	int32 MaxTierUnlocked;

	UPROPERTY(Transient)
	uint8 bLocked : 1;

};

USTRUCT()
struct FActiveTieredCollectionLayoutArray : public FFastArraySerializer
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FActiveTieredCollectionLayout> LayoutArray;

	UPROPERTY(Transient, NotReplicated)
	bool bTiersForced;

};

USTRUCT()
struct FDeployableBaseInstance : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ADeployableBasePlot> DeployableBase;

};

USTRUCT()
struct FDeployableBaseArray : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FDeployableBaseInstance> DeployableBases;

};

USTRUCT()
struct FEnvironmentBuildingRestorationRecord
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<ABuildingActor> ActorClass;

	UPROPERTY()
	FTransform ActorTransform;

	UPROPERTY()
	FName QuotaSelectedLootTierKey;

	UPROPERTY()
	int32 QuotaSelectedLootTier;

};

USTRUCT()
struct FPendingDeployableBaseUser
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl UserNetID;

	UPROPERTY()
	FFortUserCloudRequestHandle LoadingCloudRequestHandle;

	UPROPERTY()
	TObjectPtr<UFortDeployableBaseRecord> BaseRecord;

	UPROPERTY()
	TObjectPtr<ADeployableBasePlot> BasePlot;

};

USTRUCT()
struct FPendingDeployableManagerAction
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	EQueueActionType ActionType;

	UPROPERTY()
	TArray<TObjectPtr<ADeployableBasePlot>> PendingPlots;

	UPROPERTY()
	int32 CurrentPlotRunningIndex;

	UPROPERTY()
	EDeployableBaseBuildingState DesiredPlotState;

	UPROPERTY(Transient)
	TObjectPtr<AFortDeployableBaseManager> Manager;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortDeployableBaseManager : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly, Category="Deployable Manager")
	void BroadcastHordeWaveStinger(EHordeWaveStingerType StingerType) const;

	UFUNCTION(BlueprintPure, Category="Deployable Mananger")
	void GetAllDeployableBasePlots(TArray<ADeployableBasePlot*>& OutDeployableBasePlots) const;

	UFUNCTION(BlueprintPure, Category="Deployable Manager")
	void GetAvailableTiers(TArray<FAvailableTierLayout>& OutAvailableTiers) const;

	UFUNCTION(BlueprintCallable, Category="Deployable Mananger", meta=(DisplayName="Get Deployable Base Manager", WorldContext="WorldContextObject"))
	static AFortDeployableBaseManager* GetCurrent(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category="Deployable Mananger")
	ADeployableBasePlot* GetDeployableBasePlotFromLocation(const FVector& Location) const;

	UFUNCTION(BlueprintPure, Category="Deployable Manager")
	EDeployableBaseUseType GetDeployableBaseUseType() const;

	UFUNCTION(BlueprintPure, Category="Deployable Manager")
	int32 GetHighestDefeatedTierForPlayerAndLayout(FUniqueNetIdRepl PlayerId, const UFortTieredCollectionLayout* Layout) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, Category="Deployable Manager")
	bool GetTierOutputForSelectedTier(int32 Tier, const UFortTieredCollectionLayout* Layout, FFortTierCollectionLayoutOutput& Output) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Deployable Mananger")
	void ReloadAllPlots();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Deployable Mananger")
	void SetKeepDeployableBasesOnLogout(bool bInKeepBasesOnLogout);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Deployable Mananger")
	uint8 bRestrictedBuildingActive : 1;

	UPROPERTY(Transient, Replicated)
	uint8 bBusyWithPlotActions : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Deployable Mananger")
	uint8 bDestroyAllBuildingPiecesOnReload : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Deployable Mananger")
	int32 NumPiecesDestroyedOnZoneCleanupPerUpdate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Deployable Mananger")
	int32 NumEnvPiecesRestoredPerUpdate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="DeployableBase")
	bool bDeployableBasesReadOnly;

	UPROPERTY(Transient, Replicated)
	EDeployableBaseUseType DeployableBaseUseType;

	UPROPERTY(Transient, Replicated)
	FActiveTieredCollectionLayoutArray ActiveTieredCollectionLayouts;

	UPROPERTY(BlueprintAssignable)
	FOnDeployableBasePlotsSpawned OnDeployableBasePlotsSpawned;

	UPROPERTY(BlueprintAssignable)
	FOnLocalPlayerEntersDeployablePlot OnLocalPlayerEntersDeployablePlotEvent;

	UPROPERTY(BlueprintAssignable)
	FOnLocalPlayerLeavesDeployablePlot OnLocalPlayerLeavesDeployablePlotEvent;

	UPROPERTY(BlueprintAssignable)
	FOnLocalDeployablePlotInventoryChanged OnLocalDeployablePlotInventoryChangedEvent;

private:
	UPROPERTY(Transient, Replicated)
	FDeployableBaseArray DeployableBaseArray;

	UPROPERTY(Transient)
	TObjectPtr<UFortDeployableBaseCloudSaveItemDefinition> DeployableBaseItemDefinition;

	UPROPERTY(Transient)
	TSubclassOf<ADeployableBasePlot> DeployableBasePlotClass;

	UPROPERTY(Transient)
	TObjectPtr<UFortDeployableBaseSkillTreeUnlocks> SupportedSkillTreeBasedUnlocks;

	UPROPERTY(Transient)
	int32 NumExpectedPlots;

	UPROPERTY(Transient)
	TArray<FPendingDeployableBaseUser> PendingUsers;

	UPROPERTY(Transient)
	TArray<FPendingDeployableManagerAction> PendingDeployableManagerActions;

	UPROPERTY(Transient)
	TArray<FEnvironmentBuildingRestorationRecord> EnvironmentActorsRequiringRestoration;

	UPROPERTY(Transient)
	uint8 bCaptureEnvironmentActorsForRestoration : 1;

	UPROPERTY(Transient)
	uint8 bWorldInitialized : 1;

	UPROPERTY(Transient)
	uint8 bKeepBasesOnLogout : 1;

	UPROPERTY(Transient)
	TArray<FUniqueNetIdRepl> PlayersPendingPlotReset;

};

