// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AmbientAudioTypes.h"
#include "AmbientAudioDataAsset.generated.h"

/**
 *	A collection of audio data representing one ambient zone
 */
UCLASS(BlueprintType)
class AMBIENTAUDIO_API UAmbientAudioDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Ambient Loop Data")
	TArray<FAmbientAudioLoop> LoopingSounds;

	UPROPERTY(EditDefaultsOnly, Category="Ambient One-shot Data")
	TArray<FAmbientAudioOneShot> OneShotSounds;

	UPROPERTY(EditAnywhere, Category="Ambient Audio")
	float TagCrossfadeTime;

};

