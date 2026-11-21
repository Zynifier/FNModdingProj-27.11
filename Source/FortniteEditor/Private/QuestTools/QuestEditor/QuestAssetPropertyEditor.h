// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "QuestAssetPropertyEditor.generated.h"

class UCustomPropertyView;

UCLASS(Abstract)
class UQuestAssetPropertyEditor : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="QuestAssetPropertyEditor", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCustomPropertyView> PropertyView_QuestAsset;

};

