// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortQuestUpdateEntry.generated.h"

class UFortQuestItem;
class UFortQuestObjectiveEntry;
class UFortQuestObjectiveInfo;
class UFortQuestUpdateEntry;
class UPanelWidget;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFinishedDisplayingQuests, UFortQuestUpdateEntry*, QuestEntry);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestUpdateEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Quests")
	bool CanAddObjective(UFortQuestItem* QuestItemToCheck);

	UFUNCTION(BlueprintCallable, Category="Quests")
	void FinishQuestIntro();

	UFUNCTION(BlueprintCallable, Category="Quests")
	virtual void FinishQuestOutro();

	UFUNCTION(BlueprintCallable, Category="Quests")
	int32 GetNumDisplayedObjectives();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void QuestItemSet(UFortQuestItem* QuestItemToCheck);

	UFUNCTION(BlueprintCallable, Category="Quests")
	virtual void SetQuestItem(const UFortQuestObjectiveInfo* ObjectiveInfo, bool bIsAnnouncement);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Quests")
	void SetupAsAnnouncement();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void StartQuestIntro();

	UFUNCTION(BlueprintImplementableEvent, Category="Quests")
	void StartQuestOutro();

	UPROPERTY(BlueprintAssignable)
	FFinishedDisplayingQuests FinishedDisplayingQuests;

protected:
	UFUNCTION()
	void CurrentlyDisplayedObjectiveFinished(UFortQuestObjectiveEntry* QuestObjective);

	UPROPERTY(BlueprintReadOnly, Export, Category="Quests", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> ObjectivesBox;

	UPROPERTY(EditDefaultsOnly, Category="Quests")
	int32 NumberOfObjectivesToDisplayAtTheSameTime;

	UPROPERTY(EditDefaultsOnly, Category="Quests", meta=(ClampMin="1", EditCondition="NumberOfObjectivesToDisplayAtTheSameTime < 0"))
	int32 NumberOfWidgetsToPreCreateWhenDisplayingAllObjectives;

	UPROPERTY()
	TObjectPtr<UFortQuestItem> QuestItem;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Quests", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortQuestObjectiveEntry> SubEntryClass;

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortQuestObjectiveEntry>> QuestObjectiveEntryPool;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortQuestObjectiveEntry>> AvailableQuestObjectiveEntryArray;

};

