// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BlueprintContextBase.h"
#include "Building/BuildingTypes.h"
#include "FortInventoryFilterEnum.h"
#include "FortInventoryType.h"
#include "FortItemQuantityPair.h"
#include "FortItemTier.h"
#include "FortTypes.h"
#include "FortInventoryContext.generated.h"

class ABuildingSMActor;
class AFortWeapon;
class UFortAccountItem;
class UFortItem;
class UFortItemDefinition;
class UFortResourceItemDefinition;
class UFortSchematicItem;
class UFortSchematicItemDefinition;
class UFortWorldItem;
class UFortWorldItemDefinition;
enum class EConversionControlKeyRequest : uint8;
enum class EFortCraftFailCause : uint8;
enum class EFortFrontendInventoryFilter : uint8;
enum class EFortInventoryFilter : uint8;
enum class EFortItemTier : uint8;
enum class EFortItemType : uint8;
enum class EFortQuickBars : uint8;
enum class EInventoryContentSortType : uint8;
enum class EItemEvolutionRestrictionReason : uint8;
enum class EItemRecyclingRestrictionReason : uint8;
enum class EItemRecyclingWarning : uint8;
enum class EVaultItemLimitStatus : uint8;

UENUM(BlueprintType)
enum class EConversionControlKeyRequest : uint8
{
	AllKeys = 0,
	NonConsumableKeys = 1,
	ConsumableKeys = 2,
};

UENUM(BlueprintType)
enum class EItemRecyclingRestrictionReason : uint8
{
	InnatelyUnrecyclable = 0,
	IsSlottedGroundOperative = 1,
	MissingCatalyst = 2,
	ItemOutOnExpedition = 3,
	InUseByCrafting = 4,
	MulchingNotAllowed = 5,
	IsSlottedAttributeWorker = 6,
};

UENUM(BlueprintType)
enum class EItemRecyclingWarning : uint8
{
	HighLevel = 0,
	HighRarity = 1,
	CanSlotInCollectionBook = 2,
};

UENUM(BlueprintType)
enum class EVaultItemLimitStatus : uint8
{
	WellBelowCapacity = 0,
	NearCapacity = 1,
	AtCapacity = 2,
	OverCapacity = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemDefinitionChangedDelegate, UFortItem*, Item, UFortItemDefinition*, ItemDefinition);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_TwoParams(FItemDefinitionChangedListener, UFortItem*, Item, UFortItemDefinition*, ItemDefinition);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemListChangedDelegate, const TArray<UFortWorldItem*>&, ItemsAdded, const TArray<UFortWorldItem*>&, ItemsRemoved);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCraftItemFailed, EFortCraftFailCause, FailureCause);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCraftItemStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnItemPickedUp, UFortWorldItem*, NewItem, int32, Count);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnQuickbarContentsChanged, EFortQuickBars, QuickbarIndex, const TArray<int32>&, ChangedSlots);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnQuickbarFullUpdate, EFortQuickBars, QuickbarIndex);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuickbarRecordsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSchematicUnlocked, UFortSchematicItem*, Schematic);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnVaultItemLimitStateChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuickbarFocusChangedDelegate, EFortQuickBars, QuickbarIndex, int32, Slot);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSetWorldResourceWidgetVisibility, const TEnumAsByte<EFortResourceType::Type>, ResourceType, const bool, bVisible);

USTRUCT(BlueprintType)
struct FFortItemListFilter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter")
	FString SearchText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter")
	EFortInventoryFilter FilterType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter")
	bool bInStorageVault;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Filter")
	bool bIncludeVaultOverflow;

};

UCLASS()
class FORTNITEUI_API UFortInventoryContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	static bool AreAnyItemsAnimate(const TArray<UFortItem*>& Items);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	static bool AreAnyItemsInanimate(const TArray<UFortItem*>& Items);

	UFUNCTION(BlueprintPure, Category="Inventory")
	bool AreAnyItemsUnseenForInventoryFilter(const EFortFrontendInventoryFilter InventoryFilter) const;

	UFUNCTION(BlueprintPure, Category="Crafting")
	bool CanCraftSchematic(UFortSchematicItem* SchematicItem, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier = EFortItemTier::No_Tier, int32 CraftCount = 1) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool CanEvolve(const UFortItem* Item, TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const;

	UFUNCTION(BlueprintPure, Category="InventoryContext|Mulch")
	bool CanItemBeMulched(const UFortItem* Item, FText& OutRestrictionReasons) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool CanItemBePromoted(const UFortItem* Item, TArray<FFortItemQuantityPair>& Costs) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool CanRecycle(const UFortItem* Item, TArray<EItemRecyclingRestrictionReason>& OutRestrictionReasons) const;

	UFUNCTION(BlueprintCallable, Category="QuickBar")
	bool CanSwapItem(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool CanUpgradeItemRarity(const UFortItem* Item, TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	bool CraftAndSlotSchematic(UFortSchematicItem* SchematicItem, int32 PostCraftSlot, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier = EFortItemTier::No_Tier, int32 CraftCount = 1);

	UFUNCTION(BlueprintCallable, Category="Crafting")
	bool CraftSchematic(UFortSchematicItem* SchematicItem, EFortCraftFailCause& FailCause, EFortItemTier RequestedTier = EFortItemTier::No_Tier, int32 CraftCount = 1);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void DestroyWorldItem(UFortItem* Item);

	UFUNCTION(BlueprintCallable, Category="QuickBar")
	bool DropCreativeItemOnQuickBar(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	bool DropItem(const UFortWorldItem* ItemBeingDropped, const int32 Quantity);

	UFUNCTION(BlueprintCallable, Category="QuickBar")
	bool DropItemOnQuickBar(UFortItem* Item, EFortQuickBars TargetQuickbar, int32 TargetSlot);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	void EnumerateRecyclingWarningsForItems(const TArray<UFortItem*>& Items, TArray<EItemRecyclingWarning>& OutWarnings);

	UFUNCTION(BlueprintCallable, Category="QuickBar")
	void EquipItem(UFortItem* Item);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void ForceItemsChanged(const TArray<EFortInventoryFilter>& InventoryFilters);

	UFUNCTION(BlueprintPure, Category="Inventory")
	void GetAccountItemsByFilterType(const FString SearchText, const EInventoryContentSortType SortType, const EFortInventoryFilter SubType, TArray<UFortAccountItem*>& OutItemList) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	void GetAccountItemsByType(EFortItemType ItemType, TArray<UFortAccountItem*>& Items) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	void GetBackpackItemCounts(int32& ItemsCount, int32& MaxItemsCount, int32& OverflowItemsCount) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetBackpackOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const;

	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	TArray<FRecipe> GetConversionRecipesFromItemDefintion(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category="Vault")
	int32 GetCountOfVaultLimitedItems() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	UFortWorldItemDefinition* GetCurrentAmmoItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetCurrentResourceCount() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	UFortResourceItemDefinition* GetCurrentResourceItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	void GetDeployableBaseItemCounts(int32& ItemsCount, int32& MaxItemsCount, int32& OverflowItemsCount) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetDeployableBaseOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	AFortWeapon* GetEquippedWeapon() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	void GetItemInstancesByDefinition(UFortItemDefinition* ItemDefinition, TArray<UFortItem*>& Items) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	static FText GetItemStackCount_Creative(const int32 Quantity);

	UFUNCTION(BlueprintPure, Category="InventoryContext|Mulch", meta=(DisplayName="Get Items To Mulch"))
	TArray<UFortItem*> GetItemsToMulchBP() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	int32 GetLevelsPerItemPromotion() const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetNumInInventory(UFortItemDefinition* ItemDefinition, bool bIncludeReserved = false) const;

	UFUNCTION(BlueprintPure, Category="InventoryContext|Mulch")
	int32 GetNumItemsToMulch() const;

	UFUNCTION(BlueprintPure, Category="InventoryContext|Mulch")
	int32 GetNumOfItemToMulch(const UFortItem* Item) const;

	UFUNCTION(BlueprintPure, Category="QuickBar")
	void GetQuickbarFocus(EFortQuickBars& OutQuickBar, int32& OutSlot, int32& OutSecondarySlot, int32& OutPreviousFocusedSlot) const;

	UFUNCTION(BlueprintPure, Category="QuickBar")
	UFortItem* GetQuickBarSlottedItem(EFortQuickBars InQuickBar, int32 Slot) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	static FText GetRecyclingWarningText(EItemRecyclingWarning Warning, const bool WereAnyItemsAnimate);

	UFUNCTION(BlueprintPure, Category="Inventory")
	int32 GetResourceCount(EFortResourceType::Type ResourceType) const;

	UFUNCTION(BlueprintPure, Category="Inventory")
	UFortResourceItemDefinition* GetResourceItemDefinition(EFortResourceType::Type ResourceType) const;

	UFUNCTION(BlueprintPure, Category="Storage")
	int32 GetStorageCapacity() const;

	UFUNCTION(BlueprintPure, Category="Storage")
	int32 GetStorageNumItems() const;

	UFUNCTION(BlueprintPure, Category="Storage")
	int32 GetStorageOverflowFromAddingItem(UFortWorldItem* Item, int32 Count) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	static FText GetTierText(EFortItemTier Tier);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	int32 GetTotalItemQuantityByDefinition(UFortItemDefinition* ItemDefinition) const;

	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	void GetTransformKeys(EConversionControlKeyRequest RequestType, const EInventoryContentSortType SortType, TArray<UFortAccountItem*>& TransformKeys);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool GetTransmogSacrificeDataFromItemDefintion(const UFortItemDefinition* ItemDefinition, FTransmogSacrifice& OutTransmogData) const;

	UFUNCTION(BlueprintPure, Category="QuickBar")
	FText GetTrapAttachTypeName(ABuildingSMActor* Actor) const;

	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	void GetUnseenTransformKeys(EConversionControlKeyRequest RequestType, const EInventoryContentSortType SortType, TArray<UFortAccountItem*>& TransformKeys);

	UFUNCTION(BlueprintCallable, Category="HomebaseInventory")
	FRecipe GetUpgradeItemRarityRecipeFromItemDefintion(UFortItemDefinition* ItemDefinition);

	UFUNCTION(BlueprintPure, Category="Items")
	static TArray<FText> GetUserFriendlyTags(const UFortItem* Item, bool bAddWeaponTier = true);

	UFUNCTION(BlueprintPure, Category="Vault")
	int32 GetVaultItemLimit() const;

	UFUNCTION(BlueprintPure, Category="Vault")
	EVaultItemLimitStatus GetVaultItemLimitStatus() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool HasGameplayTagContainer(FGameplayTagContainer GameplayTagContainer) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool HasGameplayTagContainerExact(FGameplayTagContainer GameplayTagContainer) const;

	UFUNCTION(BlueprintPure, Category="QuickBar")
	bool HasTrapReadyForBuilding(const ABuildingSMActor* BuildingToAttachTo) const;

	UFUNCTION(BlueprintPure, Category="Storage")
	bool HasUnavailableItemsInStorage() const;

	UFUNCTION(BlueprintPure, Category="HomebasePoints")
	bool HasUnseenHomebasePoints() const;

	UFUNCTION(BlueprintPure, Category="Research")
	bool HasUnseenResearchPointCollectionNodes() const;

	UFUNCTION(BlueprintPure, Category="QuickBar")
	bool IsTrapAvailableForBuilding(ABuildingSMActor* Actor) const;

	UFUNCTION(BlueprintCallable, Category="Inventory")
	static FFortItemInstanceQuantityPair MakeItemInstanceQuantityPair(const UFortItem* Item, const EFortInventoryType::Type InventoryType, int32 ItemQuantity);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	static FFortItemQuantityPair MakeItemQuantityPair(const UFortItemDefinition* ItemDefinition, int32 ItemQuantity);

	UFUNCTION(BlueprintCallable, Category="QuickBar")
	bool RemoveItemFromQuickBar(UFortItem* Item);

	UFUNCTION(BlueprintCallable, Category="HomebasePoints")
	void UpdateLastSeenHomebasePoints();

	UFUNCTION(BlueprintCallable, Category="Research")
	void UpdateLastSeenResearchPointCollectionNodes();

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool WillAllItemsSlotInCollectionBook(const TArray<UFortItem*>& Items);

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	bool WouldExceedMaxStackSize(UFortItemDefinition* ItemDefinition, int32 QuantityToTest = 1) const;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FItemsChanged OnMcpWorldItemsChanged;

	UPROPERTY(BlueprintAssignable, Category="Storage")
	FItemsChanged OnMcpOutpostItemsChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FItemListChangedDelegate OnWorldItemListChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FItemListChangedDelegate OnOutpostItemListChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnItemPickedUp OnItemPickedUp;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnQuickbarContentsChanged OnQuickbarContentsChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnQuickbarRecordsChanged OnQuickbarRecordsChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FQuickbarFocusChangedDelegate OnQuickbarSlotFocusChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FQuickbarFocusChangedDelegate OnQuickbarSecondarySlotFocusChanged;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FOnQuickbarFullUpdate OnQuickbarForceFullUpdate;

	UPROPERTY(BlueprintAssignable, Category="Inventory")
	FItemsChanged OnWorldItemsChanged;

	UPROPERTY(BlueprintAssignable, Category="Crafting")
	FOnCraftItemFailed OnCraftItemFailed;

	UPROPERTY(BlueprintAssignable, Category="Vault")
	FOnVaultItemLimitStateChanged OnVaultItemLimitStateChangedEvent;

private:
	UFUNCTION()
	void HandleMcpProfilesInitialized();

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFortSchematicItemDefinition>, bool> SchematicLockedStates;

};

