// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortInputField.generated.h"

class UEditableText;

UCLASS()
class FORTNITEUI_API UFortInputField : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetEditableText(const FText& EditableText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetErrorText(const FText& ErrorText);

	UFUNCTION(BlueprintImplementableEvent)
	void SetHintText(const FText& HintText);

protected:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortInputField", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableTextWidget;

};

