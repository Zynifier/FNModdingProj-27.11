// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Math/Color.h"
#include "Misc/Guid.h"
#include "Styling/SlateBrush.h"
#include "UObject/NoExportTypes.h"
#include "FortBrushSize.h"
#include "FortItemVariantHandle.h"
#include "FortMultiSize.h"
#include "FortTypes.h"
#include "McpItemAware.h"
#include "FortItem.generated.h"

class AFortPlayerController;
class UAbilitySystemComponent;
class UFortAlterationItemDefinition;
class UFortItemDefinition;
class UFortPersistentResourceItemDefinition;
class UFortWeaponItemDefinition;
class UObject;
class UTexture2D;
enum class EFortInventoryFilter : uint8;
enum class EFortItemCategoryOrdinal : uint8;
enum class EFortItemTier : uint8;
enum class EFortItemType : uint8;
enum class EFortRarity : uint8;
enum class EItemEvolutionRestrictionReason : uint8;
enum class EItemUpgradeRestrictionReason : uint8;

UENUM(BlueprintType)
enum class EItemEvolutionRestrictionReason : uint8
{
	NoEvolutions = 0,
	BelowMaximumLevel = 1,
	VaultOverflow = 2,
	MissingCatalyst = 3,
	MissingCosts = 4,
	NoRarityUpgrade = 5,
	InUseByCrafting = 6,
};

UENUM(BlueprintType)
enum class EItemUpgradeRestrictionReason : uint8
{
	NoAdditionalLevels = 0,
	MaximumLevelAchieved = 1,
	VaultOverflow = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFortOnItemChangedDelegate, bool, bItemChanged, bool, bAmmoChanged, bool, bIngredientsChanged);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFortOnItemDestroyedDelegate);

UCLASS(Abstract, MinimalAPI, BlueprintType)
class UFortItem : public UObject, public IMcpItemAware
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool AllowedToBeLockedInInventory() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="FortItem")
	FORTNITEGAME_API void BroadcastOnItemChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged, bool bLogBroadcasts = false) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual bool CanAffordPromotion() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool CanBeDropped() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool CanBeUnslotted() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool CanBeUpgraded(TArray<EItemUpgradeRestrictionReason>& OutRestrictionReasons) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual bool CanEvolve(TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual bool CanUpgradeItemRarity(TArray<EItemEvolutionRestrictionReason>& OutRestrictionReasons) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API bool DoesMatchSearchString(const FString& SearchString) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API TArray<UFortAlterationItemDefinition*> GetActiveAlterations(int32 PretendLevel = -1) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TArray<FFortAlterationSlotStatus> GetAlterationSlots() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual float GetCoolDownTimeRemaining(const AFortPlayerController* FortPC, float& CooldownDuration) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FText GetCraftedDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FText GetDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API FText GetDisplayNameWithoutPrefix() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual float GetDurability() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	static FORTNITEGAME_API FText GetEvolveRestrictionReasonText(const EItemEvolutionRestrictionReason Reason);

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual EFortInventoryFilter GetFilterCategory() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TSoftObjectPtr<UTexture2D> GetInactivePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item", meta=(DisplayName="GetItemDefinition"))
	FORTNITEGAME_API UFortItemDefinition* GetItemDefinitionBP() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FGuid GetItemGuid() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FText GetItemTypeName(bool bUsePlural = false) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FGuid GetItemVariantGuid() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FItemVariantHandle GetItemVariantHandle() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TSoftObjectPtr<UTexture2D> GetLargePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetLevel() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual int32 GetLevelRelativeCostForRarityUpgrade() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetLoadedAmmo() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetMaxLevel() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetMaxStackSize(UAbilitySystemComponent* AbilityComp = nullptr) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API EFortItemTier GetMaxTier() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual float GetNormalizedDurability() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual uint8 GetNumberOfSlotsTaken() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetNumInStack() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API int32 GetNumInStackWithInfinityCheck() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual AFortPlayerController* GetOwningController() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetPhantomReserveAmmo() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TArray<TSoftObjectPtr<UObject>> GetPreviewAssets() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool GetPrimaryCategory(FText& ItemCategoryText) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetPromotionTier() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual EFortRarity GetRarity() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FLinearColor GetRarityColor() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API FLinearColor GetRaritySecondaryColor() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetRating() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetRecycleValue() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetRemainingAmmo() const;

	UFUNCTION(BlueprintPure, Category="Item", meta=(DisplayName="GetSchematicCraftingResult"))
	FORTNITEGAME_API UFortItemDefinition* GetSchematicCraftingResultBP() const;

	UFUNCTION(BlueprintPure, Category="Item", meta=(DisplayName="GetSchematicCraftingResultOrCraftedWeapon"))
	FORTNITEGAME_API UFortWeaponItemDefinition* GetSchematicCraftingResultOrCraftedWeaponBP() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual EFortItemType GetSchematicResultType() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FText GetSearchTags() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool GetSecondaryCategory(FText& ItemCategoryText, FSlateBrush& ItemCategoryBrush, EFortBrushSize::Type BrushSize = EFortBrushSize::Medium) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TSoftObjectPtr<UTexture2D> GetSmallPreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool GetTertiaryCategory(FText& ItemCategoryText, FSlateBrush& ItemCategoryBrush, EFortBrushSize::Type BrushSize = EFortBrushSize::Medium) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API EFortItemTier GetTier() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetTotalAmmo() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual FGuid GetTrackerGuid() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual EFortItemType GetType() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetUpgradeCost() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual int32 GetUpgradeCostToLevel(int32 TargetLevel) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual UFortPersistentResourceItemDefinition* GetUpgradeResourceItemDefinition() const;

	UFUNCTION(BlueprintPure, Category="Item")
	static FORTNITEGAME_API FText GetUpgradeRestrictionReasonText(const EItemUpgradeRestrictionReason Reason);

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual TSoftObjectPtr<UTexture2D> GetWidePreviewImage() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool HasDurability() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual bool HasEvolutions() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool HasOverriddenWeaponAmmo() const;

	UFUNCTION(BlueprintPure, Category="HomebaseInventory")
	FORTNITEGAME_API virtual bool HasRarityUpgrade() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsActivatable(const AFortPlayerController* FortPC, FGameplayTagContainer& FailureReason) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsDroppedItem() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsEquipable(const AFortPlayerController* EquippingPC, bool bGamepadSwitchingForHeroAbilities = false) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsEquipped() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsInStorageVault() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsInventoryOverflowItem() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsSchematic() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API bool IsSchematicOrCraftedWeapon() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsSlotted() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsTemporaryItem() const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool IsVisible() const;

	UFUNCTION(BlueprintCallable, Category="Item")
	FORTNITEGAME_API void SetOwningControllerForTemporaryItem(AFortPlayerController* InController);

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool TryGetCategory(EFortItemCategoryOrdinal Ordinal, FText& OutCategoryDisplayName, bool& OutHasIcon, FFortMultiSizeBrush& OutCategoryIconBrush) const;

	UFUNCTION(BlueprintPure, Category="Item")
	FORTNITEGAME_API virtual bool UsesPhantomReserveAmmo() const;

	UPROPERTY(BlueprintAssignable, Category="FortItem")
	FFortOnItemChangedDelegate OnItemChanged;

	UPROPERTY(BlueprintAssignable, Category="FortItem")
	FFortOnItemDestroyedDelegate OnItemDestroyed;

protected:
	UPROPERTY(Transient)
	uint8 bLoadedFromSave : 1;

	UPROPERTY(Transient)
	uint8 bTemporaryItemOwningController : 1;

};

UCLASS(NotBlueprintable)
class UFortItemIconDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Display")
	TSoftObjectPtr<UTexture2D> SmallImage;

	UPROPERTY(EditAnywhere, Category="Display")
	TSoftObjectPtr<UTexture2D> LargeImage;

};

