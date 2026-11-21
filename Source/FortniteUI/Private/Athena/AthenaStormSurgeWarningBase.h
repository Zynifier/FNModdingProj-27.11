// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaStormSurgeWarningBase.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaStormSurgeWarningBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnStartDisplaying(const FText& TitleText, const FText& SubTitleText, bool bDisplaySubtitle, bool bPlayDamageActiveSound);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStopDisplaying();

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

