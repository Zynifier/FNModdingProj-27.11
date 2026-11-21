// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBattlePassResourcesWidgetBase.h"
#include "FortBattlePassResourcesWidgetS27.generated.h"

class UBorder;
class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBattlePassResourcesWidgetS27 : public UFortBattlePassResourcesWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBattleStarRewardsSet(const int32 Rewards);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStylePointsRewardsSet(const int32 Rewards);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourcesWidgetS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BattleStarsAmount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourcesWidgetS27", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_StylePointsAmount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourcesWidgetS27", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_StylePointsRewardsTag;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortBattlePassResourcesWidgetS27", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_BattleStarsRewardsTag;

};

