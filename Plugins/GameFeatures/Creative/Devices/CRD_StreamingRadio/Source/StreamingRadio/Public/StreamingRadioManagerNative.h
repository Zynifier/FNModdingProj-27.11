// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StreamingRadioManagerNative.generated.h"

class UFortStreamMediaSource;
class UMediaPlayer;

UCLASS()
class STREAMINGRADIO_API AStreamingRadioManagerNative : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StreamingRadioManagerNative")
	TObjectPtr<UFortStreamMediaSource> StreamMediaSource;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="StreamingRadioManagerNative")
	TObjectPtr<UMediaPlayer> MediaPlayer;

};

