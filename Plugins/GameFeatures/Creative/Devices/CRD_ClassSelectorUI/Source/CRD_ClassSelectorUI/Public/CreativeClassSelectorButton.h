// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Engine/DataTable.h"
#include "CreativeClassSelectorButton.generated.h"

class UCommonActionWidget;
class UCommonTextBlock;

UCLASS(Abstract)
class UCreativeClassSelectorButton : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetButtonText(const FText& InText);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelectorButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ButtonTextBlock;

	UPROPERTY(BlueprintReadOnly, Export, Category="CreativeClassSelectorButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActionWidget> ActionWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeClassSelectorButton")
	FText ButtonText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeClassSelectorButton")
	FDataTableRowHandle ButtonInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeClassSelectorButton")
	bool bAutoCapitalize;

};

