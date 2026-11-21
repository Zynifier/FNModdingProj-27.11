// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/SlottedWidgets/FortPrioritizedWidgetInterface.h"
#include "Athena/SlottedWidgets/PrioritizedWidgetTypes.h"
#include "FortHUDElementWidget.h"
#include "FortQuestUpdatesLog.generated.h"

class UFortQuestObjectiveInfo;
class UFortQuestUpdateEntry;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestUpdatesLog : public UFortHUDElementWidget, public IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void CreateAnnouncementUpdate(const UFortQuestObjectiveInfo* QuestItemToCheck);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortQuestUpdateEntry> QuestEntryClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	int32 MaxDisplayedQuestUpdates;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	int32 MaxDisplayedQuestObjectives;

	UPROPERTY(EditAnywhere, Category="Quests")
	bool bShowFeatQuests;

	UPROPERTY(EditAnywhere, Category="Quests")
	bool bFeatShowNonVisibleObjectives;

protected:
	UFUNCTION()
	void HandleDisplayDynamicQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool DisplayStatusUpdate, bool DisplayAnnouncementUpdate);

	UFUNCTION()
	void HandleQuestUpdateFinished(UFortQuestUpdateEntry* QuestEntryFinished);

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> QuestUpdatesBox;

	UPROPERTY(EditAnywhere, Category="Widget Priority")
	FFortPrioritizedWidgetData PrioritizationData;

	UPROPERTY()
	TArray<TObjectPtr<UFortQuestObjectiveInfo>> QueuedQuestObjectiveInfos;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortQuestUpdateEntry>> QuestUpdateWidgets;

};

