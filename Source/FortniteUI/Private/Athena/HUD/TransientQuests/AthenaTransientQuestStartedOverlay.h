// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaTransientQuestStartedOverlay.generated.h"

class UCommonButtonLegacy;
class UFortQuestItem;
class UFortQuestItemDefinition_Athena;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaTransientQuestStartedOverlay : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetOutroDelay() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrioitizedActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrioitizedFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTransientQuestStarted(const UFortQuestItem* QuestItem);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaTransientQuestStartedOverlay")
	FFortPrioritizedWidgetData PrioritizedWidgetData;

private:
	UFUNCTION()
	void HandleTransientQuestStarted(const UFortQuestItem* QuestItem, const UFortQuestItemDefinition_Athena* PreceedingQuestDefAthena);

	UPROPERTY(BlueprintReadWrite, Export, Category="AthenaTransientQuestStartedOverlay", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_MobileClickCatcher;

};

