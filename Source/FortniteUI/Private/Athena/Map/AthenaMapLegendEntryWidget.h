// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaMapLegendEntryWidget.generated.h"

class UCommonTextBlock;
class UDynamicEntryBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapLegendEntryWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="UAthenaMapLegendEntryIcon"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_LegendIcons;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaMapLegendEntryWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EntryName;

};

