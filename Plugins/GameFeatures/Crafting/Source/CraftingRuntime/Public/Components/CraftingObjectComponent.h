// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortItemAndCount.h"
#include "Items/FortItemEntry.h"
#include "Types/CraftingTypes.h"
#include "CraftingObjectComponent.generated.h"

class AActor;
class AFortPawn;
class AFortPickup;
class AFortPlayerController;
class UFortGameplayAbility;
class UFortWorldItemDefinition;

USTRUCT(BlueprintType)
struct FCraftingObjectSuccessEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectSuccessEvent")
	AActor* CraftingObject;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectSuccessEvent")
	FCraftingMultiKey Key;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectSuccessEvent")
	AFortPlayerController* Instigator;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectSuccessEvent")
	FName FormulaRowName;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCraftingObjectOnCraftingSuccess, const FCraftingObjectSuccessEvent&, Payload);

USTRUCT(BlueprintType)
struct FCraftingObjectStateChangedEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	AActor* CraftingObject;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	FCraftingMultiKey Key;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	AFortPlayerController* Instigator;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	ECraftingObjectState CraftingState;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	float CraftingStateStartTime;

	UPROPERTY(BlueprintReadOnly, Category="CraftingObjectStateChangedEvent")
	float CraftingStateDuration;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCraftingObjectStateChanged, const FCraftingObjectStateChangedEvent&, Payload);

USTRUCT(BlueprintType)
struct FCraftingObjectRepStateData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	FCraftingMultiKey Key;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	ECraftingObjectState CraftingObjectState;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	float StateChangeServerTime;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	float PausedCraftingTime;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	FName CraftingFormulaRow;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	int32 NumToCraft;

	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	TWeakObjectPtr<AFortPlayerController> CraftingInstigator;

};

USTRUCT(BlueprintType)
struct FCraftingObjectServerStateData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Crafting")
	uint8 bNextResultsHandledExternally : 1;

	UPROPERTY()
	TObjectPtr<AFortPickup> PendingPickupCraftingItem;

	UPROPERTY()
	FName PendingPickupCraftingFormula;

	UPROPERTY()
	FFortItemEntry PendingPickupCraftingItemEntry;

	UPROPERTY()
	int32 PendingPickupHeldCount;

	UPROPERTY()
	TArray<FFortItemEntry> AllOfTheIngredientItems;

	UPROPERTY()
	TArray<int32> NonConsumedIngredientItemIndices;

	UPROPERTY()
	TArray<FItemAndCount> CraftingResults;

	UPROPERTY(Transient)
	FGameplayAbilitySpecHandle InstigatorWhileCraftingAbilitySpecHandle;

};

UCLASS(MinimalAPI, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UCraftingObjectComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCraftingObjectOnFormulaCraftableChanged, const FName&, FormulaRowName, bool, bIsCraftable);

public:
	UCraftingObjectComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(BlueprintAssignable, Category="Crafting | Callbacks")
	FCraftingObjectStateChanged CraftingObjectStateChanged;

	UPROPERTY(BlueprintAssignable, Category="Crafting | Callbacks")
	FCraftingObjectOnFormulaCraftableChanged OnFormulaCraftableChanged;

	UPROPERTY(BlueprintAssignable, Category="Crafting | Callbacks")
	FCraftingObjectOnCraftingSuccess OnCraftingSuccess;

protected:
	UPROPERTY(Transient)
	FString LastIngredientStringForAnalytics;

	UPROPERTY(Transient)
	FString LastFormulaStringForAnalytics;

	UPROPERTY(Transient)
	FString LastResultsStringForAnalytics;

	UPROPERTY(Transient)
	FGameplayAbilitySpecHandle WhileCraftingAbilitySpecHandle;

	UPROPERTY(Transient)
	FGameplayAbilitySpecHandle OwnerCraftingAbilitySpecHandle;

	UPROPERTY()
	FGameplayTag CraftingObjectTag;

	UPROPERTY(EditDefaultsOnly, Category="Crafting", meta=(Categories="Crafting.Object"))
	FGameplayTagContainer CraftingObjectTags;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | State Lengths")
	FScalableFloat CraftingTimeLength;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | State Lengths")
	FScalableFloat ReadyTimeLength;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | State Lengths")
	FScalableFloat OverCraftingTimeLength;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | State Lengths")
	FScalableFloat ResettingTimeLength;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior")
	FName OverCraftingLootTierKey;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior")
	uint8 bTakeItemsAtCraftingStart : 1;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior")
	float DecayRate;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior | Ingredients")
	uint8 bGiveIngredientsToCraftingObject : 1;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior | Ingredients")
	uint8 bGiveIngredientsToInstigator : 1;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior | Ingredients")
	FVector IngredientSpawnOffset;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior | Results")
	uint8 bGiveToCraftingObject : 1;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior | Results")
	uint8 bGiveResultToInstigator : 1;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Abilities")
	TSoftClassPtr<UFortGameplayAbility> OwnerCraftingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortGameplayAbility> WhileCraftingAbility;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Data")
	TSoftClassPtr<UFortGameplayAbility> InstigatorWhileCraftingAbility;

	UPROPERTY(EditDefaultsOnly, Category="Crafting | Behavior")
	bool bScaleMultiCraftingTime;

	UPROPERTY(EditDefaultsOnly, Category="CraftingObjectComponent")
	FGameplayTagContainer CraftingFailedTags;

private:
	UFUNCTION()
	void HandlePickupCraftingItemPickedUp(AFortPickup* Pickup, AFortPawn* InteractingPawn, const UFortWorldItemDefinition* WorldItemDefinition, FVector PickupLocation);

	UFUNCTION()
	void OnRep_CraftingObjectRepStateData(const TArray<FCraftingObjectRepStateData>& OldValue);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_CraftingObjectRepStateData)
	TArray<FCraftingObjectRepStateData> CraftingObjectRepStateData;

	UPROPERTY(Transient)
	TMap<FCraftingMultiKey, FCraftingObjectServerStateData> CraftingObjectServerStateData;

	UPROPERTY(Transient, Replicated)
	FName LastCraftedItemFormulaRow;

	UPROPERTY(Transient, Replicated)
	bool FreeCraftingEnabled;

};

