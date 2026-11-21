// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortBangWrapper_NUI.h"
#include "FortTutorialQuestVisibilityWrapper.generated.h"

class UFortQuestItemDefinition;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTutorialQuestVisibilityWrapper : public UFortBangWrapper_NUI
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TutorialQuestWrapper", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortQuestItemDefinition> QuestItemDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TutorialQuestWrapper", meta=(ExposeOnSpawn="TRUE", RowType="/Script/FortniteGame.FortQuestObjectiveStatTableRow"))
	FDataTableRowHandle QuestObjectiveStat;

private:
	UFUNCTION()
	void HandleCurrentQuestsChanged();

};

