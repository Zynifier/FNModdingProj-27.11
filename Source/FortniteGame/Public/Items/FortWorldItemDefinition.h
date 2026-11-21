// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "FortSpecialActorStatData.h"
#include "Items/FortItemDefinition.h"
#include "FortWorldItemDefinition.generated.h"

class AFortPickupEffect;
class UFortWorldItemDefinition;
class USkeletalMesh;
class USoundBase;
class USoundLibrary;
class UStaticMesh;

UENUM()
enum class EWorldItemDropBehavior : uint8
{
	/** Try to drop the item as a world pickup */
	DropAsPickup = 0,
	/** Destroy the item quantities when dropped */
	DestroyOnDrop = 1,
	/** Try to drop as a pickup, but destroy instead if the item being dropped is empty (persisted through zero count) */
	DropAsPickupDestroyOnEmpty = 2,
	/** Drops the item entry as a pickup even when the stack is empty */
	DropAsPickupEvenWhenEmpty = 3,
};

USTRUCT()
struct FFortPickupTagTestContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPickupTagTestContainer")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, Category="FortPickupTagTestContainer")
	FText FailReason;

};

USTRUCT(BlueprintType)
struct FFortPickupRestrictionLists
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortPickupRestrictionLists")
	FFortPickupTagTestContainer Whitelist;

	UPROPERTY(EditDefaultsOnly, Category="FortPickupRestrictionLists")
	FFortPickupTagTestContainer Blacklist;

};

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortWorldItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	bool CanBeDisassembled() const;

	UFUNCTION(BlueprintPure, Category="WeaponItemDefinition", meta=(DisplayName="GetAmmoWorldItemDefinition"))
	UFortWorldItemDefinition* GetAmmoWorldItemDefinition_BP() const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual float GetDamageAtLevel(int32 ItemLevel) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual float GetDPSAtLevel(int32 ItemLevel) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual int32 GetInitialAmmo(const int32 ItemLevel) const;

	UFUNCTION(BlueprintPure, Category="Item")
	virtual float GetMaxDurability(int32 ItemLevel) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Functionality")
	FGameplayTagContainer RequiredEquipTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bShouldShowItemToast : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals")
	uint8 bShowDirectionalArrowWhenFarOff : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bCanBeDropped : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bCanBeReplacedByPickup : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bItemCanBeStolen : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bCanBeDepositedInStorageVault : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bItemHasDurability : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="DropCount"))
	uint8 bAllowedToBeLockedInInventory : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals", meta=(DisplayAfter="PickupMeshTransform"))
	uint8 bOverridePickupMeshTransform : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	uint8 bAlwaysCountForCollectionQuest : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="InStormPickupDespawnTime"))
	uint8 bDropOnDeath : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="bDropOnDeath"))
	uint8 bDropOnLogout : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(DisplayAfter="bDropOnDeath"))
	uint8 bDropOnDBNO : 1;

	UPROPERTY(EditAnywhere, Category="Functionality")
	uint8 bDoesNotNeedSourceSchematic : 1;

	UPROPERTY(VisibleAnywhere, Category="FortWorldItemDefinition")
	uint8 bUsesGoverningTags : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(Patchable))
	uint8 bIsPickupASpecialActor : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	uint8 bDrawCompassDistanceText : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(Patchable))
	uint8 bDrawMapIconUnderStorm : 1;

	UPROPERTY(EditAnywhere, Category="Inventory")
	uint8 NumberOfSlotsToTake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	int32 DropCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals")
	float MiniMapViewableDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals")
	FSlateBrush MiniMapIconBrush;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="PickupVisuals")
	FText OwnerPickupText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LootLevel")
	FDataTableCategoryHandle LootLevelData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorPickupTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FName PickupSpecialActorUniqueID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals")
	FTransform PickupMeshTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	TArray<FSpecialActorSingleStatData> SpecialActorPickupStatList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush PickupMinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D PickupMinimapIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush PickupCompassIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D PickupCompassIconScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor", meta=(Patchable))
	float PickupCompassRenderDistance;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	FScalableFloat PickupDespawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	FScalableFloat InStormPickupDespawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	FScalableFloat NetworkCullDistanceOverride;

	UPROPERTY(EditDefaultsOnly, Category="SoundLibrary")
	TArray<TObjectPtr<USoundLibrary>> PickupSoundLibraries;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Functionality")
	TArray<FFortPickupRestrictionLists> PickupRestrictionListEntry;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(EditCondition="bCanBeDropped"))
	EWorldItemDropBehavior DropBehavior;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality", meta=(EditCondition="bCanBeDropped"))
	uint8 bIgnoreRespawningForDroppingAsPickup : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AutoEquip")
	uint8 bCanAutoEquipByClass : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Functionality")
	uint8 bPersistInInventoryWhenFinalStackEmpty : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bSupportsQuickbarFocus : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bSupportsQuickbarFocusForGamepadOnly : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bShouldActivateWhenFocused : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bForceFocusWhenAdded : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bForceIntoOverflow : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bForceStayInOverflow : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	uint8 bDropCurrentItemOnOverflow : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<UStaticMesh> PickupStaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USkeletalMesh> PickupSkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PickupVisuals", meta=(AssetBundles="DroppedItem"))
	TSoftClassPtr<AFortPickupEffect> PickupEffectOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USoundBase> PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USoundBase> PickupByNearbyPawnSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USoundBase> DropSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USoundBase> DroppedLoopSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Sounds", meta=(AssetBundles="DroppedItem"))
	TSoftObjectPtr<USoundBase> LandedSound;

	UPROPERTY(EditAnywhere, Category="Disassembly")
	FDataTableRowHandle DisassembleRecipe;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Disassembly")
	float DisassembleDurabilityDegradeMinLootPercent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Disassembly")
	float DisassembleDurabilityDegradeMaxLootPercent;

	UPROPERTY(EditDefaultsOnly, Category="FortWorldItemDefinition")
	int32 PreferredQuickbarSlot;

	UPROPERTY(EditDefaultsOnly, Category="FortWorldItemDefinition")
	uint8 bSkipRemovingFromInventory : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MinLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MaxLevel;

};

