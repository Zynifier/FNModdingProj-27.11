// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortRarityData.h"
#include "AthenaInventoryItemStatEntry.generated.h"

class UCommonTextBlock;
enum class EFortRarity : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaInventoryItemStatEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnItemRaritySet(const EFortRarity ItemRarity, const FFortRarityItemData RarityItemData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStatInitialized(const float Value, const float ComparisonValue, const float MinValue, const float MaxValue);

	UPROPERTY(BlueprintReadOnly, Category="AthenaInventoryItemStatEntry")
	bool bValueIsInfinite;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemStatEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StatName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemStatEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StatValue;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaInventoryItemStatEntry", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StatDeltaValue;

	UPROPERTY(EditAnywhere, Category="AthenaInventoryItemStatEntry")
	FText StatDeltaTextFormat;

};

