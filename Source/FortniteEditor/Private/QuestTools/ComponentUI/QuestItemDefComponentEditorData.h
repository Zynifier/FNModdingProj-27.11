// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestItemDefComponentEditorData.generated.h"

class UFortQuestDefinitionComponent;
class UFortQuestItemDefComponentEditor;

USTRUCT(BlueprintType)
struct FQuestItemDefComponentEditorData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QuestItemDefComponentEditorData")
	TSubclassOf<UFortQuestDefinitionComponent> QuestItemDefComponentClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QuestItemDefComponentEditorData")
	TSubclassOf<UFortQuestItemDefComponentEditor> QuestItemDefComponentEditorClass;

};

USTRUCT(BlueprintType)
struct FQuestItemDefComponentEditorObjectives : public FQuestItemDefComponentEditorData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="QuestItemDefComponentEditorObjectives")
	FName ObjectiveBackEndName;

};

