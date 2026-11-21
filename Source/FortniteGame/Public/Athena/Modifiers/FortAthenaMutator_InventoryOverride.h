// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortItemAndCount.h"
#include "Items/FortItemTypeEnum.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_InventoryOverride.generated.h"

class AController;
class UFortItemDefinition;

UENUM(BlueprintType)
enum class EAthenaInventorySpawnOverride : uint8
{
	// Use the default settings for how things drop

	NoOverride = 0,
	// Reset inventory on every spawn

	Always = 1,
	// Only set inventory on initial spawn

	IntialSpawn = 2,
	// Only set inventory during the Aircraft phase

	AircraftPhaseOnly = 3,
	// Only set inventory after the warmup phase (aircraft phase and on)

	AfterWarmup = 4,
};

UENUM(BlueprintType)
enum class EAthenaLootDropOverride : uint8
{
	// Use the default settings for how things drop

	NoOverride = 0 UMETA(DisplayName="Default"),
	// Force the loot to drop when the player dies

	ForceDrop = 1 UMETA(DisplayName="Drop"),
	// Do not drop the loot when the player dies

	ForceKeep = 2 UMETA(DisplayName="Keep"),
	// Force Destroy of Item

	ForceDestroy = 3 UMETA(DisplayName="Delete"),
	// Keep unless the player isn't respawning. Drop if they can't respawn.

	ForceDropUnlessRespawning = 4 UMETA(DisplayName="Drop Unless Respawning"),
	// Keep unless the player isn't respawning. Destroy if they can't respawn.

	ForceDestroyUnlessRespawning = 5 UMETA(DisplayName="Delete Unless Respawning"),
	// Drop unless being respawned by a team selection device

	DropUnlessTeamSelectionUpdated = 6,
};

USTRUCT(BlueprintType)
struct FHotfixableInventoryOverrideItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	FScalableFloat Count;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Item")
	TObjectPtr<UFortItemDefinition> Item;

};

USTRUCT()
struct FInventoryOverrideLoadoutRandomization
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FItemLoadoutContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	FScalableFloat bEnabled;

	UPROPERTY(meta=(DeprecatedProperty))
	TArray<FItemAndCount> Loadout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	TArray<FHotfixableInventoryOverrideItem> LoadoutList;

};

USTRUCT(BlueprintType)
struct FItemLoadoutTeamMap
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ItemLoadoutTeamMap")
	uint8 TeamIndex;

	UPROPERTY(EditDefaultsOnly, Category="ItemLoadoutTeamMap")
	uint8 LoadoutIndex;

	UPROPERTY(EditDefaultsOnly, Category="ItemLoadoutTeamMap")
	EAthenaInventorySpawnOverride UpdateOverrideType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemLoadoutTeamMap")
	EAthenaLootDropOverride DropAllItemsOverride;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_InventoryOverride : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Activation")
	bool bWantsAutoTDMActivation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Activation")
	FScalableFloat bForceRemoveInventoryOnGetInventoryOverride;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	FScalableFloat bRunForAthenaGameParticipantsOnly;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	FScalableFloat bSelectRandomLoadoutOnce;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	FScalableFloat bSelectRandomLoadoutForAll;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	FScalableFloat bSelectRandomLoadoutPerPlayer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Inventory")
	FScalableFloat bNoRepeat;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride DropAllItemsOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride TrapDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride WeaponDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride MaterialDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride GadgetDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride ConsumableDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="ItemDrop")
	EAthenaLootDropOverride AmmoDropOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="InventoryUpdate")
	EAthenaInventorySpawnOverride InventoryUpdateOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	TArray<FItemLoadoutContainer> InventoryLoadouts;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortAthenaMutator_InventoryOverride")
	FItemLoadoutContainer AlwaysGiveLoadout;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	FScalableFloat bPreventPickaxe;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	FScalableFloat bPreventAllDefaultItems;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	TArray<TObjectPtr<UFortItemDefinition>> PreventDefaultItems;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	int32 InventoryLoadoutIndex;

	UPROPERTY(EditDefaultsOnly, Category="Inventory")
	TArray<FItemLoadoutTeamMap> TeamLoadouts;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_InventoryOverride")
	TArray<EFortItemType> ItemTypesToRemoveOnReset;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaMutator_InventoryOverride")
	FScalableFloat bKeepUnchangedItemsOnReset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory")
	int32 InventoryAutoEquipSlot;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Inventory", meta=(EditCondition="InventoryAutoEquipSlot >= 0"))
	bool bForceInventoryAutoEquip;

private:
	UPROPERTY()
	TMap<TObjectPtr<AController>, FInventoryOverrideLoadoutRandomization> LoadoutRandomizationPerPlayer;

	UPROPERTY()
	TMap<TObjectPtr<AController>, int32> LoadoutIndexMap;

};

UCLASS()
class UFortCheatManager_InventoryOverride : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void InventoryOverrideLogPlayerInventoryInfo();

};

