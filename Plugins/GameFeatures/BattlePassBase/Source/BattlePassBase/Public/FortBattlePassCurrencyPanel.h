// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortBattlePassResourcesWidgetBase.h"
#include "FortBattlePassCurrencyPanel.generated.h"

class UCommonTextBlock;
class UHorizontalBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class BATTLEPASSBASE_API UFortBattlePassCurrencyPanel : public UFortBattlePassResourcesWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_BattleStarContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_BattleStar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> HBox_CustomSkinContainer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CustomSkin;

};

