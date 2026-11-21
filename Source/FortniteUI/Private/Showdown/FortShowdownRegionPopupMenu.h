// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPopupMenuLegacy.h"
#include "FortShowdownRegionPopupMenu.generated.h"

class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonButtonLegacy;
class UCommonButtonStyle;
class UDynamicEntryBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowdownRegionEntryChanged, int32, SelectedButtonIndex);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortShowdownRegionPopupMenu : public UCommonPopupMenuLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnShowdownRegionEntryChanged OnRegionChanged;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_SetButtonText(UCommonButtonLegacy* Button, const FText& Text);

	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsMenuPopupOpen);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortShowdownRegionPopupMenu", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_BindableActions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortShowdownRegionPopupMenu")
	TSubclassOf<UCommonButtonStyle> Style;

private:
	UFUNCTION()
	void HandleSelectedButtonClicked(UCommonButtonBase* SelectedButton, int32 SelectedButtonIndex);

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup;

};

