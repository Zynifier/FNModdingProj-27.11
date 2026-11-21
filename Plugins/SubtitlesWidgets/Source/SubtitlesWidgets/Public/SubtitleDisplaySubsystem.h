// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SubtitleDisplayOptions.h"
#include "SubtitleDisplaySubsystem.generated.h"

USTRUCT(BlueprintType)
struct SUBTITLESWIDGETS_API FSubtitleFormat
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Display Info")
	ESubtitleDisplayTextSize SubtitleTextSize;

	UPROPERTY(EditAnywhere, Category="Display Info")
	ESubtitleDisplayTextColor SubtitleTextColor;

	UPROPERTY(EditAnywhere, Category="Display Info")
	ESubtitleDisplayTextBorder SubtitleTextBorder;

	UPROPERTY(EditAnywhere, Category="Display Info")
	ESubtitleDisplayBackgroundOpacity SubtitleBackgroundOpacity;

};

UCLASS(meta=(DisplayName="Subtitle Display"))
class SUBTITLESWIDGETS_API USubtitleDisplaySubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FSubtitleFormat SubtitleFormat;

};

