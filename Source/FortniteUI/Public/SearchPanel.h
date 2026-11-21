// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "SearchPanel.generated.h"

class UCommonButtonLegacy;
class UEditableTextBox;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSearchTextChangedEvent, const FText&, Text);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class USearchPanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Search|Event")
	FOnSearchTextChangedEvent OnSearchTextChanged;

	UPROPERTY(BlueprintReadOnly, Export, Category="SearchPanel", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditableText_Search;

private:
	UFUNCTION()
	void HandleOnSearchTextChanged(const FText& Text);

	UFUNCTION()
	void HandleSearchButtonClick();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_TextSearch;

};

