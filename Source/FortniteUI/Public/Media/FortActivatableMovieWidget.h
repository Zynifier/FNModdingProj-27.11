// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "CheckDismissableActivatableWidget.h"
#include "Media/VideoWidgetConfig.h"
#include "FortActivatableMovieWidget.generated.h"

class UBorder;
class UCommonButtonBase;
class UFortBaseStreamingVideo;
class UFortMediaPlayerCtrl;
class UFortMediaSubtitlesPlayer;
class UImage;
class ULocalizedOverlays;
class UMediaPlayer;
class UMediaSoundComponent;
class USoundClass;
class USoundMix;
class USoundSubmixBase;
class USubtitleDisplay;
enum class EBaseMediaTerminalErrorReason : uint8;
enum class UFortActivatablePrePostRollStates : uint8;

UENUM(BlueprintType)
enum class UFortActivatablePrePostRollStates : uint8
{
	None = 0,
	PreRoll = 1,
	PreRollComplete = 2,
	PostRoll = 3,
	PostRollComplete = 4,
	BeginningStepOne = 5,
	BeginningStepTwo = 6,
	Middle = 7,
	End = 8,
};

UENUM()
enum class UFortActivatableVideoEvents : uint8
{
	Finished = 0,
	Skipped = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMovieWidgetMediaEnded);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMovieWidgetMediaErrorBP, FString, StreamedVideoError);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMovieWidgetMediaPreEnd);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMovieWidgetMediaStarted);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMovieWidgetVolumeChange, const double&, StreamVolumeChange);

UCLASS(BlueprintType, Blueprintable)
class FORTNITEUI_API UFortActivatableMovieWidget : public UCommonActivatableWidget, public ICheckDismissableActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Close();

	UFUNCTION(BlueprintCallable)
	void EnableFadeInFromColor(bool bInEnable);

	UFUNCTION(BlueprintCallable)
	void FadeInFromColorComplete(UFortActivatablePrePostRollStates Reason);

	UFUNCTION(BlueprintPure)
	UFortBaseStreamingVideo* GetBaseStreamingVideo();

	UFUNCTION(BlueprintPure)
	UMediaPlayer* GetMediaPlayer() const;

	UFUNCTION(BlueprintCallable)
	const UImage* GetVideoTexture();

	UFUNCTION(BlueprintCallable)
	void LoadStreamingVideo(const FVideoWidgetConfig& Config);

	UFUNCTION(BlueprintCallable)
	void Play();

	UFUNCTION(BlueprintCallable)
	void SetFadeTime(double InFadeTime);

	UFUNCTION(BlueprintCallable)
	void SetMediaPreEndTimeSeconds(float InSeconds);

	UFUNCTION(BlueprintPure)
	bool ShouldAutoPlayVideo(FName AssetName, bool bAllowRecord = false) const;

	UFUNCTION(BlueprintImplementableEvent)
	void StartFadeFromColor(bool bEnd, UFortActivatablePrePostRollStates Reason, bool bReverse);

	UFUNCTION(BlueprintImplementableEvent)
	void StartWholeFade(bool bReverse);

	UFUNCTION(BlueprintCallable)
	void Stop(bool InForceClose = false);

	UFUNCTION(BlueprintCallable)
	void WholeFadeComplete();

	UPROPERTY(BlueprintReadWrite, Category="FortActivatableMovieWidget")
	bool bOverwriteSkip;

	UPROPERTY(BlueprintAssignable)
	FMovieWidgetMediaErrorBP OnMediaError;

	UPROPERTY(BlueprintReadOnly, Category="FortActivatableMovieWidget")
	bool bMediaPreEndCheckEnabled;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortActivatableMovieWidget")
	FVideoWidgetConfig VideoConfig;

private:
	UFUNCTION()
	void HandleVideoStreamingSuccess();

	UFUNCTION()
	void HandleVideoStreamingTerminalError(EBaseMediaTerminalErrorReason Reason);

	UFUNCTION()
	void StreamedVideoOnMediaPlayerClosed();

	UFUNCTION()
	void StreamedVideoOnMediaPlayerEndReached();

	UFUNCTION()
	void StreamedVideoOpeningTimeout();

	UPROPERTY(BlueprintReadWrite, Category="FortActivatableMovieWidget", meta=(AllowPrivateAccess, BindWidgetOptional))
	bool bInWholeFade;

	UPROPERTY(BlueprintReadWrite, Category="FortActivatableMovieWidget", meta=(AllowPrivateAccess, BindWidgetOptional))
	bool bInColorFade;

	UPROPERTY(EditDefaultsOnly, Category="FortActivatableMovieWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PressToSkipAction;

	UPROPERTY(EditDefaultsOnly, Category="FortActivatableMovieWidget", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle HoldToSkipAction;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortActivatableMovieWidget", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Color;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	bool bAutoBroadcastRebuild;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	bool bShowSubtitles;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	bool bNoAudio;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	bool bEnableInputControl;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<UMediaPlayer> VideoPlayer;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<UFortMediaSubtitlesPlayer> SubtitlePlayer;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<ULocalizedOverlays> SubtitleOverlays;

	UPROPERTY(Transient)
	float LastInteractionTime;

	UPROPERTY(Transient)
	bool bControlsVisible;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_VideoTexture;

	UPROPERTY()
	FLinearColor VideoTextureColor;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<USubtitleDisplay> Subtitles;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Skip;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Throbber;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> SafeZonePadding;

	UPROPERTY()
	FLinearColor SafeZoneColor;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<USoundMix> ActiveSoundMix;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<USoundSubmixBase> DefaultSubmix;

	UPROPERTY(EditAnywhere, Category="FortActivatableMovieWidget")
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

	UPROPERTY(Transient)
	TObjectPtr<UFortMediaPlayerCtrl> MediaController;

	UPROPERTY(Transient)
	TObjectPtr<UFortBaseStreamingVideo> BaseStreamingVideo;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FMovieWidgetMediaPreEnd MediaPreEndEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FMovieWidgetVolumeChange MediaVolumeChangeEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FMovieWidgetMediaStarted MediaStartedEvent;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FMovieWidgetMediaEnded WidgetEndReachedEvent;

};

