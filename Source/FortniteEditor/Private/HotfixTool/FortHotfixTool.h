// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorUtilityWidget.h"
#include "FortHotfixTool.generated.h"

class UEditableTextBox;
class UHorizontalBox;
class UVerticalBox;

UCLASS()
class UFortHotfixTool : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CopyHotfixToClipboard() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void GenerateHotfixFile() const;

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortHotfixTool", meta=(BindWidget, EditInline="true"))
	UVerticalBox* VerticalBox_HotfixEntries;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortHotfixTool", meta=(BindWidget, EditInline="true"))
	UHorizontalBox* HorizontalBox_HotfixFilePath;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHotfixTool", meta=(BindWidget, EditInline="true"))
	UEditableTextBox* EditableTextBox_FilePath;

};

