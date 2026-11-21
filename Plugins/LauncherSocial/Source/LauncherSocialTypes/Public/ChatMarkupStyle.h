// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateColor.h"
#include "Styling/SlateTypes.h"
#include "ChatMarkupStyle.generated.h"

USTRUCT()
struct FChatMarkupStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle MarkupButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FTextBlockStyle MarkupTextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush MarkupBackground;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor ButtonColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor ButtonHoverColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateColor TipColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush SeperatorBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float SeperatorThickness;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin MarkupPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ButtonPadding;

};

