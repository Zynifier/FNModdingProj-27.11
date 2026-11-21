// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Fonts/SlateFontInfo.h"
#include "Layout/Margin.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "Types/SlateEnums.h"
#include "SearchableStringComboBox.generated.h"

UCLASS(meta=(DisplayName="SearchableComboBox (String)"))
class FORTNITEEDITOR_API USearchableStringComboBox : public UWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpeningEvent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSelectionChangedEvent, FString, SelectedItem, TEnumAsByte<ESelectInfo::Type>, SelectionType);

public:
	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void AddOption(const FString& Option);

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void ClearOptions();

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void ClearSelection();

	UFUNCTION(BlueprintPure, Category="ComboBox")
	int32 FindOptionIndex(const FString& Option) const;

	UFUNCTION(BlueprintPure, Category="ComboBox")
	FString GetOptionAtIndex(const int32 Index) const;

	UFUNCTION(BlueprintPure, Category="ComboBox")
	int32 GetOptionCount() const;

	UFUNCTION(BlueprintPure, Category="ComboBox")
	int32 GetSelectedIndex() const;

	UFUNCTION(BlueprintPure, Category="ComboBox")
	FString GetSelectedOption() const;

	UFUNCTION(BlueprintPure, Category="ComboBox", meta=(ReturnDisplayName="bOpen"))
	bool IsOpen() const;

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void RefreshOptions();

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	bool RemoveOption(const FString& Option);

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void SetSelectedIndex(const int32 Index);

	UFUNCTION(BlueprintCallable, Category="ComboBox")
	void SetSelectedOption(const FString& Option);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style", meta=(DisplayName="Style"))
	FComboBoxStyle WidgetStyle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	FTableRowStyle ItemStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Content")
	FMargin ContentPadding;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Content")
	float MaxListHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Content")
	bool HasDownArrow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Category="Content")
	bool EnableGamepadNavigationMode;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Style")
	FSlateFontInfo Font;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Style", meta=(DesignerRebuild))
	FSlateColor ForegroundColor;

	UPROPERTY(EditAnywhere, Category="Events", meta=(IsBindableEvent="True"))
	UWidget::FGenerateWidgetForString OnGenerateWidgetEvent;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnSelectionChangedEvent OnSelectionChanged;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FOnOpeningEvent OnOpening;

private:
	UPROPERTY(EditAnywhere, Category="Content")
	TArray<FString> DefaultOptions;

	UPROPERTY(EditAnywhere, Category="Content")
	FString SelectedOption;

};

