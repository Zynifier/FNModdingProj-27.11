// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateTypes.h"
#include "ChatChromeColorScheme.h"
#include "ChatChromeMargins.h"
#include "ChatChromeStyle.h"
#include "ChatColorScheme.h"
#include "ChatMarkupStyle.h"
#include "ChatStyle.h"
#include "SocialFontStyle.h"
#include "SocialListMargins.h"
#include "SocialListStyle.h"
#include "SocialSoundSchema.h"
#include "SocialStyle.generated.h"

USTRUCT()
struct FSocialStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FScrollBarStyle ScrollBarStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FButtonStyle ActionButtonStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialFontStyle SmallFontStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialFontStyle NormalFontStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialFontStyle LargeFontStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialFontStyle ChatFontStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FCheckBoxStyle CheckBoxStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FCheckBoxStyle RadioBoxStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialListStyle SocialListStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialListMargins SocialListMargins;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatStyle ChatStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatColorScheme ChatColorScheme;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatChromeStyle ChatChromeStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatChromeMargins ChatChromeMargins;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatChromeColorScheme ChatChromeColorScheme;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FChatMarkupStyle ChatMarkupStyle;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSocialSoundSchema SoundSchema;

};

