// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaFullScreenMapBrowsingControlsWidget.generated.h"

class UCommonTextBlock;
class UPanelWidget;
class USizeBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaFullScreenMapBrowsingControlsWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapBrowsingControlsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_PanGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapBrowsingControlsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_ZoomGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapBrowsingControlsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_PlaceMarker;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlaceMarker;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenMapBrowsingControlsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_TeleportToMarker;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Place Marker"))
	FText TextPlaceMarker;

	UPROPERTY(EditAnywhere, Category="Text", meta=(DisplayName="Remove Marker"))
	FText TextRemoveMarker;

};

