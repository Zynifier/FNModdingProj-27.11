// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "ChatChromeColorScheme.generated.h"

USTRUCT()
struct FChatChromeColorScheme
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor ChatEntryBackgroundColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor NoneActiveTabColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor TabFontColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor TabFontColorInverted;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor ChatBackgroundColor;

};

