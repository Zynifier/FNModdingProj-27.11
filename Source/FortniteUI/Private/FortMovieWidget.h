// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MediaPlayerOptions.h"
#include "UObject/NoExportTypes.h"
#include "FortUserWidget.h"
#include "FortMovieWidget.generated.h"

class UMediaPlayer;
class UMediaSoundComponent;
class UMediaSource;
class UMediaTexture;
class USoundClass;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMediaWidgetMediaOpened);

UCLASS(BlueprintType, Blueprintable)
class UFortMediaInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fortnite UI", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fortnite UI", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UMediaSource> MediaSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Fortnite UI", meta=(ExposeOnSpawn="TRUE"))
	bool bVideoStreamed;

};

UCLASS(BlueprintType, meta=(Category="Fortnite UI", DisableNativeTick))
class UFortMovieWidget : public UFortUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Movie")
	void CleanupMediaPlayer();

	UFUNCTION(BlueprintPure, Category="Movie")
	UMediaPlayer* GetMediaPlayer() const;

	UFUNCTION(BlueprintPure, Category="Movie")
	UMediaSoundComponent* GetMediaSoundComponent() const;

	UFUNCTION(BlueprintPure, Category="Movie")
	UMediaTexture* GetMediaTexture() const;

	UFUNCTION(BlueprintPure, Category="Movie")
	bool HasPlayerForSource(UMediaSource* InMediaSource) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Movie")
	void MediaDimensionsUpdated(float NewWidth, float NewHeight);

	UFUNCTION(BlueprintCallable, Category="Movie")
	void RequestPlayMovie(bool bShouldRewind = true);

	UFUNCTION(BlueprintCallable, Category="Movie")
	void RequestStopMovie();

	UFUNCTION(BlueprintCallable, Category="Movie")
	bool SetMediaSource(UMediaPlayer* InMediaPlayer, UMediaSource* InMediaSource, const FMediaPlayerOptions& PlayerOptions, bool bPlayOnOpen, bool bLooping);

	UPROPERTY(BlueprintAssignable, Category="Movie")
	FOnMediaWidgetMediaOpened OnMediaOpened;

private:
	UPROPERTY(Transient)
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY(Transient)
	TObjectPtr<UMediaTexture> MediaTexture;

	UPROPERTY(EditAnywhere, Category="FortMovieWidget")
	bool bIncludeAudio;

	UPROPERTY(EditAnywhere, Category="FortMovieWidget")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

};

