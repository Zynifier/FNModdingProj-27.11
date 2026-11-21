// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "QuestTools/EditorQuestToolUtilityWidget.h"
#include "QuestEditorSubWidget.generated.h"

UCLASS()
class UQuestEditorSubWidget : public UEditorQuestToolUtilityWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BaseStruct="/Script/FortniteEditor.QuestEditorCommonData"))
	FInstancedStruct InstancedCommonData;

	UPROPERTY(EditAnywhere, Category="QuestEditorSubWidget")
	bool bHideIfNoValidAsset;

	UPROPERTY(EditAnywhere, Category="QuestEditorSubWidget")
	bool bHideIfValidAsset;

};

