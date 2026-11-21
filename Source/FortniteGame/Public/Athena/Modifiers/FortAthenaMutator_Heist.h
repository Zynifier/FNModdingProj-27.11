// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortSpecialActorReplicationInfo.h"
#include "FortTypes.h"
#include "FortAthenaMutator_Heist.generated.h"

class AFortAthenaExitCraft;
class AFortAthenaExitCraftSpawner;
class AFortPlayerPawnAthena;
class AFortPlayerStateAthena;
class UFortAthenaExitCraftInfo;
class USoundCue;
class UTexture2D;

UENUM()
enum class EHeistExitCraftState : uint8
{
	None = 0,
	Incoming = 1,
	Spawned = 2,
	Exited = 3,
};

USTRUCT(BlueprintType)
struct FHeistBlingDropSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistBlingDropSpawnData")
	FScalableFloat SafeZonePhaseWhereToSpawn;

};

USTRUCT()
struct FHeistExitCraftData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortAthenaExitCraftSpawner> ExitCraftSpawner;

	UPROPERTY()
	TObjectPtr<AFortAthenaExitCraft> SpawnedExitCraft;

	UPROPERTY()
	EHeistExitCraftState ExitCraftState;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawnAthena>> DepartedPawns;

	UPROPERTY()
	float SpawnTime;

	UPROPERTY()
	bool bIsUsed;

	UPROPERTY()
	bool bHasDeparted;

};

USTRUCT(BlueprintType)
struct FHeistExitCraftSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftSpawnData")
	FScalableFloat SpawnDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftSpawnData")
	FScalableFloat SafeZonePhaseWhenToSpawn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftSpawnData")
	FScalableFloat SafeZonePhaseWhereToSpawn;

};

USTRUCT()
struct FHeistPostMatchAnalyticsData
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	int32 SupplyDropsOpenedPerMatch;

	UPROPERTY(Transient)
	int32 JewelsLostToStorm;

	UPROPERTY(Transient)
	int32 HeistDropsLostToStorm;

	UPROPERTY(Transient)
	int32 JewelsEquippedPerMatch;

	UPROPERTY(Transient)
	TArray<float> TimeJewelHeldPerTeam;

	UPROPERTY(Transient)
	TArray<int32> PlayersAlivePerEscape;

	UPROPERTY(Transient)
	int32 NumSuccessfulEscapes;

	UPROPERTY(Transient)
	TArray<uint8> WinningTeams;

};

USTRUCT()
struct FHeistTeamHoldingJewelInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 JewelsHeld;

	UPROPERTY()
	float TimeStartedHoldingJewel;

	UPROPERTY()
	float AccumulatedTotalTime;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Heist : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnExitCraftIsDestroying(AFortAthenaExitCraft* ExitCraft);

	UFUNCTION()
	void OnExitCraftSpawned(AFortAthenaExitCraft* ExitCraft, AFortAthenaExitCraftSpawner* ExitCraftSpawner);

	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnMutatorGenericIntegerUpdated(int32 GenericIntegerIndex, int32 NewIntegerValue);

	UFUNCTION()
	void OnSpecialActorAdded(const FSpecialActorRepData& SpecialActorData);

	UFUNCTION()
	void OnSpecialActorRemoved(const FSpecialActorRepData& SpecialActorData);

	UFUNCTION()
	void SendPlayerAcquiredMessage(AFortPlayerStateAthena* CarryingPlayerState);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	TObjectPtr<UFortAthenaExitCraftInfo> ExitCraftInfo;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	TArray<FHeistExitCraftSpawnData> HeistExitCraftSpawnData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	TArray<FHeistBlingDropSpawnData> HeistBlingDropSpawnData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	TObjectPtr<USoundCue> HeistVictorySoundCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FScalableFloat SpawnExitCraftInitialDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FScalableFloat BlingCarryingEnemiesVisibleTime;

	UPROPERTY(Transient)
	TArray<FHeistExitCraftData> SpawnedExitCraftList;

	UPROPERTY(Transient)
	bool bCurrExitCraftDeparted;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AFortPlayerPawnAthena>> ExitCraftOverlappingPawns;

	UPROPERTY(Transient)
	float SpawnExitCraftTime;

	UPROPERTY(Transient)
	int32 CurrExitCraftIndexToSpawn;

	UPROPERTY(Transient)
	float SupplyDropStartingAngle;

	UPROPERTY(Transient)
	float ExitCraftStartingAngle;

	UPROPERTY(Transient)
	int32 CurrBlingSupplyDropIndexHandled;

	UPROPERTY(Transient)
	TArray<int32> RemainingExitCraftSpawnIndexes;

	UPROPERTY(Transient)
	TArray<int32> RemainingSupplyDropSpawnIndexes;

	UPROPERTY(Transient, Replicated)
	int32 NumUnspawnedExitCrafts;

	UPROPERTY(Transient, Replicated)
	int32 NumSpawnedExitCrafts;

	UPROPERTY(Transient, Replicated)
	int32 NumDepartedExitCrafts;

	UPROPERTY(Transient)
	TArray<int32> NumPlayersAliveOnDeparture;

	UPROPERTY(Transient)
	int32 JewelsLostToStorm;

	UPROPERTY(Transient)
	int32 SafesLostToStorm;

	UPROPERTY(Transient)
	TMap<uint8, FHeistTeamHoldingJewelInfo> JewelHeldByTeamMap;

	UPROPERTY(Transient)
	FGameplayTag BlingTrackingCategoryTag;

	UPROPERTY(Transient)
	FGameplayTag SafeSupplyDropTag;

	UPROPERTY(Transient)
	FGameplayTag BlingItemTag;

	UPROPERTY(Transient)
	FGameplayTag CarryingBlingItemTag;

	UPROPERTY(Transient)
	FGameplayTag ExitCraftTag;

	UPROPERTY(Transient)
	FGameplayTag BlingLootItemTag;

	UPROPERTY(Transient)
	float LastAcquiredEnemyMsgTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	float MinTimeAllowedBetweenAcquiredEnemyMessages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_InitialBlingIncoming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_InitialExitCraftsIncoming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_FinalExitCraftIncoming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_HeistCompleted;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_HeistCompletedOneRemains;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_DiamondAcquiredByEnemy;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_DiamondAcquiredByAlly;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_DiamondAcquiredByAllyNoVans;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_DiamondAcquiredByLocalPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeistMessages")
	FAthenaGameMessageData GameMsg_DiamondAcquiredByLocalPlayerNoVans;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FSlateBrush FriendlyCarrierBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FVector2D FriendlyCarrierBrushScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FSlateBrush CompassFriendlyCarrierBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FSlateBrush EnemyCarrierBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FVector2D EnemyCarrierBrushScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	FSlateBrush CompassEnemyCarrierBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_Heist")
	TObjectPtr<UTexture2D> IconToShowInSquadBar;

};

