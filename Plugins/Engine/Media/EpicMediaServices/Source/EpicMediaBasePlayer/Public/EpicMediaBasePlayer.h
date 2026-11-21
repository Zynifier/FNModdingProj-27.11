// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "MediaPlayerOptions.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "EpicStreamMediaSource.h"
#include "EpicMediaBasePlayer.generated.h"

class UEpicStreamMediaSource;
class UMediaPlayer;
class UMediaSoundComponent;
class UMediaTexture;
class USoundSubmixBase;
enum class EBaseMediaTerminalErrorReason : uint8;

UENUM()
enum class EBaseMediaDelayAction : uint8
{
	Open = 0,
	Stop = 1,
	Start = 2,
};

UENUM()
enum class EBaseMediaPlayerState : uint8
{
	None = 0,
	Released = 1,
	Stopped = 2,
	Started = 3,
	Opened = 4,
	Playing = 5,
	Error = 6,
};

UENUM()
enum class EBaseMediaTerminalErrorReason : uint8
{
	Unknown = 0,
	Source = 1,
	Player = 2,
	UCP = 3,
	OpenTimeout = 4,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBaseVideoOnEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBaseVideoOnTerminalError, EBaseMediaTerminalErrorReason, Reason);

USTRUCT()
struct FBaseMediaDelayConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UMediaTexture> MediaTexture;

};

UCLASS(BlueprintType, Blueprintable)
class EPICMEDIABASEPLAYER_API UEpicBaseStreamingVideo : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Player")
	void ClearSyncTimes();

	UFUNCTION(BlueprintCallable, Category="Player")
	bool GetLicensedAudio();

	UFUNCTION(BlueprintCallable, Category="Player")
	UMediaPlayer* GetMediaPlayer();

	UFUNCTION()
	virtual FMediaPlayerOptions GetMediaPlayerOptions();

	UFUNCTION(BlueprintCallable, Category="Player")
	UEpicStreamMediaSource* GetMediaSource();

	UFUNCTION(BlueprintCallable, Category="Player")
	UMediaSoundComponent* GetSoundComponent();

	/*
	 * This can be called to setup the various pieces for streaming video playback.
	 * GetMediaPlayer and GetMediaSource can then be called if access is needed to
	 * those classes for event binding, etc.
	 * InVideoTexture (optional) - Texture reference for presentation
	 * InMediaPlayer (optional) - MediaPlayer to use if already established
	 * InMediaSource (required) - EXTENDED EpicStreamMEdiaSource
	 * InCDNFailover (optional) - Enable/Disable CDN failover
	 * return (bool) - If successful.
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	virtual bool Init(UMediaTexture* InVideoTexture, UMediaPlayer* InMediaPlayer, UEpicStreamMediaSource* InMediaSource, bool InCDNFailover = true);

	UFUNCTION(BlueprintPure, Category="Player")
	bool IsSyncStartTimeSet() const;

	UFUNCTION(BlueprintCallable, Category="Player")
	virtual bool Open(FMediaPlayerOptions InMediaOptions);

	UFUNCTION(BlueprintCallable, Category="Player")
	virtual void Release();

	UFUNCTION(BlueprintCallable, Category="Player")
	void SetCreateAudioComponent(bool bInCreateAudioComponent);

	UFUNCTION(BlueprintCallable, Category="Player")
	void SetOpenTimeout(double InTimeoutTime);

	UFUNCTION(BlueprintCallable, Category="Player")
	void SetSoundSubmixes(UMediaSoundComponent* InSoundComponent, USoundSubmixBase* InDefault, USoundSubmixBase* InLicensed);

	UFUNCTION(BlueprintCallable, Category="Player")
	void SetSyncTimes(FDateTime InNowTime, FDateTime InStartTime, bool DynamicStart = false, float InOffset_s = 0.000000f, float InDelay_s = 0.000000f);

	/*
	 * Set actual size of representation of the video for streaming optimizations.
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void SetVideoSize(const int32 Width, const int32 Height);

	/*
	 * Call to start playback immediately.
	 * InVUID (required) - Content to play
	 * InVideoTexture (optional) - Texture reference to presentation
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void Start(const FString& InVUID, UMediaTexture* InVideoTexture);

	// Stop all playback and reset all pieces.

	UFUNCTION(BlueprintCallable, Category="Player")
	virtual void Stop(bool bRelease = true, bool bStopPlayer = true);

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnTerminalError VideoOnTerminalError;

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnEvent VideoOnSuccess;

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnEvent VideoOnClosed;

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnEvent VideoOnEndReached;

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnEvent VideoOnOpenTimeout;

	UPROPERTY(BlueprintAssignable)
	FBaseVideoOnEvent VideoOnResumed;

protected:
	UFUNCTION()
	void HandleMediaClosed();

	UFUNCTION()
	void HandleMediaEndReached();

	UFUNCTION()
	void HandleMediaOpened(const FString& OpenedUrl);

	UFUNCTION()
	void HandleMediaOpenedFailed(const FString& FailedUrl);

	UFUNCTION()
	virtual void HandleMediaResumed();

	UPROPERTY()
	TObjectPtr<UEpicStreamMediaSource> MediaSource;

	UPROPERTY()
	TObjectPtr<UMediaPlayer> MediaPlayer;

	UPROPERTY()
	FIntPoint VideoSize;

private:
	UFUNCTION()
	void HandleLicensedAudioTreatmentChanged(UCPTypes UCPType);

	UFUNCTION()
	void OnFailedURL(const FString& URL);

	UFUNCTION()
	void OnSuccessfulURL(const FString& URL);

	UFUNCTION()
	bool RetryOnError(bool bFromPlayer);

	UPROPERTY()
	TObjectPtr<USoundSubmixBase> DefaultSubmix;

	UPROPERTY()
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> MediaSoundComponent;

};

