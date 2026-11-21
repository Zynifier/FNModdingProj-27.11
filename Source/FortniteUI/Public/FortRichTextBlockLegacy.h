// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Engine/DataTable.h"
#include "Framework/Text/TextLayout.h"
#include "Layout/Margin.h"
#include "Styling/SlateTypes.h"
#include "FortRichTextBlockLegacy.generated.h"

class UDataTable;
class UFortKeybindWidget;

USTRUCT()
struct FFortRichTextStyleData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FTextBlockStyle TextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	bool bHyperlinkStyle;

};

UCLASS(ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortRichTextBlockLegacy : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Widget")
	static FString EscapeStringForRichText(const FString& InString);

	UFUNCTION(BlueprintCallable, Category="Widget")
	void SetText(FText InText);

	UPROPERTY(EditAnywhere, Category="Content", meta=(MultiLine="true"))
	FText Text;

	UPROPERTY(EditAnywhere, Category="Appearance")
	TObjectPtr<UDataTable> StyleSet;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TextMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float WrapTextAt;

	UPROPERTY(EditAnywhere, Category="Appearance")
	bool AutoWrapText;

	UPROPERTY(EditAnywhere, Category="Appearance")
	TEnumAsByte<ETextJustify::Type> Justification;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle HyperlinkButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FScrollBarStyle ScrollBarStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	bool DisableTouchInput;

	UPROPERTY(EditInstanceOnly, Category="Appearance", meta=(DesignerRebuild="TRUE"))
	bool AllowContextMenu;

protected:
	UPROPERTY(Transient)
	FTextBlockStyle DefaultTextStyle;

private:
	UPROPERTY(EditAnywhere, Category="Appearance")
	TSubclassOf<UFortKeybindWidget> KeybindWidgetClass;

};

