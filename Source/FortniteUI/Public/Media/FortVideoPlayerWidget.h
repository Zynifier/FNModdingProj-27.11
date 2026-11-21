// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserWidget.h"
#include "FortVideoPlayerWidget.generated.h"

class UFortMediaPlayerCtrl;
class UFortMediaSubtitlesPlayer;
class UImage;
class UMaterialInterface;
class UMediaPlayer;
class UMediaSoundComponent;
class USoundClass;
class USoundSubmixBase;
class USubtitleDisplay;

UCLASS(MinimalAPI)
class UFortVideoPlayerWidget : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UMediaPlayer* GetMediaPlayer() const;

	UFUNCTION(BlueprintCallable)
	void SetMediaMaterial(UMaterialInterface* VideoMaterial);

	UFUNCTION(BlueprintCallable)
	void SetSoundClass(USoundClass* InSoundClass);

	UFUNCTION(BlueprintCallable)
	void SetupMediaController(float MediaStartTime);

private:
	UFUNCTION()
	void DynamicHandleOnMediaOpened(const FString& OpenedURL);

	UFUNCTION()
	void DynamicHandleOnOpenMediaFailed(const FString& FailedURL);

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	bool bAutoPlayOnOpen;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	bool bLoop;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	bool bShowSubtitles;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	bool bNoAudio;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	bool bForceDefaultAudio;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	TObjectPtr<UMediaPlayer> VideoPlayer;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	TObjectPtr<USoundSubmixBase> DefaultAudioSubmix;

	UPROPERTY(EditAnywhere, Category="FortVideoPlayerWidget")
	TObjectPtr<USoundSubmixBase> LicensedAudioSubmix;

	UPROPERTY(Transient)
	TObjectPtr<UFortMediaPlayerCtrl> MediaController;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY(Transient)
	TObjectPtr<UFortMediaSubtitlesPlayer> SubtitlePlayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_VideoTexture;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USubtitleDisplay> Subtitles;

};

