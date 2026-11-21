// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortStandaloneModalPopup.generated.h"

class UCommonBorder;
class UCommonButtonLegacy;
class UFortStoreFrontOfferWidgetBase_Legacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortStandaloneModalPopup : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Dismiss();

private:
	UFUNCTION()
	void HandleDetailsButtonClicked();

	UFUNCTION()
	void HandleInputActionButton(bool& bPassThrough);

	UPROPERTY(EditAnywhere, Category="FortStandaloneModalPopup", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle buttonInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonLegacy* Button_Details;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonButtonLegacy* Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UCommonBorder* Border_TapToCloseZone;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	UFortStoreFrontOfferWidgetBase_Legacy* ItemShopStandaloneOfferPreview;

};

