// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortPotContentsPopup.generated.h"

class ACraftingObjectBGA;
class UCommonTextBlock;
class UCommonTileView;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPotContentsPopup : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortPotContentsPopup(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="Setup")
	void SetOwningCraftingObject(ACraftingObjectBGA* InCraftingObject);

private:
	UPROPERTY(EditAnywhere, Category="List Settings")
	int32 MaxItemsToShow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTileView> TileView_PotContents;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MoreItems;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Overlay_Popup;

};

