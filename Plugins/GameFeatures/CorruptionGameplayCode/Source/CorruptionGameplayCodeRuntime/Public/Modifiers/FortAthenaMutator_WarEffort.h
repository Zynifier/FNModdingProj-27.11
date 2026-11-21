// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "UObject/PrimaryAssetId.h"
#include "Athena/Modifiers/FortAthenaMutator_GameModeBase.h"
#include "MeshNetworkSubsystem.h"
#include "FortAthenaMutator_WarEffort.generated.h"

class UFortItemDefinition;

USTRUCT(BlueprintType)
struct FWarEffortMutatorChoiceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="WarEffortMutatorChoiceData")
	FGameplayTag FundingTag;

	UPROPERTY(EditAnywhere, Category="WarEffortMutatorChoiceData")
	TArray<TSoftObjectPtr<UFortItemDefinition>> SoftRefsToLoad;

	UPROPERTY(EditAnywhere, Category="WarEffortMutatorChoiceData", meta=(DisplayName="Loot Table Entries"))
	TMap<FName, FScalableFloat> LootTableMods;

};

USTRUCT(BlueprintType)
struct FWarEffortMutatorMetadata : public FMeshMetaDataStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="WarEffortMutatorMetadata")
	TArray<FGameplayTag> ActiveFundedItems;

	UPROPERTY(BlueprintReadWrite, Category="WarEffortMutatorMetadata")
	TArray<FGameplayTag> ActiveTryBeforeYouBuyItems;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "FortAthenaMutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_WarEffort : public AFortAthenaMutator_GameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetFundingManagerReady(bool bIsReady);

	UFUNCTION(BlueprintCallable)
	void SetItemFundedAmount(FGameplayTag ItemFundingTag, int64 CurrentFundingAmount, int64 TargetFundingAmount);

	UFUNCTION(BlueprintCallable)
	void SetItemFundedPercent(FGameplayTag ItemFundingTag, float FundingPercent);

	UFUNCTION(BlueprintCallable)
	void SetItemFundedState(FGameplayTag ItemFundingTag, bool bIsActive);

	UFUNCTION(BlueprintCallable)
	void SetTryBeforeYouBuyItemState(FGameplayTag ItemFundingTag, bool bIsActive);

protected:
	UFUNCTION()
	void OnRep_PreloadedItemList();

	UPROPERTY(BlueprintReadWrite, Category="War Effort")
	FWarEffortMutatorMetadata MeshNetworkMetadata;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="War Effort")
	TArray<FWarEffortMutatorChoiceData> WeaponChoices;

	UPROPERTY(ReplicatedUsing=OnRep_PreloadedItemList)
	TArray<FPrimaryAssetId> PreloadedItemList;

	UPROPERTY(Replicated)
	bool bCanPreloadItems;

};

