// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortWeaponWheel.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortKeybindWidget;
class UFortSlottedRadialMenu;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortWeaponWheel : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Item Chosen"))
	void BP_OnItemChosen();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlaySelectionAnimation();

private:
	UPROPERTY(EditAnywhere, Category="Options")
	bool bRememberLastItem;

	UPROPERTY(Transient)
	int32 NumOfQuickBarItems;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle VirtualAcceptInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSlottedRadialMenu> RadialMenu_Picker;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortKeybindWidget> Keybind_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RadialHighlight;

};

