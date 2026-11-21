// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortItemListPreviewWidget.generated.h"

class UCommonButtonLegacy;
class UFortHoldableButton;
class UTileView;
class UWidget;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortItemListPreviewWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemListPreviewWidget", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_Items;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Container_Items;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviewVariants;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortItemListPreviewWidget", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	UFortHoldableButton* Button_Subscribe;

};

