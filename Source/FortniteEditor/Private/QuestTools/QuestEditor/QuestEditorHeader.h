// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "QuestTools/QuestEditor/QuestEditorSubWidget.h"
#include "QuestEditorHeader.generated.h"

class UCommonTextBlock;
class UVerticalBox;

UCLASS(Abstract)
class UQuestEditorHeader : public UQuestEditorSubWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void CreateNewQuestAsset();

	UFUNCTION(BlueprintCallable)
	virtual void MakeNextInTheSeries();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestAssetName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_CurrentlyEditing;

};

