// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortItemInfoWidget.generated.h"

class UCommonTextBlock;
class UFortItem;
class UFortItemDefinition;
class UOverlay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemInfoWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void PopulateUsingItem(UFortItem* NewItem);

	UFUNCTION(BlueprintCallable)
	void PopulateUsingItemDefinition(UFortItemDefinition* NewItem);

	UFUNCTION(BlueprintImplementableEvent)
	void SetRarityMaterialValues(UFortItemDefinition* ItemDefinition);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemInfoWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Name;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Desc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_MainView;

};

