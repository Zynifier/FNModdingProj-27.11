// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Fonts/SlateFontInfo.h"
#include "Math/Color.h"
#include "Styling/SlateBrush.h"
#include "SubtitleDisplayOptions.generated.h"

UENUM()
enum class ESubtitleDisplayBackgroundOpacity : uint8
{
	Clear = 0,
	Low = 1,
	Medium = 2,
	High = 3,
	Solid = 4,
	ESubtitleDisplayBackgroundOpacity_MAX = 5,
};

UENUM()
enum class ESubtitleDisplayTextBorder : uint8
{
	None = 0,
	Outline = 1,
	DropShadow = 2,
	ESubtitleDisplayTextBorder_MAX = 3,
};

UENUM()
enum class ESubtitleDisplayTextColor : uint8
{
	White = 0,
	Yellow = 1,
	ESubtitleDisplayTextColor_MAX = 2,
};

UENUM()
enum class ESubtitleDisplayTextSize : uint8
{
	ExtraSmall = 0,
	Small = 1,
	Medium = 2,
	Large = 3,
	ExtraLarge = 4,
	ESubtitleDisplayTextSize_MAX = 5,
};

UCLASS(BlueprintType)
class SUBTITLESWIDGETS_API USubtitleDisplayOptions : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	FSlateFontInfo Font;

	UPROPERTY(EditDefaultsOnly, Category="Display Info", meta=(ArraySizeEnum="/Script/SubtitlesWidgets.ESubtitleDisplayTextSize"))
	int32 DisplayTextSizes[5];

	UPROPERTY(EditDefaultsOnly, Category="Display Info", meta=(ArraySizeEnum="/Script/SubtitlesWidgets.ESubtitleDisplayTextColor"))
	FLinearColor DisplayTextColors[2];

	UPROPERTY(EditDefaultsOnly, Category="Display Info", meta=(ArraySizeEnum="/Script/SubtitlesWidgets.ESubtitleDisplayTextBorder"))
	float DisplayBorderSize[3];

	UPROPERTY(EditDefaultsOnly, Category="Display Info", meta=(ArraySizeEnum="/Script/SubtitlesWidgets.ESubtitleDisplayBackgroundOpacity"))
	float DisplayBackgroundOpacity[5];

	UPROPERTY(EditDefaultsOnly, Category="Display Info")
	FSlateBrush BackgroundBrush;

};

