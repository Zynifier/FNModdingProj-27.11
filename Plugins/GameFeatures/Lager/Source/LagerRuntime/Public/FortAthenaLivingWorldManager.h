// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameStateComponent.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortAthenaLivingWorldActorUpdateHandler.h"
#include "FortAthenaLivingWorldConditionContainer.h"
#include "FortAthenaLivingWorldEventData.h"
#include "FortAthenaLivingWorldPlayerTracker.h"
#include "FortAthenaLivingWorldPreloader.h"
#include "FortDataRegistry/FortDataRegistryResolverScopeInterface.h"
#include "FortReleaseVersion.h"
#include "FortAthenaLivingWorldManager.generated.h"

class AActor;
class AFortAthenaLivingWorldEQSHelper;
class AFortAthenaPatrolPath;
class IFortAthenaLivingWorldPointProviderInterface;
class UFortAthenaLivingWorldConfigData;
class UFortAthenaLivingWorldDebugDensityMiniMapIndicator;
class UFortAthenaLivingWorldEncounter;
class UFortAthenaLivingWorldEncounterInstance;
class UFortAthenaLivingWorldManager;
class UFortAthenaLivingWorldSpawnAction;
class UFortAthenaSpawnerDataBase;
class UFortSeasonalEventManager;
class UObject;
class UWorld;

UENUM()
enum class EFortAthenaLivingWorldEventRuntimeDeactivationReason : uint8
{
	None = 0,
	NoValidEventData = 1,
	// No valid event data where found for this event.

	RandomDeactivation = 2,
	// Event Random Activation chance is not 100% and the event has been disabled for this match

	CalendarEvent = 3,
	// Calendar event condition are not met

	MatchedPrefabAndNormalActor = 4,
	// An actor description tag query matches at least one LWP and one normal actor and that isn't supported.

	ActorDescDoesntMatchAnySpawnerData = 5,
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnLivingWorldRequestFinished, const TArray<AActor*>&, SpawnedActors, bool, bSuccess);

USTRUCT()
struct FFortLivingWorldConfigOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Lager")
	TSoftObjectPtr<UWorld> SourceWorld;

	UPROPERTY(EditDefaultsOnly, Category="Lager")
	FGameplayTagContainer PlaylistTag;

	UPROPERTY(EditDefaultsOnly, Category="Lager", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaLivingWorldConfigData> LagerConfig;

	UPROPERTY(EditDefaultsOnly, Category="Lager")
	FFortReleaseVersion StartVersion;

	UPROPERTY(EditDefaultsOnly, Category="Lager")
	FFortReleaseVersion EndVersion;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortAthenaLivingWorldManager : public UGameStateComponent, public IFortDataRegistryResolverScopeInterface
{
	GENERATED_BODY()

public:
	UFortAthenaLivingWorldManager(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	virtual bool BuildDataRegistryResolverScope_Implementation(TArray<FName>& InOutResolverScopes, int32& InOutPriority) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void CancelSpawnRequest(const int32 RequestId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void EndEncounter(UFortAthenaLivingWorldEncounterInstance* EncounterInstance);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly, meta=(WorldContext="WorldContextObject"))
	static UFortAthenaLivingWorldManager* GetLivingWorldManager(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	UFortAthenaLivingWorldEncounterInstance* GetOwningEncounter(AActor* Actor) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasPendingSpawnRequestForEncounter(const UFortAthenaLivingWorldEncounterInstance* EncounterInstance) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsEncounterCategoryActive(const TSoftObjectPtr<UFortAthenaLivingWorldEncounter> EncounterType) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerDebugEvent(const FString& EventName, int32 DebugIndex = 0, const FString& RuntimeSpawnDataName = TEXT(""), const FString& EncounterName = TEXT(""));

	UFUNCTION(BlueprintCallable)
	static void LivingWorldManagerDisablePointProvider(AActor* PointProvider);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerDumpEventInstances();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerDumpPrefabLevelBounds();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerDumpSpawnCount();

	UFUNCTION(BlueprintCallable)
	static void LivingWorldManagerEnablePointProvider(AActor* PointProvider);

	UFUNCTION(BlueprintCallable, Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerFlush();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerGenerateEvents();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerProviderDebugActor(int32 ProviderIndex = -1);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="LivingWorldManagerRegisterPointProvider_DEPRECATED"))
	static void LivingWorldManagerRegisterPointProvider(AActor* PointProvider);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void LivingWorldManagerSetEventGenerationEnabled(const bool bInGenerateEvents);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerSwitchDensityDisplay(int32 DensityMapIndex = -1);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerToggleActorMinimap(const FString& Name = TEXT(""));

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerToggleDensityDisplay();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerToggleGenerateEvents();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LivingWorldManagerToggleVerboseLogging();

	UFUNCTION(BlueprintCallable, meta=(DisplayName="LivingWorldManagerUnregisterPointProvider_DEPRECATED"))
	static void LivingWorldManagerUnregisterPointProvider(AActor* PointProvider);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LWMF();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void LWMTAM(const FString& Name = TEXT(""));

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	float QueryActorDensityBudget(AActor* ReferenceActor, float Range = -1.000000f) const;

	UFUNCTION(BlueprintPure)
	int32 QueryEventBudget(FDataTableRowHandle EventEntry, const AActor* SpawnLocation = nullptr) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool RegisterDensityReservoir(AActor* ActorDensityReservoir, float Density, float Range = -1.000000f);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	bool RegisterTagDensityReservoir(AActor* ActorDensityReservoir, const TArray<FFortAthenaLivingWorldEventTagDensityRegistration>& TagsDensity);

	UFUNCTION(BlueprintCallable)
	void RequestEventGeneration();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetEncounter(UFortAthenaLivingWorldEncounterInstance* EncounterInstance);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	UFortAthenaLivingWorldEncounterInstance* StartEncounter(const TSoftObjectPtr<UFortAthenaLivingWorldEncounter> EncounterType, const TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>>& EncounterPointProviders, AActor* ActorDensityReservoir = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, meta=(AutoCreateRefTerm="OnRequestFinished"))
	bool TrySpawnEvent(FDataTableRowHandle EventEntry, const FTransform SpawnLocation, const FOnLivingWorldRequestFinished& OnRequestFinished, int32& RequestId);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterDensityReservoir(AActor* ActorDensityReservoir);

private:
	UFUNCTION()
	void OnActorSpawned(AActor* Actor, int32 RequestId);

	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnDebugSpawnEventSpawned(const TArray<AActor*>& SpawnedActors, bool bSuccess);

	UFUNCTION()
	void OnPatrolPathAdded(AFortAthenaPatrolPath* PatrolPath);

	UFUNCTION()
	void OnRep_ActorClassToPreloadOnClient();

	UFUNCTION()
	void OnRep_DebugDensityMinimapIndicator(UFortAthenaLivingWorldDebugDensityMiniMapIndicator* OldMapIndicator);

	UFUNCTION()
	void OnSpawnedActorDestroy(AActor* DestroyedActor);

	UFUNCTION()
	void OnUnmanagedDensityReservoirActorDestroy(AActor* DestroyedActor);

	UFUNCTION()
	void OnWorldFinishedInitialization(const FGameplayTagContainer& ContextTags);

	UPROPERTY(EditDefaultsOnly, Category="Lager", meta=(AssetBundles="Server"))
	TSoftObjectPtr<UFortAthenaLivingWorldConfigData> DefaultLagerConfig;

	UPROPERTY(EditDefaultsOnly, Category="Lager", meta=(AssetBundles="Server"))
	TArray<FFortLivingWorldConfigOverride> LagerConfigOverrides;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Lager", meta=(AssetBundles="Server"))
	TArray<FFortLivingWorldConfigOverride> EditorOnlyLagerConfigOverrides;
#endif

	UPROPERTY(EditDefaultsOnly, Category="Lager")
	FScalableFloat LagerEnabled;

	UPROPERTY(EditDefaultsOnly, Category="SpawnAction", meta=(AssetBundles="Server"))
	TMap<FGameplayTag, TSubclassOf<UFortAthenaLivingWorldSpawnAction>> TaggedSpawnActionClassMap;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> PointProviders;

	UPROPERTY(Transient)
	int32 RegisteredPointProvidersCount;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debugging", meta=(AllowPrivateAccess="true"))
	FSlateBrush SpecialActorMinimapIconBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debugging", meta=(AllowPrivateAccess="true"))
	FVector2D SpecialActorMinimapIconScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debugging", meta=(AllowPrivateAccess="true"))
	FSlateBrush SpecialActorCompassIconBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Debugging", meta=(AllowPrivateAccess="true"))
	FVector2D SpecialActorCompassIconScale;

	UPROPERTY(Transient)
	TArray<TSubclassOf<UFortAthenaSpawnerDataBase>> SpawnedSingleUseSpawnerData;

	UPROPERTY(Transient)
	TObjectPtr<UWorld> CachedWorld;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaLivingWorldConfigData> CachedConfig;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortAthenaLivingWorldEncounterInstance>> RunningEncounterInstances;

	UPROPERTY(Transient)
	TObjectPtr<UFortSeasonalEventManager> CachedSeasonalEventManager;

	UPROPERTY(ReplicatedUsing=OnRep_ActorClassToPreloadOnClient)
	TArray<TSoftClassPtr<AActor>> ActorClassToPreloadOnClient;

	UPROPERTY(Transient)
	FFortAthenaLivingWorldActorUpdateHandler ActorUpdateHandler;

	UPROPERTY(Transient)
	FFortAthenaLivingWorldPlayerTracker PlayerTracker;

	UPROPERTY(Transient)
	FFortAthenaLivingWorldPreloader Preloader;

	UPROPERTY(Transient)
	FFortAthenaLivingWorldConditionContainer GlobalConditionContainer;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> RuntimePointProviderList;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AActor>> RuntimePointProviderOwners;

	UPROPERTY(Transient)
	TMap<TSubclassOf<UFortAthenaLivingWorldSpawnAction>, TObjectPtr<UFortAthenaLivingWorldSpawnAction>> SpawnActionCache;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaLivingWorldEQSHelper> EQSHelper;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_DebugDensityMinimapIndicator)
	TObjectPtr<UFortAthenaLivingWorldDebugDensityMiniMapIndicator> DebugDensityMinimapIndicator;

};

