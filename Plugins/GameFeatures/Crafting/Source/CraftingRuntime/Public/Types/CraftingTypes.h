// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayEffectTypes.h"
#include "GameplayTagContainer.h"
#include "FortItemAndCount.h"
#include "CraftingTypes.generated.h"

class AActor;
class UFortGameplayAbility;
class UFortItemDefinition;
class UObject;

UENUM(BlueprintType)
enum class ECraftingIngredientReqError : uint8
{
	None = 0,
	// No error was found

	NoItem = 1,
	// Could not find an item that matches the requirement

	NotEnough = 2,
};

UENUM(BlueprintType)
enum class ECraftingObjectState : uint8
{
	Invalid = 0,
	// Initial state that is marked to idle on begin play

	Idle = 1,
	// Crafting object is sitting waiting to start crafting

	Crafting = 2,
	// Crafting object is currently crafting something

	CraftingPaused = 3,
	// Crafting object is currently crafting, but the timer is paused

	CraftingPausedDecaying = 4,
	// Crafting object is currently crafting, but the timer is paused, and is slowly rewinding

	Ready = 5,
	// Crafting object has finished crafting, item ready for pickup

	OverCrafting = 6,
	// Crafting object has over crafted the ready object because it wasn't picked up (optional state)

	Resetting = 7,
	// Crafting object is currently resetting back to idle (cannot craft during this time)

	TotalStates = 8,
};

USTRUCT(BlueprintType)
struct FCraftingIngredientRequirement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTagContainer IngredientTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 Count;

};

USTRUCT(BlueprintType)
struct FCraftingUpgradeRule
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CraftingUpgradeRule")
	FGameplayTagRequirements SourceItemTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CraftingUpgradeRule")
	FGameplayTagRequirements TargetItemTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(Bitmask, BitmaskEnum="/Script/FortniteGame.ECraftingUpgradeDataFlags"))
	uint8 UpgradeFlags;

};

USTRUCT(BlueprintType)
struct FCraftingFormula : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	uint8 bEnabled : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	uint8 bAlwaysKnownFormula : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	uint8 bInstantlyConsumeIngredients : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 SortingPriority;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data", meta=(Categories="Crafting.Object"))
	FGameplayTag SourceObjectTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FGameplayTagContainer AttributeTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FCraftingIngredientRequirement> RequiredIngredients;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FName ResultLootTierKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortGameplayAbility> WhileCraftingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TArray<FCraftingUpgradeRule> UpgradeRules;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	float OverrideCraftingTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortGameplayAbility> InstigatorWhileCraftingAbility;

};

USTRUCT(BlueprintType)
struct FCraftingIngredientQueryState
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	FCraftingIngredientRequirement Requirement;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 Owned;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	int32 Missing;

};

USTRUCT(BlueprintType)
struct FCraftingIngredientUIData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	FGameplayTagContainer IngredientTags;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data")
	TArray<TSoftObjectPtr<UFortItemDefinition>> ItemDefs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Data", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TArray<TSoftObjectPtr<UObject>> Icons;

};

USTRUCT(BlueprintType)
struct FCraftingMessage
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CraftingMessage")
	TObjectPtr<AActor> CraftingObject;

};

USTRUCT(BlueprintType)
struct FCraftingMultiKey
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CraftingMultiKey")
	int64 Key;


	CRAFTINGRUNTIME_API bool operator==(const FCraftingMultiKey& Other) const;
	friend CRAFTINGRUNTIME_API uint32 GetTypeHash(const FCraftingMultiKey& Value);
};

USTRUCT(BlueprintType)
struct FCraftingResult
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ResultLootTierKey;

	UPROPERTY()
	TArray<FItemAndCount> Results;

};

