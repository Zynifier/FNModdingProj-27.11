// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EpicMediaBasePlayer.h"
#include "FortBaseStreamingVideo.generated.h"

class UFortDownloadLocalizedOverlays;
class UFortMediaPlayerCtrl;
class UFortMediaSubtitlesPlayer;
class ULocalizedOverlays;

USTRUCT(BlueprintType)
struct FFortMediaInBandMetadata
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString LanguageCode;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Artist;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Genre;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Date;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString LongDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Album;

	UPROPERTY(BlueprintReadOnly, Category="FortMediaInBandMetadata")
	FString Encoder;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortMediaMetadataEvent, FFortMediaInBandMetadata, Metadata);

UCLASS(BlueprintType, Blueprintable)
class FORTNITEGAME_API UFortBaseStreamingVideo : public UEpicBaseStreamingVideo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFortMediaPlayerCtrl* GetMediaController();

	UFUNCTION(BlueprintCallable)
	FFortMediaInBandMetadata GetMediaMetadata();

	UFUNCTION(BlueprintCallable)
	UFortMediaSubtitlesPlayer* GetSubtitlePlayer();

	UFUNCTION(BlueprintCallable)
	void SetMediaControllerStartTime(const float InStartTime);

	UFUNCTION(BlueprintCallable)
	void SetSubtitles(ULocalizedOverlays* InOverlays, UFortMediaSubtitlesPlayer* InSubtitlePlayer);

	UPROPERTY(BlueprintAssignable)
	FFortMediaMetadataEvent MetadataChangedEvent;

protected:
	UPROPERTY()
	TObjectPtr<UFortMediaPlayerCtrl> MediaController;

private:
	UFUNCTION()
	void HandleMetadataEvent();

	UPROPERTY(Transient)
	UFortDownloadLocalizedOverlays* LocalizedOverlays;

	UPROPERTY(Transient)
	UFortMediaSubtitlesPlayer* SubtitlesPlayer;

};

