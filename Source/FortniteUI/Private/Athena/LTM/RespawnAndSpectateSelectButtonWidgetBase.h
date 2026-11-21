// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "RespawnAndSpectateSelectButtonWidgetBase.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortLazyImage;
class UImage;
class URespawnAndSpectateSelectButtonWidgetBase;
class USizeBox;

UCLASS(meta=(DisableNativeTick))
class URespawnAndSpectateSelectButtonWidgetBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRespawnAndSpectateSelectButtonHovered, URespawnAndSpectateSelectButtonWidgetBase*, Widget);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRespawnAndSpectateSelectButtonSelected, URespawnAndSpectateSelectButtonWidgetBase*, Widget);

public:
	UFUNCTION(BlueprintCallable)
	void OnSelectionHovered();

	UFUNCTION(BlueprintCallable)
	void OnSelectionMade();

	UFUNCTION(BlueprintImplementableEvent)
	void SetHoverHighlightVisibility(bool bNewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void SetNavigationFocusOnButton();

	UFUNCTION(BlueprintImplementableEvent)
	void SetSelectionVisualsVisibility(bool bNewVisibility);

	UPROPERTY(BlueprintAssignable)
	FOnRespawnAndSpectateSelectButtonSelected OnButtonSelected;

	UPROPERTY(BlueprintAssignable)
	FOnRespawnAndSpectateSelectButtonHovered OnButtonHovered;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void IsSelectableUpdated_BP();

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsEnabledUpdated_BP(bool bNewIsEnabled);

	UFUNCTION(BlueprintImplementableEvent)
	void SetButtonVisibility_BP(bool bNewVisbility);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="RespawnAndSpectateSelectButtonWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> TargetImageSizeBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="RespawnAndSpectateSelectButtonWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> DefaultButtonImageSizeBox;

	UPROPERTY(BlueprintReadWrite, Export, Category="RespawnAndSpectateSelectButtonWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> TargetButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> TargetImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DefaultButtonImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="RespawnAndSpectateSelectButtonWidgetBase", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TargetNameTextWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="RespawnAndSpectateSelectButtonWidgetBase", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_TargetState;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="RespawnAndSpectateSelectButtonWidgetBase")
	int32 ButtonIndex;

	UPROPERTY(BlueprintReadOnly, Category="RespawnAndSpectateSelectButtonWidgetBase")
	bool bIsSelectable;

};

