// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "FortWeeklyQuestNumEditorWidget.generated.h"

class UEditableText;

UCLASS(Abstract)
class UFortWeeklyQuestNumEditorWidget : public UQuestEditorSubWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void HandleWeekNumChanged();

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortWeeklyQuestNumEditorWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> Text_WeekNum;

};

