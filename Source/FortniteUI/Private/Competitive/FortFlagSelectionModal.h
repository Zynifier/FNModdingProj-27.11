// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortFlagSelectionModal.generated.h"

class UCommonButtonBase;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UCommonTileView;
class UFortFlagImage;
class UFortFlagObject;
class UImage;

UCLASS(meta=(Category="Fortnite UI", DisableNativeTick))
class UFortFlagSelectionModal : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortFlagSelectionModal")
	TObjectPtr<UFortFlagObject> SelectedFlag;

	UPROPERTY(EditAnywhere, Category="FortFlagSelectionModal")
	float FlagConfirmSpinnerDelay;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Confirmation;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CurrentFlagRegionName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> CurrentFlagImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> ConfirmationCurrentFlagImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFlagImage> ConfirmationTargetFlagImage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView_FlagOptions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FlagRegionName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChangeRegionBlock;

	UPROPERTY(Export, meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Change;

	UPROPERTY(Export, meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ConfirmationCancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ConfirmationConfirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_CloseMobile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Spinner;

};

