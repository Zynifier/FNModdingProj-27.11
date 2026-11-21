// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/FortQuestToolListView.h"
#include "Quests/FortMcpQuestObjectiveInfo.h"
#include "FortQuestToolObjectivesListView.generated.h"

class UFortQuestToolListEntry_NewObjective;

UCLASS(meta=(EntryClass="QuestToolListViewBase"))
class UFortQuestToolObjectivesListView : public UFortQuestToolListView
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 GetNumObjectiveEntries() const;

	UFUNCTION(BlueprintCallable)
	void InitObjectivesList(const TArray<FFortMcpQuestObjectiveInfo>& ObjectivesList);

protected:
	UPROPERTY(EditAnywhere, Category="ListEntries")
	TSubclassOf<UFortQuestToolListEntry_NewObjective> QuestToolNewObjectiveEntryClass;

};

