// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaSubtitlesPlayer.generated.h"

class UMediaPlayer;
class UOverlays;

UCLASS(BlueprintType)
class SUBTITLESWIDGETS_API UFortMediaSubtitlesPlayer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Fortnite Subtitles|Subtitles Player")
	void BindToMediaPlayer(UMediaPlayer* InMediaPlayer);

	UFUNCTION(BlueprintCallable, Category="Fortnite Subtitles|Subtitles Player")
	void Play();

	UFUNCTION(BlueprintCallable, Category="Fortnite Subtitles|Subtitles Player")
	void SetSubtitles(UOverlays* Subtitles);

	UFUNCTION(BlueprintCallable, Category="Fortnite Subtitles|Subtitles Player")
	void Stop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Subtitles Source")
	TObjectPtr<UOverlays> SourceSubtitles;

};

