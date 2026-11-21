// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidgetPool.h"
#include "CommonUserWidget.h"
#include "Misc/Guid.h"
#include "Types/SlateEnums.h"
#include "AthenaFullScreenMapProductGroup.generated.h"

class UAthenaFullScreenMapQuestCategoryBase;
class UAthenaFullScreenMapQuestCategoryButton;
class UAthenaFullScreenMapQuestInactiveCategoryButton;
class UAthenaFullScreenMapQuestProductButton;
class UCommonButtonGroupBase;
class UVerticalBox;
class UWidget;

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaFullScreenMapProductGroup : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	UWidget* HandleExternalNavigationRequest(EUINavigation InNavigation);

	UPROPERTY(EditDefaultsOnly, Category="Categories")
	TSubclassOf<UAthenaFullScreenMapQuestCategoryButton> ActiveCategoryButtonType;

	UPROPERTY(EditDefaultsOnly, Category="Categories")
	TSubclassOf<UAthenaFullScreenMapQuestInactiveCategoryButton> InactiveCategoryButtonType;

	UPROPERTY(EditDefaultsOnly, Category="Categories")
	float CategoryButtonPadding;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapProductGroup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapQuestProductButton> Button_Product;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapProductGroup", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VB_Categories;

private:
	UPROPERTY(Transient)
	FUserWidgetPool CategoryWidgetPool;

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup;

	UPROPERTY(Export, meta=(EditInline="true"))
	TMap<FGuid, TObjectPtr<UAthenaFullScreenMapQuestCategoryBase>> CategoryInstanceMap;

};

