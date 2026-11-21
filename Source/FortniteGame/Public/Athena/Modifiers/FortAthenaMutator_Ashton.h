// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Athena/AthenaGameMessage.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortTypes.h"
#include "FortAthenaMutator_Ashton.generated.h"

class AFortGameModePickup;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class UFortGadgetItemDefinition;
class UFortItemDefinition;
class UFortWorldItemDefinition;
enum class EAshtonStoneStateType : uint8;
enum class EAshtonStoneType : uint8;

UENUM(BlueprintType)
enum class EAshtonStoneStateType : uint8
{
	NotSpawned = 0,
	Spawned = 1,
	Captured = 2,
	MAX = 3,
};

UENUM(BlueprintType)
enum class EAshtonStoneType : uint8
{
	Purple = 0,
	Blue = 1,
	Red = 2,
	Orange = 3,
	Green = 4,
	Yellow = 5,
	MAX = 6,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshtonStoneListChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAshtonVillainRespawnsRemainingChanged);

USTRUCT(BlueprintType)
struct FAshtonStoneData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AshtonStoneData")
	EAshtonStoneType StoneType;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	TObjectPtr<UFortWorldItemDefinition> StoneItemDefinition;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	FSlateBrush StoneIconBrush;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	FVector2D MapIconScale;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	FGameplayTag GameplayTag;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	FGameplayTag PickupTag;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneData")
	EAshtonStoneStateType InitialStoneState;

};

USTRUCT(BlueprintType)
struct FAshtonStoneSpawnData : public FFortPieSliceSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AshtonStoneSpawnData")
	FScalableFloat SpawnDelay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AshtonStoneSpawnData")
	FScalableFloat SpawnSafeZoneIndex;

};

USTRUCT(BlueprintType)
struct FAshtonStoneState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneState")
	EAshtonStoneType StoneType;

	UPROPERTY(EditDefaultsOnly, Category="AshtonStoneState")
	EAshtonStoneStateType StoneState;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="AshtonStoneState")
	FGameplayTag GameplayTag;

	UPROPERTY(Transient, NotReplicated)
	float SpawnTime;

	UPROPERTY(Transient, NotReplicated)
	bool bHasEverSpawned;

	UPROPERTY(Transient, NotReplicated)
	int32 SpawnDataIdx;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_Ashton : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 GetNumCapturedStones(const TArray<FAshtonStoneState>& TestList);

	UFUNCTION(BlueprintCallable)
	EAshtonStoneStateType GetStoneState(EAshtonStoneType StoneType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayVillainLeaderDiedSound(FVector SoundLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayVillainLeaderSnapSound(FVector SoundLocation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayVillainLeaderSpawnedSound(FVector SoundLocation);

	UPROPERTY(BlueprintAssignable)
	FOnAshtonStoneListChanged OnStoneListChanged;

	UPROPERTY(BlueprintAssignable)
	FOnAshtonVillainRespawnsRemainingChanged OnVillainRespawnsRemainingChanged;

protected:
	UFUNCTION()
	void OnMutatorGameplayEvent(int32 EventId, int32 EventParam1, int32 EventParam2, int32 EventParam3);

	UFUNCTION()
	void OnPickupDestroying(AFortGameModePickup* PickupObj, const UFortItemDefinition* PickupItemDef);

	UFUNCTION()
	void OnPickupSpawnedAndReady(AFortGameModePickup* PickupObj, const UFortItemDefinition* PickupItemDef);

	UFUNCTION()
	void OnRep_NumVillainRespawnsRemaining();

	UFUNCTION()
	void OnRep_StoneList();

	UFUNCTION()
	void OnRep_VillainLeaderLocationForDeathSound();

	UFUNCTION()
	void OnRep_VillainLeaderLocationForSnapSound();

	UFUNCTION()
	void OnRep_VillainLeaderLocationForSound();

	UFUNCTION()
	void SelectNextVillainLeader();

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FScalableFloat GameOverDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton", meta=(ArraySizeEnum="/Script/FortniteGame.EAshtonStoneType"))
	FAshtonStoneData StoneDataList[6];

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton", meta=(ArraySizeEnum="/Script/FortniteGame.EAshtonStoneType"))
	FAshtonStoneSpawnData StoneSpawnDataList[6];

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_StoneList, Category="FortAthenaMutator_Ashton")
	TArray<FAshtonStoneState> StoneList;

	UPROPERTY(Transient)
	TArray<FAshtonStoneState> CachedStoneList;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_VillainLeaderLocationForSnapSound, Category="FortAthenaMutator_Ashton")
	FVector VillainLeaderLocationForSnapSound;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_VillainLeaderLocationForDeathSound, Category="FortAthenaMutator_Ashton")
	FVector VillainLeaderLocationForDeathSound;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_VillainLeaderLocationForSound, Category="FortAthenaMutator_Ashton")
	FVector VillainLeaderLocationForSound;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FGameplayTag JimInventoryTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FGameplayTag JimPickupTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FGameplayTag VillainTeamTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FGameplayTag HeroTeamTag;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FGameplayTagContainer ForceEquipTags;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FSlateBrush MapEnemyBrush;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FVector2D MapEnemyScale;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerController> AutoEquipController;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	TObjectPtr<UFortGadgetItemDefinition> VillainLeaderItemDef;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	TArray<TObjectPtr<UFortWorldItemDefinition>> VillainItemDefs;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerControllerAthena> VillainLeaderPC;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FFortRespawnLogicData RespawnLogicData;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FScalableFloat NumVillainRespawns;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_NumVillainRespawnsRemaining)
	int32 NumVillainRespawnsRemaining;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FScalableFloat PromoteNextVillainLeaderDelay;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_Ashton")
	FScalableFloat VillainsDisplayStoneIcons;

	UPROPERTY(Transient, Replicated)
	int32 CachedNumCapturedStones;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_IntroVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_IntroHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_RespawnVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_RespawnHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_HeroFollowMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FirstStoneComingVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FirstStoneComingHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StoneComingVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StoneComingHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FirstStoneCapturedVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FirstStoneCapturedHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StoneCapturedVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StoneCapturedHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_OneStoneLeftVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_OneStoneLeftHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FinalStoneComingVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_FinalStoneComingHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_EliminatedThanosVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_EliminatedThanosHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_RespawnThanosVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_RespawnThanosHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StonesCompleteVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_StonesCompleteHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_VillainArmyDepletedVillain;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_VillainArmyDepletedHero;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Messages")
	FAthenaGameMessageData GameMsg_NoMoreRespawns;

};

