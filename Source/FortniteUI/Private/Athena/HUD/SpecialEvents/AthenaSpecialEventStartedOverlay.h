// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortUrgentQuestData.h"
#include "AthenaSpecialEventStartedOverlay.generated.h"

class AFortPlayerStateAthena;
class UFortQuestObjectiveInfo;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpecialEventStartedOverlay : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetOutroDelay() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrioitizedActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPrioitizedFinished();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData, const float EventTimeRemaining);

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpecialEventStartedOverlay")
	TObjectPtr<AFortPlayerStateAthena> AttachedPlayerState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaSpecialEventStartedOverlay")
	FFortPrioritizedWidgetData PrioritizedWidgetData;

private:
	UFUNCTION()
	void HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData, const float EventTimeRemaining);

};

