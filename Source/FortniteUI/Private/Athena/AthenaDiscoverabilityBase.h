// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaDiscoverabilityBase.generated.h"

class UFortControllerComponent_MapDiscoverability;

UCLASS()
class UAthenaDiscoverabilityBase : public UFortHUDElementWidget, public IAthenaCoupledWidgetInterface, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void CommonArrivalEvent(const FGameplayTag& NewTag);

	UFUNCTION()
	virtual void CommonDiscoveredEvent(const FGameplayTag& NewTag);

	UFUNCTION()
	virtual void CommonVisitedEvent(const FGameplayTag& NewTag);

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

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortControllerComponent_MapDiscoverability> AssociatedComponent;

};

