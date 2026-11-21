// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Mobile/BacchusHUDElement.h"
#include "BacchusAvailablePickupsDisplay.generated.h"

class AFortPickup;
class UCommonButtonLegacy;
class UCommonButtonStyle;
class UFortDynamicEntryBox;

UCLASS(meta=(DisableNativeTick))
class UBacchusAvailablePickupsDisplay : public UBacchusHUDElement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> ListCollapsedButtonStyle;

	UPROPERTY(EditAnywhere, Category="Styles")
	TSubclassOf<UCommonButtonStyle> ListVisibleButtonStyle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ToggleVisibility;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_PickupButtons;

	UPROPERTY()
	TArray<TWeakObjectPtr<AFortPickup>> CurrentPickupArray;

};

