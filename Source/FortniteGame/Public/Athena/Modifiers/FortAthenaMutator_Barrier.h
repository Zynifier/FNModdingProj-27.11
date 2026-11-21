// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/GameStateComponents/FortGameStateComponent_BattleRoyaleGamePhaseLogic.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_Barrier.generated.h"

class AAthenaBarrierFlag;
class AAthenaBarrierObjective;
class AAthenaBigBaseWall;
class UCustomCharacterPart;
class UFortWorldItemDefinition;
class UMaterialInterface;

UENUM(BlueprintType)
enum class EBarrierFoodTeam : uint8
{
	Burger = 0,
	Tomato = 1,
	MAX = 2,
};

UENUM(BlueprintType)
enum class EBarrierObjectiveDamageState : uint8
{
	Health_75 = 0,
	Health_50 = 1,
	Health_25 = 2,
	Health_10 = 3,
	Health_5 = 4,
	Health_4 = 5,
	Health_3 = 6,
	Health_2 = 7,
	Health_1 = 8,
	MAX = 9,
};

USTRUCT()
struct FBarrierHeadData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BarrierHeadData")
	TArray<TObjectPtr<UCustomCharacterPart>> PartsToSwapIn;

};

USTRUCT()
struct FBarrierMountedTurretData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="BarrierMountedTurretData")
	TArray<TObjectPtr<UMaterialInterface>> MaterialOverrides;

	UPROPERTY(EditAnywhere, Category="BarrierMountedTurretData")
	TObjectPtr<UMaterialInterface> BaseMaterialOverride;

};

USTRUCT()
struct FBarrierTeamState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 TeamNum;

	UPROPERTY()
	EBarrierFoodTeam FoodTeam;

	UPROPERTY()
	TObjectPtr<AAthenaBarrierFlag> ObjectiveFlag;

	UPROPERTY()
	TObjectPtr<AAthenaBarrierObjective> ObjectiveObject;

	UPROPERTY()
	bool bRespawnEnabled;

};

USTRUCT()
struct FItemsToSpawn
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemsToSpawn")
	TObjectPtr<UFortWorldItemDefinition> ItemToDrop;

	UPROPERTY(EditAnywhere, Category="ItemsToSpawn")
	FScalableFloat NumberToDrop;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "HLOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Barrier : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void CheckHealthThreshold(uint8 TeamNum);

	UFUNCTION()
	void OnGamePhaseStepChanged(const FFortGamePhaseStepUpdatedEvent& Event);

	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UPROPERTY(EditAnywhere, Category="Wall")
	TSubclassOf<AAthenaBigBaseWall> BigBaseWallClass;

	UPROPERTY(EditAnywhere, Category="Objectives")
	TSubclassOf<AAthenaBarrierFlag> ObjectiveFlag;

	UPROPERTY(Replicated)
	bool bGameEndsWhenObjectiveIsDestroyed;

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EBarrierFoodTeam"))
	FBarrierHeadData FoodHeadData[2];

	UPROPERTY(EditAnywhere, Category="Display Data", meta=(ArraySizeEnum="/Script/FortniteGame.EBarrierFoodTeam"))
	FBarrierMountedTurretData MountedTurretOverrideMaterials[2];

	UPROPERTY(Replicated)
	TObjectPtr<AAthenaBigBaseWall> BigBaseWall;

	UPROPERTY(Replicated)
	FBarrierTeamState Team_0_State;

	UPROPERTY(Replicated)
	FBarrierTeamState Team_1_State;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectiveDistanceFromWall;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat SafeZonePhaseToStartObjectiveDestructionTimer;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectiveDestructionTimer;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat StartObjectiveDamageOnSpecialEvent;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectiveZOffset;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectiveMaxZDiff;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectiveMaxSpawnHeight;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat ObjectivesSpawnSameHeight;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables")
	FScalableFloat LavaLevelRelativeToMascot;

	UPROPERTY(EditDefaultsOnly, Category="Objective Scalables", meta=(ArraySizeEnum="/Script/FortniteGame.EBarrierObjectiveDamageState"))
	FScalableFloat ObjectiveHealthTiers[9];

	UPROPERTY(EditDefaultsOnly, Category="Wall Scalables")
	FScalableFloat WallGravity;

	UPROPERTY(EditDefaultsOnly, Category="Wall Scalables")
	FScalableFloat SafeZonePhaseWhenToBringDownWall;

	UPROPERTY(EditDefaultsOnly, Category="Wall Scalables")
	FScalableFloat TimeToBringDownWall;

	UPROPERTY(EditDefaultsOnly, Category="Respawn Data")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(EditDefaultsOnly, Category="Respawn Data")
	FScalableFloat SafeZonePhaseToTurnOffRespawning;

	UPROPERTY(EditDefaultsOnly, Category="Respawn Data")
	FScalableFloat HealthToWarnAboutRespawnsAt;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_Intro;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_WallComingDown;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_WallDown;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_Objective_Destroyed_Friendly;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_Objective_Destroyed_Friendly_NotGameOver;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_Objective_Destroyed_Enemy;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_NoMoreRespawnsWarning_Friendly;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_NoMoreRespawns_Friendly;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages")
	FAthenaGameMessageData GameMsg_NoMoreRespawns_Enemy;

	UPROPERTY(EditDefaultsOnly, Category="Barrier Messages", meta=(ArraySizeEnum="/Script/FortniteGame.EBarrierObjectiveDamageState"))
	FAthenaGameMessageData GameMsg_ObjectiveDamageState_Friendly[9];

};

