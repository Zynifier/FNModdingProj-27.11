// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Camera/FortCameraFramingTypes.h"
#include "FortHeroLoadoutScreenBase.generated.h"

class AActor;
class UDataTable;
class UFortCampaignHeroLoadoutItem;
class UFortItem;
class UFortItemTileView;
class UFortItemView;
class UWidget;
class UWidgetAnimation;
enum class EFortItemInspectionMode : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroLoadoutScreenBase : public UCommonActivatableWidget, public IFortUICameraFrameInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsLoadoutSwitchingAllowed() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetHeroLoadout(const UFortCampaignHeroLoadoutItem* HeroLoadout);

protected:
	UFUNCTION(BlueprintPure)
	bool GetIsReadOnly() const;

	UFUNCTION(BlueprintImplementableEvent)
	UWidget* GetWidgetForFramingViewedItem();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleBackInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleClearAllInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleCyclePickerInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleDetailsInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleHelpInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleInspectPickerInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleInspectRootSlotsInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleShowAllStatsInputAction();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleToggleDescInputAction();

	UFUNCTION()
	void OnItemPreviewChanged(AActor* NewPrefab, UFortItem* NewItem);

	UFUNCTION(BlueprintCallable)
	void SetInputBindings(const bool ActivePickerBox, const bool CommanderSlot, const bool NoneSlot, const bool CanClearAll);

	UPROPERTY(BlueprintReadOnly, Transient, Instanced, Category="FortHeroLoadoutScreenBase")
	TObjectPtr<UFortItemView> ItemViewObject;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HelpInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CancelInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleDetailInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClearAllInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ShowAllStatsInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectRootSlotsInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CyclePickerSortModeInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle InspectPickerInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Input Actions", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleDescInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool AllowItemRotation;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool AllowItemZooming;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool AutomaticallyRegisterCameraView;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool OverrideFixedCameras;

	UPROPERTY()
	TObjectPtr<UDataTable> ActionDataTable;

	UPROPERTY(BlueprintReadWrite, Category="Item View")
	TObjectPtr<UWidgetAnimation> AnimationToHideItemInfo;

	UPROPERTY(BlueprintReadWrite, Category="Item View")
	bool bAutoShowDetails;

	UPROPERTY(Transient)
	bool bItemDetailsHidden;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float HideItemInfoHeaderDurationSecs;

private:
	UFUNCTION(BlueprintCallable)
	void HideItemDetails();

	UFUNCTION()
	void OnVaultItemsViewed(const TArray<UFortItem*>& Items);

	UFUNCTION(BlueprintCallable, Category="Utility")
	void PushItemInspectionScreen(UFortItem* ItemToInspect, EFortItemInspectionMode Mode, UFortItemTileView* CycleTileView = nullptr, bool bReadOnly = false, bool bAllowFavoriting = true, bool bIsTemporaryItem = false, bool bAllowRarityUpgrading = true);

	UFUNCTION(BlueprintCallable)
	void ShowItemDetails();

};

