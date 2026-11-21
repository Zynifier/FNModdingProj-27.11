// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RadialContextMenu/FortRadialSlot.h"
#include "FortRadialPickerEntry.generated.h"

class UCommonTextBlock;
class UHorizontalBox;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortRadialPickerEntry : public UFortRadialSlot
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnAvailabilityChanged(bool bIsAvailable);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortRadialPickerEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	UHorizontalBox* HorizontalBox_EntryName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRadialPickerEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Center;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortRadialPickerEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	UHorizontalBox* HorizontalBox_CenterText;

};

