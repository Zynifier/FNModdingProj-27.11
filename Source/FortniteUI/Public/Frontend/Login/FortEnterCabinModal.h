// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "UIManager/FortPrimaryContentInterface.h"
#include "FortEnterCabinModal.generated.h"

class UCommonButtonBase;
class UFortRichTextBlockLegacy;
class UWidget;
class UWidgetSwitcher;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortEnterCabinModal : public UCommonActivatableWidget, public IFortPrimaryContentInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortEnterCabinModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher_CabinScreens;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortEnterCabinModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VerticalBox_CrewCancelled;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortEnterCabinModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> VerticalBox_EnterCabin;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SwapPanel(UWidget* PanelToSwapTo);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortEnterCabinModal", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortRichTextBlockLegacy> LinkText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Continue;

};

