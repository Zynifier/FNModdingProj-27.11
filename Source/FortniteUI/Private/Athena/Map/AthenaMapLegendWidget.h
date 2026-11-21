// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameFeatures/FortUIGameFeatureAction_AddMapLegendEntries.h"
#include "AthenaMapLegendWidget.generated.h"

class UDynamicEntryBox;
class UPanelWidget;

UCLASS()
class UAthenaMapLegendWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="AthenaMapLegendWidget")
	TArray<FAthenaMapLegendEntryData> MapLegendEntries;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> SizeBox_LegendPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true", EntryClass="UAthenaMapLegendEntryWidget"))
	TObjectPtr<UDynamicEntryBox> EntryBox_LegendEntries;

};

