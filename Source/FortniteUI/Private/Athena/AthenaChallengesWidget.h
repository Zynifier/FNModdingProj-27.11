// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaChallengesWidget.generated.h"

class UDynamicEntryBox;
class UFortQuestObjectiveInfo;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengesWidget : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnWidgetActivated();

	UFUNCTION(BlueprintImplementableEvent)
	void BP_WidgetIsFinished();

	UFUNCTION()
	virtual void HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate);

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	bool IsXPSystemRequiredForChallenges() const;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengesWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_ChallengeEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AthenaChallengesWidget")
	FFortPrioritizedWidgetData PrioritizedWidgetData;

	UPROPERTY(EditDefaultsOnly, BlueprintGetter=IsXPSystemRequiredForChallenges, Category="AthenaChallengesWidget")
	bool bXPSystemRequiredForChallenges;

};

