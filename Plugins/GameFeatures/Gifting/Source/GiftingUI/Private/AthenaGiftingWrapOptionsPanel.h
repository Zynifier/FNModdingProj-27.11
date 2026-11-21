// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "AthenaGiftingWrapOptionsPanel.generated.h"

class UCommonButtonLegacy;
class UFortGiftBoxItemDefinition;
class UTileView;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaGiftingWrapOptionsPanel : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaGiftingWrapOptionsPanel")
	TArray<TSoftObjectPtr<UFortGiftBoxItemDefinition>> GiftBoxes;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGiftBoxItemDefinition>> GiftBoxItemDefs;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ConfirmWrap;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTileView> TileView_WrapOptions;

};

