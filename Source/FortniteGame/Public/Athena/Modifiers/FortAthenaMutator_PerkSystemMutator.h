// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_PerkSystemMutator.generated.h"

class AFortPlayerControllerAthena;
class UFortSpyTechItemDefinition;
class UGameplayEffect;
class UUserWidget;

USTRUCT(BlueprintType)
struct FForcedPerks
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ForcedPerks")
	TObjectPtr<UFortSpyTechItemDefinition> ForcedItems[6];

};

USTRUCT(BlueprintType)
struct FPerkMutatorData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag PerkTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag ShowPerkSelectTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag PassivePerkTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag ItemPerkTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag FirstRollTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FGameplayTag BlockRespawnTag;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	TSubclassOf<UGameplayEffect> PerkUnlockedGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	TSubclassOf<UGameplayEffect> ShowPerkSelectGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	TSubclassOf<UGameplayEffect> BlockRespawnGameplayEffectClass;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData", meta=(AllowedClasses="/Script/FortniteUI.PerkIntroScreenWidget"))
	TSubclassOf<UUserWidget> PerkScreenIntroWidgetClass;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FScalableFloat StartingRerollCount;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FScalableFloat RerollsToGivePerPerkUnlock;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	FScalableFloat MaxRerollsPerPlayer;

	UPROPERTY(EditAnywhere, NotReplicated, Category="PerkMutatorData")
	TMap<FName, FGameplayTag> FactionItemMapping;

	UPROPERTY(EditAnywhere, Category="PerkMutatorData")
	bool bShouldShowBackgroundImage;

};

UCLASS(MinimalAPI, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_PerkSystemMutator : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Perks")
	int32 MinPerksToUnlock;

	UPROPERTY(EditDefaultsOnly, Category="Perks")
	int32 MaxPerksToUnlock;

protected:
	UPROPERTY(EditAnywhere, Category="Mutator Data")
	FPerkMutatorData MutatorData;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_PerkSystemMutator")
	FScalableFloat MaxTimeAtPerkScreen;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_PerkSystemMutator")
	FScalableFloat MaxTimeToBlockRespawn;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_PerkSystemMutator")
	bool bDelayedPerkSelection;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_PerkSystemMutator")
	TArray<TObjectPtr<UFortSpyTechItemDefinition>> DefaultPerks;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_PerkSystemMutator")
	TArray<FForcedPerks> ForcedPerks;
#endif

	UPROPERTY()
	TMap<TWeakObjectPtr<AFortPlayerControllerAthena>, FTimerHandle> SafetyTimerMap;

};

