// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestItemDefComponentEditorRow.generated.h"

class UFortQuestItemDefComponentEditor;

USTRUCT()
struct FQuestItemDefComponentEditorRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QuestItemDefComponentEditorRow")
	bool bDisableEditor;

	UPROPERTY(EditDefaultsOnly, Category="QuestItemDefComponentEditorRow")
	TSoftClassPtr<UFortQuestItemDefComponentEditor> EditorClass;

	UPROPERTY(EditDefaultsOnly, Category="QuestItemDefComponentEditorRow")
	TSoftClassPtr<UFortQuestItemDefComponentEditor> EditorObjectiveExtensionClass;

};

