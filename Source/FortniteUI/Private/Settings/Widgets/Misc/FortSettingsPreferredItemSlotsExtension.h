// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingDetailExtension.h"
#include "FortSettingsPreferredItemSlotsExtension.generated.h"

class UHorizontalBox;
class UImage;

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UFortSettingsPreferredItemSlotsExtension : public UFortSettingDetailExtension
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortSettingsPreferredItemSlotsExtension", meta=(EditInline="true"))
	TArray<TObjectPtr<UImage>> SlotItemIconImages;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortSettingsPreferredItemSlotsExtension", meta=(EditInline="true"))
	TArray<TObjectPtr<UImage>> HighlightImages;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSettingsPreferredItemSlotsExtension", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HorizontalBox_ItemSlotContainer;

};

