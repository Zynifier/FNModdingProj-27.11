// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "FortCookingScreen.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortSlottedRadialMenu;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCookingScreen : public UCommonActivatableWidget, public IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCookingScreen")
	FDataTableRowHandle CloseInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EjectAll;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RecipeName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RecipeDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Recipe;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSlottedRadialMenu> RadialMenu_Recipes;

};

