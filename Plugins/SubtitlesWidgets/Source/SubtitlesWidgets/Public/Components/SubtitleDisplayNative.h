// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Styling/SlateTypes.h"
#include "UObject/NoExportTypes.h"
#include "SubtitleDisplayNative.generated.h"

class USubtitleDisplayOptions;

UCLASS()
class SUBTITLESWIDGETS_API USubtitleDisplayNative : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<USubtitleDisplayOptions> Options;

private:
	UPROPERTY(Transient)
	FTextBlockStyle GeneratedStyle;

	UPROPERTY(Transient)
	FSlateBrush GeneratedBackgroundBorder;

};

