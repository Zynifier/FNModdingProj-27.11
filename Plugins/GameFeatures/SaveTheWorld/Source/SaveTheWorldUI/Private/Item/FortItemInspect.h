// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Athena/FortActivatablePanelWithItemPreview.h"
#include "FortTypes.h"
#include "FortItemInspect.generated.h"

class UDataTable;
class UFortAccountItem;
class UFortAlterationModOptinScreenBase;
class UFortAlterationModScreenBase;
class UFortItem;
class UFortItemInspectCycleWidget;
class UFortItemTileView;
enum class EFortItemInspectionMode : uint8;

USTRUCT(BlueprintType)
struct FFortRefundDescriptionsData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRefundDescriptionsData")
	FString SearchString;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRefundDescriptionsData")
	FString TargetReleaseVersion;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortRefundDescriptionsData", meta=(MultiLine="TRUE"))
	FText RefundDescriptionText;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortItemInspectionScreen : public UFortActivatablePanelWithItemPreview
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Inspect")
	void DoAlterationModification();

	UFUNCTION(BlueprintPure, Category="Item Inspect")
	UFortItemInspectCycleWidget* GetCycleWidget();

	UFUNCTION(BlueprintPure, Category="Item Inspect")
	int32 GetItemQuantityOverride() const;

	UFUNCTION(BlueprintCallable, Category="Item Inspect")
	void OpenItemInspect(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, bool ShouldAllowUpgrading, bool ShouldAllowEvolution, bool ShouldAllowFavorite, bool IsTemporaryItem, bool bAllowRarityUpgrading, int32 QuantityOverride = -1, UFortItemTileView* TileViewWidget = nullptr);

	UFUNCTION(BlueprintCallable, Category="Item Inspect")
	void SetAttemptingConversion(bool bIsAttemptingConversion);

protected:
	UFUNCTION(BlueprintPure, Category="Item Inspect")
	bool DoesItemHaveLegacyAlterations() const;

	UFUNCTION(BlueprintPure, Category="Item Inspect")
	FText GetRefundDescriptionText() const;

	UFUNCTION(BlueprintPure, Category="Item Inspect")
	UFortAccountItem* GetRefundResultItem() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Item Inspect")
	void HandleDifferentInspectionModeSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Inspect")
	void HandleDifferentItemToInspectSetBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Inspect")
	void HandleIsPreviewingChanged();

	UFUNCTION()
	void HandleItemToInspectChanged(bool bItemChanged, bool bAmmoChanged, bool bIngredientsChanged);

	UFUNCTION(BlueprintImplementableEvent, Category="Item Inspect")
	void HandleItemToInspectChangedBP(bool bWasFavoritedChanged);

	UFUNCTION()
	void HandleItemToInspectDestroyed();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Inspect")
	void HandleItemToInspectDestroyedBP();

	UFUNCTION(BlueprintPure, Category="Item Inspect")
	bool IsItemSlottedInCollectionBook(const UFortItem* Item) const;

	UFUNCTION(BlueprintCallable, Category="Item Inspect")
	void SetInspectionMode(EFortItemInspectionMode NewInspectMode);

	UFUNCTION(BlueprintCallable, Category="Item Inspect")
	void SetItemToRepresent(UFortItem* Item);

	UPROPERTY(BlueprintReadWrite, Category="Item Inspect")
	EFortItemInspectionMode CurrentInspectMode;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	TWeakObjectPtr<UFortItem> InspectedItem;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	bool UpgradeAllowed;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	bool EvolveAllowed;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	bool FavoriteAllowed;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	bool RarityUpgradingAllowed;

	UPROPERTY(BlueprintReadOnly, Category="Item Inspect")
	bool IsPreviewing;

	UPROPERTY(BlueprintReadWrite, Category="Item Inspect")
	bool bHasSeenRefundHelpPrompt;

	UPROPERTY(BlueprintReadOnly, Export, Category="Item Inspect", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortItemInspectCycleWidget> CycleWidget;

	UPROPERTY(EditDefaultsOnly, Category="Item Inspect")
	FGameplayTagQuery InspectAnimationTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Inspect")
	TSubclassOf<UFortAlterationModOptinScreenBase> AlterationModOptinScreenClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Inspect")
	TSubclassOf<UFortAlterationModScreenBase> AlterationModScreenClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Item Inspect")
	TSoftObjectPtr<UDataTable> RefundDescriptionsDataTable;

};

