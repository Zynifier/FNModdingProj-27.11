// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MediaPlayerOptions.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "PictureInPicturePartnerData.h"
#include "PictureInPicturePartnerSource.h"
#include "PictureInPictureMediaController.generated.h"

class UCommonLazyImage;
class UPictureInPictureActionData;
class UPictureInPictureAnalyticsManager;
class UPictureInPicturePlayer;
class UTexture2DDynamic;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFullScreenToggled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureBaseEnabled, bool, IsEnabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPictureInPictureBaseError, int32, ErrorType, FString, ErrorMessage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureSourceSelected, const FPiPPartnerSource&, Source);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureSourceUpdated, const TArray<FPiPPartnerSource>&, Sources);

USTRUCT()
struct FPiPSuspendInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPiPPartnerSource SourceSnapshot;

	UPROPERTY()
	bool bEnabledState;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class PICTUREINPICTURECORE_API UPictureInPictureMediaController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void Exit(bool bStop = true);

	UFUNCTION(BlueprintCallable)
	const TArray<UPictureInPictureActionData*>& GetActions();

	UFUNCTION(BlueprintCallable)
	virtual FPiPPartnerSource GetCurrentSource();

	UFUNCTION()
	const FPIPVideoPlayerAssetConfig& GetDefaultPlayerAssetConfig() const;

	UFUNCTION()
	UPictureInPicturePlayer* GetMediaPlayerWidget() const;

	UFUNCTION(BlueprintPure)
	const FPIPVideoPlayerAssetConfig& GetPlayerAssetConfig() const;

	UFUNCTION(BlueprintCallable)
	virtual TArray<FPiPPartnerSource> GetSources();

	UFUNCTION(BlueprintCallable)
	virtual TArray<FPiPPartnerSource> GetValidSources();

	UFUNCTION(BlueprintPure)
	bool IsEnabled() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsMultiSourceSupported();

	UFUNCTION(BlueprintCallable)
	bool IsPaused();

	UFUNCTION(BlueprintCallable)
	bool IsPlaying();

	UFUNCTION(BlueprintCallable)
	virtual void Pause();

	UFUNCTION(BlueprintCallable)
	virtual void Play(bool bForcePlay = true);

	UFUNCTION(BlueprintCallable)
	virtual void SetCurrentSource(const FPiPPartnerSource& SelectedSource);

	UFUNCTION(BlueprintCallable)
	virtual void SetEnabled(bool bIsEnabled, bool bIsFromUser);

	UFUNCTION(BlueprintCallable)
	virtual void Stop();

	UFUNCTION()
	void ToggleFullScreen();

	UPROPERTY()
	FString PartnerName;

protected:
	UFUNCTION()
	virtual void HandleSourceSelectedEvent(const FString& SelectedSource);

	UPROPERTY()
	TArray<TObjectPtr<UPictureInPictureActionData>> ActionDataArray;

	UPROPERTY()
	FPIPVideoPlayerAssetConfig DefaultPlayerAssetConfig;

	UPROPERTY()
	FPIPVideoPlayerAssetConfig PlayerAssetConfig;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPictureMediaController")
	TObjectPtr<UPictureInPicturePlayer> VideoWidget;

	UPROPERTY()
	FPIPVideoPlayerConfig VideoWidgetConfig;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="PictureInPictureMediaController")
	TWeakObjectPtr<UCommonLazyImage> ThumbnailImageNext;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="PictureInPictureMediaController")
	TWeakObjectPtr<UCommonLazyImage> ThumbnailImagePrevious;

	UPROPERTY(Transient)
	bool bSupportsMultipleSources;

	UPROPERTY()
	FPiPPartnerSource CurrentSource;

	UPROPERTY()
	TArray<FPiPPartnerSource> Sources;

	UPROPERTY()
	TArray<FPiPPartnerSource> ValidSources;

	UPROPERTY(EditAnywhere, Category="PictureInPictureMediaController")
	FMediaPlayerOptions LocalOptions;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureBaseError BaseErrorEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureBaseEnabled BaseEnabledEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureSourceUpdated SourcesChangedEvent;

	UPROPERTY(BlueprintAssignable)
	FPictureInPictureSourceSelected SourceSelectedEvent;

	UPROPERTY()
	TArray<FPictureInPictureActionConfig> InstanceActionData;

	UPROPERTY()
	TObjectPtr<UPictureInPictureAnalyticsManager> AnalyticsManager;

	UPROPERTY()
	FDateTime ActiveStartTime;

	UPROPERTY()
	FDateTime PausedStartTime;

	UPROPERTY()
	FPiPSuspendInfo SuspendedInfo;

private:
	UFUNCTION()
	void OnMediaClosedAnalytics();

	UFUNCTION()
	void OnMediaPausedAnalytics();

	UFUNCTION()
	void OnMediaResumedAnalytics();

	UFUNCTION()
	void OnMediaStartedAnalytics();

	UFUNCTION()
	void OnNextThumbnailReceived(UTexture2DDynamic* InTexture);

	UFUNCTION()
	void OnPrevThumbnailReceived(UTexture2DDynamic* InTexture);

};

