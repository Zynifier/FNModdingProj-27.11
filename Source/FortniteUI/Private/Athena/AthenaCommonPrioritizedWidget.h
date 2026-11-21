// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaCommonPrioritizedWidget.generated.h"

UCLASS(meta=(DisableNativeTick))
class UAthenaCommonPrioritizedWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Active"))
	void K2_OnBecomeActive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Inactive"))
	void K2_OnBecomeInactive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompedByOtherWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompFailed();

	UPROPERTY(EditAnywhere, Category="Prioritization")
	bool bAutoManagePriorityByVisibility;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

