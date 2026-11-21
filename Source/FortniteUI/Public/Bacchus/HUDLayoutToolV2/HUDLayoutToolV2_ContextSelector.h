// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "HUDLayoutToolV2_ContextSelector.generated.h"

class UFortDynamicEntryBox;
class UHUDLayoutToolV2_ContextButton;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_ContextSelector : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_ContextButton> EditContextButton;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UHUDLayoutToolV2_ContextButton> VisibleContextButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_MainLayoutButtons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_VehicleLayoutButtons;

};

