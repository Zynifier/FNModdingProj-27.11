// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortGameMode.h"
#include "FortItemAndCount.h"
#include "FortSubGameTypes.h"
#include "FortTypes.h"
#include "FortGameModeZone.generated.h"

class ABuildingSMActor;
class AFortAIDirector;
class AFortAIGoalManager;
class AFortMission;
class AFortPlayerStartupController;
class APlayerController;
class UFortBuildingOctreeManager;
class UFortPetManager;
class UFortTaggedActorsManager;
class UGameplayEffect;
enum class EFortReportDayPhase : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNotifyPlayerLogin, APlayerController*, PlayerController);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHandleMatchHasStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHandleZonePeriodicReport, EFortReportDayPhase, ReportEventType);

USTRUCT()
struct FBCActionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 Type;

	UPROPERTY()
	int32 Action;

};

USTRUCT()
struct FRejoinScoreMemory
{
	GENERATED_BODY()

};

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameMode_InGame : public AFortGameMode
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameModeZone : public AFortGameMode_InGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fort Game Mode")
	AFortPlayerStartupController* GetPlayerStartupController();

	UFUNCTION(BlueprintNativeEvent, Category="Death")
	TSubclassOf<UGameplayEffect> GetTeammateReviveGameplayEffectOverride();

	UFUNCTION()
	virtual bool IsGameReadyToSelectLoot() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Death")
	bool IsSpectatingAllowedAfterDeath() const;

	UFUNCTION()
	virtual void OnEveningReached();

	UFUNCTION()
	virtual void OnMorningReached();

	UFUNCTION()
	virtual void ReplicateHealthAndShield();

	UFUNCTION(BlueprintCallable)
	void SetActiveSpawnPad(ABuildingSMActor* InActiveSpawnPad);

	UFUNCTION(BlueprintCallable, Category="GameMode")
	void SetEnemyAIItemCacheLootDrops(bool bValue);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Matchmaking")
	virtual void SetJoinability(bool bMatchJoinable);

	UFUNCTION(BlueprintCallable, Category="LootData")
	void SetZoneLootNamedWeightsMapOverride(const TMap<FName, float>& NewOverrideMap);

	UPROPERTY(BlueprintAssignable, Category="Login")
	FNotifyPlayerLogin OnPlayerLogin;

	UPROPERTY(Transient)
	uint8 bSpawnAllStuff : 1;

	UPROPERTY(Transient)
	uint8 bDisableAI : 1;

	UPROPERTY(Transient)
	uint8 bInitBeaconAtInitGame : 1;

	UPROPERTY()
	int32 OverrideAIDirectorIndex;

	UPROPERTY()
	TObjectPtr<ABuildingSMActor> ActiveSpawnPad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="LootData")
	TMap<FName, float> ZoneLootNamedWeightsMapOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameMode")
	float StormWindInactiveMagnitudeScalar;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GameMode")
	float StormWindActiveMagnitudeScalar;

protected:
	UFUNCTION(BlueprintCallable, Category="Fort Game Mode")
	void ClearPlayerStartLocationOverrides();

	UFUNCTION(BlueprintCallable, Category="Fort Game Mode")
	void SetPlayerStartLocationOverrides(TArray<FVector> InPlayerStarts, AFortMission* InMission);

	UFUNCTION(BlueprintCallable, Category="Fort Game Mode")
	void SetSpawnWithinStormShield(bool bSpawnInStormShield);

	UPROPERTY(Config)
	bool bDisableVoiceChat;

	UPROPERTY(Config)
	FString ReplayStreamerOverride;

	UPROPERTY()
	TObjectPtr<AFortAIDirector> AIDirector;

	UPROPERTY()
	TObjectPtr<AFortAIGoalManager> AIGoalManager;

	UPROPERTY()
	int32 EndOfZoneRemainTime;

	UPROPERTY()
	TObjectPtr<UFortTaggedActorsManager> TaggedActorsManager;

	UPROPERTY()
	TObjectPtr<UFortBuildingOctreeManager> BuildingOctreeManager;

	UPROPERTY(EditDefaultsOnly, Category="Spawn")
	bool bUseAllSocketsInSpawnPad;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Death")
	bool bAllowSpectateAfterDeath;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Death")
	bool bForceSpectateAfterDeathRegardlessOfRespawnTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Death")
	FScalableFloat SpectateAfterDeath_DelayFirst;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Death", meta=(EditCondition="bAllowSpectateAfterDeath"))
	float SpectateAfterDeath_DelayRepeating;

	UPROPERTY(Config)
	TArray<FHotfixVolumePlacement> HotfixBehaviorVolumes;

	UPROPERTY(Config)
	bool bCriticalMissionEligible;

	UPROPERTY()
	TObjectPtr<UFortPetManager> PetManager;

	UPROPERTY(EditAnywhere, Category="LootData")
	TArray<FItemAndCount> StartingItems;

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bAllowEnemyAIWorldItemLootDrops : 1;

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bAllowEnemyAIItemCacheLootDrops : 1;

	UPROPERTY(EditDefaultsOnly, Category="LootData")
	uint8 bAllowContainerItemCacheLootDrops : 1;

	UPROPERTY(BlueprintAssignable)
	FOnHandleZonePeriodicReport OnHandleZonePeriodicReport;

	UPROPERTY(BlueprintAssignable)
	FOnHandleMatchHasStarted OnHandleMatchHasStarted;

	UPROPERTY(Config)
	bool bTrustXboxPlatformId;

	UPROPERTY(EditDefaultsOnly, Category="GameMode")
	ESubGame AssociatedSubGame;

	UPROPERTY(EditDefaultsOnly, Category="GameMode")
	FSlateBrush BluGloMiniMapIconBrushOverride;

	UPROPERTY(BlueprintReadWrite, Category="Fort Game Mode")
	bool bTryToSpawnWithinStormShield;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	bool bSupportOneHitBuildingActorRecycling;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="GameMode")
	bool bOneHitResourcesGoToOwner;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameModeZone")
	bool bEnableLongRangeAutoPickup;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameModeZone")
	float LongRangeAutoPickupInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortGameModeZone")
	float LongRangeAutoPickupRadius;

private:
	UPROPERTY()
	TArray<FVector> PlayerStartLocationOverrides;

};

UCLASS(HideCategories=("Info", "Rendering", "MovementReplication", "Replication", "Actor", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameMode_InGame_Custom : public AFortGameMode_InGame
{
	GENERATED_BODY()

};

