// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCraftingIngredientWidget.generated.h"

class UAthenaItemIcon;
class UCommonLazyImage;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCraftingIngredientWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnIngredientWidgetUpdated(const int32 NumAvailable, const int32 NumRequired, const bool bIsPrimaryIngredient, const bool bIsLastIngredient);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingIngredientWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumAvailable;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingIngredientWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumRequired;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingIngredientWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaItemIcon> ItemIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCraftingIngredientWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonLazyImage> LazyImage_Icon;

};

