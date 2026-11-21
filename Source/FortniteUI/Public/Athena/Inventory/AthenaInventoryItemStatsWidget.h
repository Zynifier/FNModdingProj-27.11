// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaInventoryItemStatsWidget.generated.h"

class UDataTable;
class UDynamicEntryBox;
class UFortTooltipLoadingWrapper;

UCLASS(Abstract, Blueprintable, meta=(DisableNativeTick, NotBlueprintType="true"))
class UAthenaInventoryItemStatsWidget : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleTooltipAssetsLoaded();

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemStatsWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true", EntryClass="AthenaInventoryItemStatEntry"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Stats;

	UPROPERTY(EditAnywhere, Category="Weapon Stat Min/Max Value Table")
	TObjectPtr<UDataTable> ItemStatsBoundsTable;

	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipLoadingWrapper> ItemTooltipLoader;

	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipLoadingWrapper> ComparisonItemTooltipLoader;

};

