// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "ChatStyle.generated.h"

USTRUCT()
struct FChatStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FEditableTextBoxStyle ChatEntryTextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FEditableTextBoxStyle ChatDisplayTextStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FScrollBoxStyle ScrollBorderStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush MessageNotificationBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ChatEntryPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	float ChatEntryHeight;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateBrush ChatMenuBackgroundBrush;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendActionPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendActionHeaderPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin FriendActionStatusMargin;

};

