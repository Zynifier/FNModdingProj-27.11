// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCraftingFormulaIngredientsWidget.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCraftingFormulaIngredientsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingFormulaIngredientsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="FortCraftingIngredientWidget"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Ingredients;

};

