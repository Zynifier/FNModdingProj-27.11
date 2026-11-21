// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "POIBannerToastWidgetBase.generated.h"

UCLASS()
class UPOIBannerToastWidgetBase : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	const FText& GetLocationTextFromTag(const FGameplayTag& LocationTag) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Active"))
	void K2_OnBecomeActive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization", meta=(DisplayName="On Become Inactive"))
	void K2_OnBecomeInactive();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompedByOtherWidget();

	UFUNCTION(BlueprintImplementableEvent, Category="Prioritization")
	void OnStompFailed();

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

};

