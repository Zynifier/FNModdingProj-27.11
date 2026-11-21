// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortQuestObjectivesEditor.generated.h"

class UFortQuestToolObjectivesListView;

UCLASS(Abstract)
class UFortQuestObjectivesEditor : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestToolObjectivesListView> ListView_Objectives;

};

