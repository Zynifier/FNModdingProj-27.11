// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortActivatableVideoPanel.generated.h"

class UCommonButtonBase;
class UFortVideoPlayerWidget;
class UImage;
class UMediaPlayer;
class USoundMix;
class UStreamMediaSource;

UENUM()
enum class UFortActivatableVideoPanelEvents : uint8
{
	Finished = 0,
	Skipped = 1,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMediaOpenFailed, FString, OpenedURL);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMediaOpened, FString, OpenedURL);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMediaPlayerEndReached);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPanelDismissed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSkipButtonClicked);

UCLASS(Abstract)
class UFortActivatableVideoPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EnableSkipButton(bool bAllowSkip);

	UFUNCTION(BlueprintPure)
	UMediaPlayer* GetMediaPlayer() const;

	UFUNCTION(BlueprintCallable)
	bool LoadVideo(FName VideoID, bool bIsAutoPlay = false, bool bForceDefaultAudioTrack = false, FName VideoString = FName(TEXT("")));

	UFUNCTION(BlueprintPure)
	bool ShouldAutoPlayVideo(FName AssetName, bool bAllowRecord = false) const;

	UFUNCTION(BlueprintCallable)
	void ShowThrobber();

	UFUNCTION(BlueprintCallable)
	void StartVideo();

	UFUNCTION(BlueprintCallable)
	bool StreamVideo(const FString& VideoURL);

	UFUNCTION(BlueprintCallable)
	bool StreamVideoFromSource(UStreamMediaSource* StreamSource);

	UPROPERTY(BlueprintAssignable)
	FOnSkipButtonClicked OnSkipButtonClicked;

	UPROPERTY(BlueprintReadWrite, Category="FortActivatableVideoPanel")
	bool bOverwriteSkip;

	UPROPERTY(BlueprintAssignable)
	FOnMediaPlayerEndReached OnMediaPlayerEndReached;

	UPROPERTY(BlueprintAssignable)
	FOnMediaOpened OnMediaOpened;

	UPROPERTY(BlueprintAssignable)
	FOnMediaOpenFailed OnMediaOpenFailed;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HideControls();

	UFUNCTION(BlueprintImplementableEvent)
	void MediaOpened();

	UFUNCTION(BlueprintImplementableEvent)
	void MediaOpenFailed();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowControls();

	UPROPERTY(EditAnywhere, Category="FortActivatableVideoPanel")
	bool AutomaticallyDismissPanel;

private:
	UPROPERTY(EditAnywhere, Category="FortActivatableVideoPanel")
	bool bAutoPlayOnActivated;

	UPROPERTY(EditAnywhere, Category="FortActivatableVideoPanel")
	bool bAllowSkipping;

	UPROPERTY(Transient)
	bool ControlsVisible;

	UPROPERTY(Transient)
	float LastInteractionTime;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivatableVideoPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UFortVideoPlayerWidget> VideoPlayerWidget;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Skip;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_ThrobberBackground;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Throbber;

	UPROPERTY(EditAnywhere, Category="FortActivatableVideoPanel")
	TObjectPtr<USoundMix> ActiveSoundMix;

};

