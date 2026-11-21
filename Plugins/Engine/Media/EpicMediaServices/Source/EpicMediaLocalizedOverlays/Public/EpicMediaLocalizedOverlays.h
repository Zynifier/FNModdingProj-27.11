// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LocalizedOverlays.h"
#include "EpicMediaLocalizedOverlays.generated.h"

class UMediaPlayer;

UCLASS(HideCategories=("Object"))
class EPICMEDIALOCALIZEDOVERLAYS_API UEpicMediaDownloadLocalizedOverlays : public ULocalizedOverlays
{
	GENERATED_BODY()

public:
	/**
	 * An direct link to the Media Player which will be used to display the
	 * subtitles. This allows analytics to be sent.
	 */
	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UMediaPlayer> MediaPlayer;

};

