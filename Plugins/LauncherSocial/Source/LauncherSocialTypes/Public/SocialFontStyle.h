// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "SocialFontStyle.generated.h"

USTRUCT()
struct FSocialFontStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontSmall;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontSmallBold;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontNormal;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontNormalBold;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontLarge;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FSlateFontInfo FontLargeBold;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor DefaultFontColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor InvertedFontColor;

	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor DefaultDullFontColor;

};

