// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ReplicationGraph.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "SpecialRelevancyNode.generated.h"

class AActor;
class AFortPlayerController;
class AFortPlayerControllerAthena;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class AFortProjectileBase;
class UFortReplicationGraphNode_SpecialRelevancy;
class USpecialRelevancyComponentBase;

UENUM(BlueprintType)
enum class ESpecialRelevancyMode : uint8
{
	NormalRelevancy = 0,
	SoloRelevancy = 1,
	SquadRelevancy = 2,
	MultiSquad = 3,
	Custom = 4,
	MAX = 5 UMETA(Hidden),
};

USTRUCT()
struct FClientRelevancyGroupEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl PlayerID;

	UPROPERTY()
	int32 RelevancyGroup;

};

USTRUCT(BlueprintType)
struct FRelevantPawnArray
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="RelevantPawnArray")
	TArray<TObjectPtr<AFortPlayerPawn>> PlayerPawns;

};

USTRUCT(BlueprintType)
struct FSpecialActorSpawnData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="SpecialActorSpawnData")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(BlueprintReadWrite, Category="SpecialActorSpawnData")
	FTransform Transform;

	UPROPERTY(BlueprintReadWrite, Category="SpecialActorSpawnData")
	TObjectPtr<AActor> Owner;

};

USTRUCT()
struct FSpecialRelevancyGroup
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerAthena>> Controllers;

	UPROPERTY()
	TArray<TObjectPtr<AActor>> SpecialActors;

};

USTRUCT()
struct FSpecialRelevancyModeData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialRelevancyModeData")
	ESpecialRelevancyMode Mode;

private:
	UPROPERTY(NotReplicated)
	int32 NumberOfSquads;

};

USTRUCT()
struct FSpecialRelevancyMultiSquadControllerGroup
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerControllerAthena>> Controllers;

};

USTRUCT()
struct FSpecialRelevancyMultiSquadControllerGroupsContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FSpecialRelevancyMultiSquadControllerGroup> ControllerGroups;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_SpecialRelevancy : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FORTNITEGAME_API bool AreActorsInSameRelvancyGroup(const AActor* Actor0, const AActor* Actor1) const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	FORTNITEGAME_API int32 FindRelevancyGroupIndex(const AActor* Actor) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API void GetActors(TArray<AActor*>& OutActors, const int32 RelevancyGroupIndex, TSubclassOf<AActor> ActorClass = nullptr) const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API int32 GetMaxSquadSize() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API int32 GetNumRelevancyGroups() const;

	UFUNCTION(BlueprintPure)
	FORTNITEGAME_API void GetPlayerPawns(TArray<AFortPlayerPawn*>& OutPawns, const int32 RelevancyGroupIndex) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, BlueprintAuthorityOnly)
	FORTNITEGAME_API void GetRelevantPawnGroups(TArray<FRelevantPawnArray>& RelevantPawns) const;

	UFUNCTION(BlueprintCallable)
	FORTNITEGAME_API void PlacePawnOnPlayerStart(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SetClientAuthoritativePhysics(bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void SpawnActorPerRelevancyGroup(const FSpecialActorSpawnData& NewSpawnData, TArray<AActor*>& SpawnedActors);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void StartMultiSquadRelevancy(int32 NumOfSquadsInRelevancyGroup);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void StartNormalRelevancy();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void StartSoloRelevancy();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FORTNITEGAME_API void StartSquadRelevancy();

	UPROPERTY(EditDefaultsOnly, Category="Replication Graph")
	TSubclassOf<UFortReplicationGraphNode_SpecialRelevancy> RootGridNodeClass;

protected:
	UFUNCTION()
	FORTNITEGAME_API void OnRep_CurrentRelevancyMode(FSpecialRelevancyModeData PrevMode);

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_CurrentRelevancyMode, Category="Relevancy", meta=(DisplayName="Starting Relevancy Mode"))
	FSpecialRelevancyModeData CurrentRelevancyModeData;

	UPROPERTY(Replicated)
	TArray<FClientRelevancyGroupEntry> ClientRelevancyGroups;

	UPROPERTY(EditDefaultsOnly, Category="Special Actors")
	TSubclassOf<AFortPlayerPawn> PlayerPawnClass;

	UPROPERTY(EditDefaultsOnly, Category="Special Actors")
	TArray<TSubclassOf<AFortProjectileBase>> ProjectileClasses;

	UPROPERTY(EditAnywhere, Category="UI", meta=(ArraySizeEnum="/Script/FortniteGame.ESpecialRelevancyMode"))
	FGameplayTagContainer TagsToHideOnRelevancyMode[5];

	UPROPERTY(EditAnywhere, Category="Player Start")
	bool bUseSpecialRelevancyPlayerStarts;

	UPROPERTY(Transient)
	TObjectPtr<UFortReplicationGraphNode_SpecialRelevancy> SpecialRelevancyNode;

	UPROPERTY(Config)
	bool bEnablePlacePawnOnPlayerStart;

private:
	UPROPERTY()
	TArray<FSpecialRelevancyMultiSquadControllerGroupsContainer> MultiSquadControllerGroupsContainers;

};

UCLASS()
class UFortCheatManager_SpecialRelevancy : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

protected:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartMultiSquadRelevancy(int32 NumOfSquadsInRelevancyGroup);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartNormalRelevancy();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartSoloRelevancy();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartSquadRelevancy();

};

UCLASS(Config=Game, MinimalAPI)
class UFortReplicationGraphNode_SpecialRelevancy : public UReplicationGraphNode_GridSpatialization2D
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnSquadIdChanged(AFortPlayerStateAthena* PlayerState, const uint8 OldSquadIndex);

	UPROPERTY()
	TArray<FSpecialRelevancyGroup> RelevancyGroups;

	UPROPERTY()
	TSubclassOf<AFortPlayerPawn> PlayerPawnClass;

	UPROPERTY()
	TArray<TSubclassOf<AFortProjectileBase>> ProjectileClasses;

	UPROPERTY()
	TArray<TSubclassOf<AActor>> SpecialActorClasses;

	UPROPERTY()
	FSpecialRelevancyModeData CurrentRelevancyModeData;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USpecialRelevancyComponentBase>> RelevancyComponents;

	UPROPERTY(Config)
	bool bUseFastCompPath;

	UPROPERTY(Config)
	int32 MostToUpdateIn1Frame;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USpecialRelevancyComponentBase>> FastCompPathArray;

};

