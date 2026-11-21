// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "ChatChromeMargins.generated.h"

USTRUCT()
struct FChatChromeMargins
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	float TabWidth;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin TabPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ChatWindowPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ChatWindowToEntryMargin;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin ChatChannelPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin UserListButtonPadding;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FMargin UserListIconPadding;

};

