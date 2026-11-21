// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "ChatChromeStyle.generated.h"

USTRUCT()
struct FChatChromeStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush UserListBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ChatBackgroundBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ChatEntryBackgroundBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ChannelBackgroundBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush TabBackgroundBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle TabSelectorButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TabOptionPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TabContentPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TabClosePadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle UserListButtonStyle;

};

