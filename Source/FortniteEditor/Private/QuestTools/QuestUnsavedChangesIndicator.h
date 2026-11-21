// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "QuestUnsavedChangesIndicator.generated.h"

class UImage;

UCLASS(Abstract)
class UQuestUnsavedChangesIndicator : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Indicator;

};

