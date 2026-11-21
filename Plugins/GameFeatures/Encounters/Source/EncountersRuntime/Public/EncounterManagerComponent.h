// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "StateTreeExecutionTypes.h"
#include "EncounterManagerComponent.generated.h"

class AActor;
class ABuildingActor;
class AEncounterGameplayVolume;
class APlayerController;
class UDataTable;
class UEncounterItem;
class UFortAthenaLivingWorldEncounter;
class UFortWorldItemDefinition;
class ULWMEncounterInstance;

USTRUCT()
struct FEncounterGroupEffectInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FGameplayEffectIdentifierInfo
{
	GENERATED_BODY()

};

USTRUCT()
struct FLWMEncounterInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<ULWMEncounterInstance> LWMEncounter;

};

USTRUCT()
struct FSpawnedActorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> SpawnedActor;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UEncounterManagerComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UEncounterManagerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void AddExplicitContributor(APlayerController* Contributor);

	UFUNCTION(BlueprintPure)
	TSoftClassPtr<AActor> GetVariable_ActorClass(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	bool GetVariable_Bool(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	float GetVariable_Float(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	FGameplayTag GetVariable_GameplayTag(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	int32 GetVariable_Int(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	const UFortWorldItemDefinition* GetVariable_ItemDefinition(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	const UFortAthenaLivingWorldEncounter* GetVariable_LWMEncounter(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintPure)
	FGameplayTagQuery GetVariable_TagQuery(const FGameplayTag& VarName) const;

	UFUNCTION(BlueprintCallable)
	void HandleEncounterFailure(int32 RewardIndex = 0);

	UFUNCTION(BlueprintCallable)
	void HandleEncounterSuccess(int32 RewardIndex = 0);

	UFUNCTION(BlueprintCallable)
	void RemoveExplicitContributor(APlayerController* Contributor);

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="EncounterManagerComponent")
	TWeakObjectPtr<AEncounterGameplayVolume> EncounterVolume;

	UPROPERTY(EditAnywhere, Category="EncounterManagerComponent")
	TWeakObjectPtr<AActor> CenterActorOverride;

	UPROPERTY(EditAnywhere, Category="EncounterManagerComponent")
	TArray<TWeakObjectPtr<ABuildingActor>> PermanentActors;

	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/LagerRuntime.FortAthenaLivingWorldEvent"))
	FDataTableRowHandle PostEncounterLWMEvent;

	UPROPERTY(EditAnywhere, Category="Encounter", meta=(RowType="/Script/LagerRuntime.FortAthenaLivingWorldCategory"))
	FDataTableRowHandle PostEncounterLWMCategory;

	UPROPERTY(Transient)
	TSet<TObjectPtr<APlayerController>> ExplicitContributors;

private:
	UFUNCTION()
	void OnStateTreeStatusChanged(EStateTreeRunStatus Status);

	UPROPERTY(Transient)
	TArray<FLWMEncounterInfo> EncounterInfos;

	UPROPERTY(Transient)
	TArray<FGameplayEffectIdentifierInfo> GameplayEffectInfos;

	UPROPERTY(Transient)
	TWeakObjectPtr<UEncounterItem> EncounterItem;

	UPROPERTY(Transient)
	TSoftObjectPtr<UDataTable> LWMEncounterTable;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> LastThreat;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ReservoirActor;

	UPROPERTY(Transient)
	TArray<FSpawnedActorInfo> SpawnedActorInfos;

};

