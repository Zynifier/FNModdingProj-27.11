// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaBroadcastPlayerEventScoreWidget.generated.h"

class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaBroadcastPlayerEventScoreWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPointTextSet();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> PlayerEventScoreText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> PlayerEventScoreSwitcher;

private:
	UFUNCTION()
	void OnRemoteClientEventScoreChanged(int32 NewEventScore);

};

