// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorHeader.h"
#include "FortQuestEditorHeader.generated.h"

class UDataTable;

UCLASS(Abstract)
class UFortQuestEditorHeader : public UQuestEditorHeader
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void OpenObjectiveDebugger();

	UPROPERTY(EditDefaultsOnly, Category="FortQuestEditorHeader")
	TSoftObjectPtr<UDataTable> TemplateDataTable;

};

