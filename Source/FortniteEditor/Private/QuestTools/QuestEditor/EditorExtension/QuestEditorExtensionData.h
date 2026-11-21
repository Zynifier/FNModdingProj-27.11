// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestEditorExtensionData.generated.h"

class UQuestEditorBase;
class UQuestEditorSubWidget;

USTRUCT(BlueprintType)
struct FQuestEditorExtensionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Extension Panel Widget")
	FName SlotNameForExtension;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest Editor")
	TSoftClassPtr<UQuestEditorBase> QuestEditorSubclass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest Editor")
	TSoftClassPtr<UQuestEditorSubWidget> ExtensionWidget;

};

