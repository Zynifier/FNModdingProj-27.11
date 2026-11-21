// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortMediaStreamingRadio.generated.h"

class UFortMediaPlayerCtrl;
class UFortStreamMediaSource;
class UMediaPlayer;
class UMediaSoundComponent;

UCLASS(MinimalAPI)
class AFortMediaStreamingRadio : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Start(const int32 StationIndex);

	UFUNCTION(BlueprintCallable)
	void Stop();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortMediaStreamingRadio", meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortMediaStreamingRadio")
	TArray<FString> StationIDs;

private:
	UFUNCTION()
	void OnFailedURL(const FString& URL);

	UFUNCTION()
	void OnMediaClosed();

	UFUNCTION()
	void OnMediaOpened(const FString& String);

	UFUNCTION()
	void OnSuccessfulURL(const FString& URL);

	UPROPERTY()
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY()
	TObjectPtr<UFortMediaPlayerCtrl> MediaPlayerController;

	UPROPERTY()
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY(Replicated)
	float MediaStartTimeFromInit;

};

