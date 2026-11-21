// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaCountdownWidgetBase.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCountdownWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCountdownFinished();

	UFUNCTION()
	void HandleCountdownStarted(int32 TimeRemaining);

	UFUNCTION()
	void HandleCountdownStopped();

	UFUNCTION()
	void HandleCountdownUpdate(int32 TimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownStarted(int32 TimeRemaining, const FText& CountdownIntroText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownStopped();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownUpdate(int32 TimeRemaining, const FText& CountdownUpdateText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayWarningMessage(const FText& FirstLineText, const FText& SecondLineText);

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

