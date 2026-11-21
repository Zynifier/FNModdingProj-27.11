// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortLoadingVideoPlayer.generated.h"

class UFileMediaSource;
class UFortStreamMediaSource;
class UMediaPlayer;
class UMediaSoundComponent;
class UMediaTexture;

UCLASS()
class UFortLoadingVideoPlayer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	UMediaPlayer* GetMediaPlayer();

	UFUNCTION()
	UMediaTexture* GetMediaTexture();

private:
	UFUNCTION()
	void RequestFailure(const FString& Url);

	UFUNCTION()
	void RequestSuccess(const FString& Url);

	UPROPERTY()
	TObjectPtr<UMediaPlayer> VideoPlayer;

	UPROPERTY()
	TObjectPtr<UMediaTexture> VideoTexture;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY()
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY()
	TObjectPtr<UFileMediaSource> FileMediaSource;

};

