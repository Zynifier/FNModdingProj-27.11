// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Camera/FortCameraFramingTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortActivatablePanelWithItemPreview.generated.h"

class AActor;
class UDataTable;
class UFortItem;
class UFortItemView;
class UWidget;
class UWidgetAnimation;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortActivatablePanelWithItemPreview : public UFortActivatablePanel, public IFortUICameraFrameInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API UWidget* GetWidgetForFramingViewedItem();

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_0(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_1(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_2(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_3(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_4(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_5(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_6(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnCosmeticSpecialActionPressed_7(bool& bPassThrough);

	UFUNCTION()
	FORTNITEUI_API void OnItemPreviewChanged(AActor* NewPrefab, UFortItem* NewItem);

	UPROPERTY(BlueprintReadOnly, Transient, Instanced, Category="FortActivatablePanelWithItemPreview")
	TObjectPtr<UFortItemView> ItemViewObject;

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemViewUnifiedSupportsCameraControlInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemViewUnifiedZoomInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemViewZoomOutInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemViewZoomInInputAction;

	UPROPERTY(EditDefaultsOnly, Category="Item View", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ItemViewRotateInputAction;

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
	FORTNITEUI_API void HideItemDetails();

	UFUNCTION()
	FORTNITEUI_API void OnVaultItemsViewed(const TArray<UFortItem*>& Items);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void ShowItemDetails();

};

