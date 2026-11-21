// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "SubtitleDisplaySubsystem.h"
#include "SubtitleDisplay.generated.h"

class USubtitleDisplayOptions;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class SUBTITLESWIDGETS_API USubtitleDisplay : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Subtitles")
	bool HasSubtitles() const;

	UPROPERTY(EditAnywhere, Category="Display Info")
	FSubtitleFormat Format;

	UPROPERTY(EditAnywhere, Category="Display Info")
	TObjectPtr<USubtitleDisplayOptions> Options;

	UPROPERTY(EditAnywhere, Category="Display Info")
	float WrapTextAt;

	UPROPERTY(EditAnywhere, Category="Preview")
	bool bPreviewMode;

	UPROPERTY(EditAnywhere, Category="Preview")
	FText PreviewText;

private:
	UPROPERTY(Transient)
	FTextBlockStyle GeneratedStyle;

	UPROPERTY(Transient)
	FSlateBrush GeneratedBackgroundBorder;

};

