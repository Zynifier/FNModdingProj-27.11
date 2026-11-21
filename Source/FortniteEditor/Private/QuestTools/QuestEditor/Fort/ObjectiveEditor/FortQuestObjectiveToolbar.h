// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortQuestObjectiveToolbar.generated.h"

class UCommonTextBlock;
class UQuestEditorButton;

UCLASS(Abstract)
class UFortQuestObjectiveToolbar : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumObjectives;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UQuestEditorButton> Button_AddObjective;

};

