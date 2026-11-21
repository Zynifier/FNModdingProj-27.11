// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortPickerOverlay.generated.h"

class UFortSlottedRadialMenu;
class UImage;
class UMaterialInstanceDynamic;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPickerOverlay : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Item Chosen"))
	void BP_OnItemChosen();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On No Item Chosen"))
	void BP_OnNoItemChosen();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlaySelectionAnimation();

private:
	UPROPERTY(EditAnywhere, Category="Input")
	FName GamepadActionName;

	UPROPERTY(EditAnywhere, Category="Input")
	FName KBMActionName;

	UPROPERTY(EditAnywhere, Category="Input")
	FName CancelActionName;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bShouldFlushInputOnActivation;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bShouldCenterMouseOnActivation;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bShouldCloseOnEmptySelection;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bAllowEmptySelection;

	UPROPERTY(EditAnywhere, Category="Settings")
	bool bRememberLastItem;

	UPROPERTY(EditAnywhere, Category="Bindings")
	FDataTableRowHandle VirtualAcceptInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSlottedRadialMenu> RadialMenu_Picker;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_RadialHighlight;

	UPROPERTY(EditAnywhere, Category="Selection Image")
	FName RadialSelectionMaterialParameterName;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> RadialHighlightMID;

};

