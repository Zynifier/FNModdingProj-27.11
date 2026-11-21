// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MediaPlayerOptions.h"
#include "Misc/DateTime.h"
#include "StreamMediaSource.h"
#include "EpicMediaMetadataTypes.h"
#include "EpicStreamMediaSource.generated.h"

class APlayerController;
class UEpicMediaCDNHostnames;
class UEpicMediaDownloadLocalizedOverlays;
class UEpicMediaMetadataResolver;
class UMediaSource;
class UObject;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum EStreamMediaContainerType
{
	CONTAINER_DASH = 0,
	CONTAINER_HLS = 1,
	CONTAINER_MP4 = 2,
	CONTAINER_UNKNOWN = 3,
};

UENUM(BlueprintType)
enum UCPTypes
{
	UCPAudio = 0,
	UCPVideo = 1,
	UCPBoth = 2,
	UCPNone = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMediaLicensedAudioTreatmentChanged, TEnumAsByte<UCPTypes>, UCPType);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMetaDataFailure, FString, MediaMetadataResponse);

/** Multicast delegate that is invoked when the video Url is ready for use. */
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRetrieveVideoUrlResult, FString, RetrievedUrl);

UCLASS(Abstract, BlueprintType, HideCategories=("Object", "Object"))
class EPICSTREAMMEDIASOURCE_API UEpicStreamMediaSource : public UStreamMediaSource
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Stream")
	void CancelVideoUrlRequest(bool bInCancelled);

	/**
	 * Clears URL Arguments made by SetSyncTimes
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void ClearSyncTimes();

	UFUNCTION(BlueprintCallable, Category="Player")
	virtual void DisableSharing();

	UFUNCTION(BlueprintCallable, Category="Player")
	void ForceSegmentCaching(bool bForce = false);

	//! check to see if there is a local fallback URL

	UFUNCTION(BlueprintPure, Category="Stream")
	bool HasLocalFilePlayback() const;

	/**
	 * Returns whether or not we could detect that screen recording (via OS provided means)
	 * is currently in progress. If it is playback of protected content may need to be suppressed.
	 *
	 * @return true if screen recording via system provided means is active, false if not.
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	bool IsScreenRecordingInProgress();

	UFUNCTION()
	void MetadataResultHandler(const FEpicMediaMetadataExt& Metadata, bool bSuccess);

	UFUNCTION(BlueprintCallable, Category="Player")
	virtual void ReinstateSharing();

	// Deprecated params, but maintain for now, less files touched in change.

	UFUNCTION(BlueprintCallable, Category="Stream")
	void RequestVideoUrl(const APlayerController* FortPC);

	/**
	 * New version of SetLocalizedOverlays that uses EpicMediaDownloadLocalizedOverlays
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void SetLocalizedOverlaysV2(UEpicMediaDownloadLocalizedOverlays* InOverlays);

	/**
	 * Set the start time offset in the media player options.
	 * 
	 * @param StartTime Offset in seconds from the start of the video stream.
	 */
	UFUNCTION(BlueprintCallable, Category="Stream")
	void SetPlaybackStartTime(float StartTime);

	/**
	 * Sets StreamURLArguments to synchronise the mediaplayer to a specified time.
	 *
	 * Note: Only DASH URLs will use these params. 
	 *
	 * @param InNowTime The timestamp of what the player should consider as 'now'. Sets the EpicUTCNow arg.
	 * @param InStartTime The timestamp of the start of playback
	 * @param DynamicStart sets EpicDynamicStart when true. EpicStaticStart when false.
	 * @param InOffset_s Adjustment for playback position in Seconds
	 * @param InDelay_s Used in EpicDynamicStart to have a delayed start. Useful for pre-buffering.
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void SetSyncTimes(FDateTime InNowTime, FDateTime InStartTime, bool DynamicStart = false, float InOffset_s = 0.000000f, float InDelay_s = 0.000000f);

	UFUNCTION(BlueprintCallable, Category="Stream")
	void SetUrl(UPARAM(ref) FString& InUrl);

	UFUNCTION(BlueprintPure, Category="Player")
	virtual UCPTypes ShouldProtectPlayerFromContent();

	/** 
	 * Query if the video stream should be playing.
	 * E.g. if the player camera is too far away then the stream should stop.
	*/
	UFUNCTION(BlueprintPure, Category="Stream", meta=(WorldContext="WorldContextObject"))
	bool ShouldStreamBePlaying(const UObject* WorldContextObject, const UPrimitiveComponent* PrimitiveComponent, float CullRadius) const;

	/**
	 * Update media player options with local settings (e.g. start time offset).
	 *
	 * @param PlayerOptions options to be updated with local settings.
	 * @return The updated media player options.
	 */
	UFUNCTION(BlueprintPure, Category="Stream")
	FMediaPlayerOptions UpdatePlayerOptions(FMediaPlayerOptions PlayerOptions) const;

	/**
	 * Actually builds the arguments for the Stream URL augmenting for time since SetSyncTimes was called.
	 * This should be called RIGHT before UMediaPlayer::Open... is called
	 */
	UFUNCTION(BlueprintCallable, Category="Player")
	void UpdateStreamUrlArguments();

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	FString VideoStreamSource;

	//default

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	float VideoStreamSourceAB;

	/** The Id for the video to get the URL's for from Links service. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	TMap<FString, FString> VideoId;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	bool bIsLive;

	UPROPERTY(BlueprintReadWrite, Category="Stream")
	bool bBlurlLive;

	/** The max resolution the video can adapt to if not zero. */
	UPROPERTY(EditAnywhere, Category="Stream")
	int32 MaxResolution;

	/** The max bandwidth the video can adapt to if not zero. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	int32 MaxBandwidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	float AspectRatio;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	bool bShareLock;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	bool bAudioOnly;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	bool bPartySync;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	float MediaDuration;

	UPROPERTY(BlueprintReadWrite, Category="Stream")
	FString MimeType;

	UPROPERTY(BlueprintReadOnly, Category="Stream")
	FString StreamDenyHTTPCode;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UEpicMediaMetadataResolver> MetadataResolver;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Stream")
	TObjectPtr<UEpicMediaCDNHostnames> CDNHostNames;

	UPROPERTY(BlueprintReadWrite, Category="Stream")
	bool bEnableBLURLRetries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Scrubbing (EditorOnly)")
	bool bEnableScrubOptimization;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Scrubbing (EditorOnly)")
	int32 SeekBitrate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Scrubbing (EditorOnly)", meta=(EditCondition="TimeToCacheMilliseconds == 0"))
	int32 CacheSizeKiB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Scrubbing (EditorOnly)")
	int32 TimeToCacheMilliseconds;

	/**
	 * A delegate that is invoked when a call to RequestVideoUrl was successful.
	 */
	UPROPERTY(BlueprintAssignable, Category="Stream")
	FOnRetrieveVideoUrlResult OnVideoUrlSuccess;

	/**
	 * A delegate that is invoked when a call to RequestVideoUrl failed.
	 */
	UPROPERTY(BlueprintAssignable, Category="Stream")
	FOnRetrieveVideoUrlResult OnVideoUrlFailed;

	UPROPERTY(BlueprintAssignable, Category="Stream")
	FMetaDataFailure OnMetaDataFailure;

	UPROPERTY(BlueprintAssignable)
	FMediaLicensedAudioTreatmentChanged OnMediaLicensedAudioTreatmentChanged;

	/**
	 * An optional direct link to the localized overlays (subtitles). This
	 * allows the URL of a download able subtitles file to be pass through.
	 */
	UPROPERTY(EditDefaultsOnly, Category="Player")
	TObjectPtr<UEpicMediaDownloadLocalizedOverlays> EpicMediaDownloadLocalizedOverlays;

	UPROPERTY(BlueprintReadOnly, Category="Player")
	FString ProtectUserFromAVSettings;

	/**
	 * The ID of a video stream resource to be played back.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	FString StreamID;

	/**
	 * The ID of a video stream resource to be played back (Development override).
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	FString StreamID_Development;

	/**
	 * The resource to use when local fallback hotfix is set.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, AssetRegistrySearchable, Category="Stream")
	TObjectPtr<UMediaSource> LocalFilePlaybackAsset;

	UPROPERTY(BlueprintReadOnly, Category="Player")
	double HighestFramerate;

};

