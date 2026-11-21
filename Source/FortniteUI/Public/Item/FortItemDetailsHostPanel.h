// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemQuantityPair.h"
#include "FortTypes.h"
#include "FortItemDetailsHostPanel.generated.h"

class IFortItemViewContextInterface;
class UCommonBorder;
class UCommonLoadGuard;
class UFortItem;
class UFortItemDefinition;
class UFortTooltipLoadingWrapper;
class UNamedSlot;
class UScrollBox;
enum class EFortItemInspectionMode : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, meta=(DisableNativeTick))
class UFortItemDetailElementWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	TSoftObjectPtr<UFortItemDefinition> DesignTimePreviewItemType;
#endif

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleInspectModeChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleItemToCompareWithChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleItemToDetailChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandlePostDifferentItemToCompareWithSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandlePostDifferentItemToDetailSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandlePreDifferentItemToCompareWithSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandlePreDifferentItemToDetailSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleQuantityOverrideChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleShouldPreviewUpgradingItemChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleUpgradeLevelDeltaChanged();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	bool bShouldPreviewUpgradingItem;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	int32 UpgradeLevelDelta;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailElementWidget")
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailElementWidget")
	EFortItemInspectionMode CurrentInspectMode;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	int32 QuantityOverride;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailElementWidget")
	bool bIsUpdatingSuspended;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UFortItem> DesignTimePreviewItem;
#endif

};

UCLASS(Abstract, MinimalAPI, BlueprintType, meta=(DisableNativeTick))
class UFortItemDetailsHostPanel : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnItemChangedDelegate);

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleItemToDetailChangedBP();

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetInspectMode(EFortItemInspectionMode InspectMode);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetIsUpdatingSuspended(const bool bValue);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetItemToCompareWith(const UFortItem* ItemToCompareWith);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetItemToDetail(const UFortItem* ItemToDetail);

	UFUNCTION(BlueprintCallable, Category="Item Widget")
	FORTNITEUI_API void SetItemViewContext(const TScriptInterface<IFortItemViewContextInterface>& ItemViewContext);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetQuantityOverride(const int32 QuantityOverride);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetScrollWidget();

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void SetUpgradeLevelDelta(const int32 InDelta);

	UFUNCTION(BlueprintCallable, Category="Item Details")
	FORTNITEUI_API void ShouldPreviewUpgradingItem(const bool Value);

	UPROPERTY(BlueprintAssignable)
	FOnItemChangedDelegate OnItemChanged;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	TSoftObjectPtr<UFortItemDefinition> DesignTimePreviewItemType;
#endif

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleDifferentItemToCompareSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleDifferentItemToDetailSet();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleInspectModeChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleItemToCompareTooltipAssetsLoading();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleItemToDetailTooltipAssetsLoading();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Management|Details")
	FORTNITEUI_API void HandleQuantityOverrideChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleShouldPreviewUpgradingItemChangedBP();

	UFUNCTION(BlueprintImplementableEvent, Category="Item Details")
	FORTNITEUI_API void HandleUpgradeLevelDeltaChangedBP();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	TWeakObjectPtr<UFortItem> ItemToDetail;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	TWeakObjectPtr<UFortItem> ItemToCompareWith;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel", meta=(ScriptName="ShouldPreviewUpgradingItemValue"))
	bool bShouldPreviewUpgradingItem;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	int32 UpgradeLevelDelta;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UNamedSlot> DetailsContainerSlotWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonBorder> HighRarityBorder;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

	UPROPERTY(BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	EFortItemInspectionMode CurrentInspectMode;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	int32 QuantityOverride;

	UPROPERTY()
	TObjectPtr<UFortTooltipLoadingWrapper> ItemToDetailLoadingWrapper;

	UPROPERTY()
	TObjectPtr<UFortTooltipLoadingWrapper> ItemToCompareLoadingWrapper;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> ItemToDetailLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> ItemToCompareLoadGuard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemDetailsHostPanel", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_Details;

	UPROPERTY(EditAnywhere, Category="FortItemDetailsHostPanel")
	bool bAsyncLoadTooltipData;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category="FortItemDetailsHostPanel")
	bool bIsUpdatingSuspended;

private:
	UFUNCTION()
	FORTNITEUI_API void HandleItemEvolutionComplete(const bool bWasSuccessful, const FString& ConvertedItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemsQuantities);

	UFUNCTION()
	FORTNITEUI_API void HandleItemRarityUpgradeComplete(const bool bWasSuccessful, const FString& ConvertedItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemsQuantities);

	UFUNCTION()
	FORTNITEUI_API void HandleItemRefundComplete(const bool bWasSuccessful, const FString& ConvertedItemInstanceId, const TArray<FFortItemInstanceQuantityPair>& ItemsQuantities);

	UFUNCTION()
	FORTNITEUI_API void HandleItemToCompareTooltipAssetsLoaded();

	UFUNCTION()
	FORTNITEUI_API void HandleItemToDetailTooltipAssetsLoaded();

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UFortItem> DesignTimePreviewItem;
#endif

};

