// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortTournamentPosterViolator.generated.h"

class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
enum class ETournmentPosterViolatorState : uint8;

UENUM(BlueprintType)
enum class ETournmentPosterViolatorState : uint8
{
	Hidden = 0,
	Live = 1,
	Countdown = 2,
	Info = 3,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortTournamentPosterViolator : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnViolatorStateRefreshed(ETournmentPosterViolatorState NewTimeState);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTournamentPosterViolator", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> WidgetSwitcher_EventStateSwitcher;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_InformationViolator;

};

