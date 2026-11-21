// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MediaPlayerOptions.h"
#include "Misc/Timespan.h"
#include "UObject/NoExportTypes.h"
#include "FortMediaPlayerCtrl.generated.h"

class UFortStreamMediaSource;
class UMediaPlayer;
class UMediaSource;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Object"))
class UFortMediaPlayerCtrl : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Media|MediaPlayer")
	FORTNITEGAME_API void Close();

	UFUNCTION(BlueprintPure, Category="Media|MediaPlayer")
	FORTNITEGAME_API bool GetPlayerStateIsPreparing() const;

	UFUNCTION(BlueprintCallable, Category="Media|MediaPlayer")
	FORTNITEGAME_API bool OpenSourceWithOptions(UMediaSource* InMediaSource, const FMediaPlayerOptions& InOptions);

	UFUNCTION(BlueprintCallable, Category="Media|MediaPlayer")
	FORTNITEGAME_API bool Play();

	UFUNCTION(BlueprintCallable, Category="Media|MediaPlayer")
	FORTNITEGAME_API virtual void SetPlayerStartTime(double InRequestSentTime);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float InitialBufferDurationInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	float SegmentBufferDurationInSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	FTimespan MaxSyncedOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Settings", meta=(ClampMax="100.0", ClampMin="1.0", UIMax="100.0", UIMin="1.0"))
	float ServerTimeOffsetSmoothingFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Settings")
	uint8 MaxConsecutiveDesyncedFrames;

private:
	UPROPERTY()
	TObjectPtr<UMediaSource> CachedMediaSource;

};

