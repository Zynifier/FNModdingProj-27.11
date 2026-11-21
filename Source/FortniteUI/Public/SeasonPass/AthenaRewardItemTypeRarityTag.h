// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "FortRarityData.h"
#include "AthenaRewardItemTypeRarityTag.generated.h"

class UBorder;
class UCommonTextBlock;
class UFortItemSeriesDefinition;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaRewardItemTypeRarityTag : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeRarityWithoutSeries(FFortRarityItemData RarityData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnInitializeRarityWithSeries(const UFortItemSeriesDefinition* SeriesData);

	UPROPERTY(EditDefaultsOnly, Category="AthenaRewardItemTypeRarityTag")
	FGameplayTag HideRarityGameplayTag;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRewardItemTypeRarityTag", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRewardItemTypeRarityTag", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_RarityTint;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRewardItemTypeRarityTag", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemRarity;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaRewardItemTypeRarityTag", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemType;

};

