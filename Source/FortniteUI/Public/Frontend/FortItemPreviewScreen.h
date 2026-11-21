// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Camera/FortCameraFramingTypes.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortItemPreviewScreen.generated.h"

class AFortItemPreviewSceneChanger;
class UCommonActivatableWidget;
class UCommonButtonBase;
class UCommonTextBlock;
class UCurveFloat;
class UFortItemDownloadIndicator;
class UFortItemView;
class UWidget;
class UWidgetAnimation;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowItemInfo, bool, ShowItemInfo);

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortItemPreviewScreen : public UFortActivatablePanel, public IFortUICameraFrameInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void HideItemDetails();

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void RequestChangeBackgroundMaterialScalarParameter(FName ParameterName, float Value);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void RequestChangeFloorMaterialScalarParameter(FName ParameterName, float Value);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void ShowItemDetails();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnPreviewActionButtonUpdated(const FText& RowDisplayName, UCommonButtonBase* Button);

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

	UPROPERTY(BlueprintReadWrite, Category="Item View")
	TObjectPtr<UWidgetAnimation> AnimationToHideItemInfo;

	UPROPERTY(BlueprintReadWrite, Category="Item View")
	bool bAutoShowDetails;

	UPROPERTY(Transient)
	bool bItemDetailsHidden;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	float HideItemInfoHeaderDurationSecs;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPreviewScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviewAction;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPreviewScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviewAction1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FortItemPreviewScreen", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Item View", meta=(EditInline="true"))
	TSet<TObjectPtr<UCommonButtonBase>> PreviewActionButtons;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortItemDownloadIndicator> ItemDownloadIndicator;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemPreviewScreen", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_DebugPreviewDetails;

private:
	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool bAllowItemRotation;

	UPROPERTY(EditDefaultsOnly, Category="Item View")
	bool bAllowItemZooming;

	UPROPERTY(EditAnywhere, Category="Camera Behavior", meta=(Categories="UI.ItemPreview.SceneChanger"))
	FGameplayTag PreviewSceneChangerTag;

	UPROPERTY(Transient)
	FGameplayTag PreviewSceneChangerOverrideTag;

	UPROPERTY(Transient)
	TObjectPtr<AFortItemPreviewSceneChanger> PreviewSceneChanger;

	UPROPERTY(BlueprintReadOnly, Transient, Instanced, Category="FortItemPreviewScreen", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<UFortItemView> ItemViewObject;

	UPROPERTY(EditDefaultsOnly, Category="Camera Behavior")
	float CameraEntryTransitionDuration;

	UPROPERTY(EditDefaultsOnly, Category="Camera Behavior")
	TObjectPtr<UCurveFloat> CameraEntryTransitionCurve;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_CameraFrame;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatableWidget> OverrideFocusWidget;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnShowItemInfo OnShowItemInfo;

};

