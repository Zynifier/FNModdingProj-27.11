// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortAbilitySetHandle.h"
#include "Athena/Modifiers/FortAthenaMutator_PerkSystemMutator.h"
#include "Components/FortControllerComponent.h"
#include "SpyTechPerkSystemPlayerControllerComponent.generated.h"

class UFortAccoladeItemDefinition;
class UFortSpyTechItemDefinition;

USTRUCT(BlueprintType)
struct FFutureTechData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FutureTechData")
	int32 UnlockLevel;

	UPROPERTY(BlueprintReadOnly, Category="FutureTechData")
	int32 XpToGetThisLevelFromRoundStartLevel;

	UPROPERTY(BlueprintReadOnly, Category="FutureTechData")
	int32 SingleLevelRequiredXp;

	UPROPERTY(BlueprintReadOnly, Category="FutureTechData")
	TObjectPtr<UFortSpyTechItemDefinition> PerkItemDef;

};

USTRUCT(BlueprintType)
struct FPerkAccoladeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PerkAccoladeInfo")
	int32 Index;

	UPROPERTY(BlueprintReadOnly, Category="PerkAccoladeInfo")
	TObjectPtr<UFortAccoladeItemDefinition> AccoladeDef;

	UPROPERTY(BlueprintReadOnly, Category="PerkAccoladeInfo")
	int32 PipCount;

};

USTRUCT()
struct FPerkItemSet
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> Items;

	UPROPERTY()
	float Time;

};

USTRUCT(BlueprintType)
struct FRoundTechDataCache
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	TArray<FFutureTechData> FuturePerks;

	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	int32 LevelAtRoundStart;

	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	int32 FactionXPAtRoundStart;

	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	bool bDataReady;

	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	int32 MaxCalandarLevel;

	UPROPERTY(BlueprintReadOnly, Category="RoundTechDataCache")
	int32 MaxLevel;

};

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_SpyTechPerkSystem : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_AllSelectedPerks();

	UFUNCTION()
	void OnRep_MutatorData();

	UFUNCTION()
	void OnRep_PerkSelection();

	UFUNCTION()
	void OnRep_RerollCount();

	UFUNCTION()
	void OnRep_ServerTimeToRelease();

	UFUNCTION()
	void OnRep_SpyTechArray();

	UPROPERTY(ReplicatedUsing=OnRep_ServerTimeToRelease)
	float ServerTimeToRelease;

	UPROPERTY(ReplicatedUsing=OnRep_RerollCount)
	int32 RerollCount;

	UPROPERTY(ReplicatedUsing=OnRep_AllSelectedPerks)
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> AllSelectedPerks;

	UPROPERTY()
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> DefaultPerks;

	UPROPERTY(ReplicatedUsing=OnRep_PerkSelection)
	TArray<FPerkItemSet> PerkSelection;

	UPROPERTY(ReplicatedUsing=OnRep_SpyTechArray)
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> SpyTechArray;

	UPROPERTY()
	TArray<FPerkAccoladeInfo> AllPerkAccolades;

	UPROPERTY(ReplicatedUsing=OnRep_MutatorData)
	FPerkMutatorData MutatorData;

	UPROPERTY(Replicated)
	FGameplayTag CachedFactionTag;

	UPROPERTY()
	FRoundTechDataCache RoundStartCache;

	UPROPERTY()
	TArray<FFortAbilitySetHandle> AbilitySetHandles;

	UPROPERTY()
	TArray<FActiveGameplayEffectHandle> GEHandles;

};

