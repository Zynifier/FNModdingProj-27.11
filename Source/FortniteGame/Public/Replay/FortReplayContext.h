// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "Replay/FortReplayTypes.h"
#include "FortReplayContext.generated.h"

class AFortPlayerControllerSpectating;
class UFortSpectateClickableMapIcon;
class UObject;
enum class EFortReplayEventType : uint8;
enum class EHudVisibilityState : uint8;
enum class ESpectatorCameraType : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHighlightReelPlayingDelegate, bool, bIsPlaying);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoParamDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCurrentShotChanged, int32, ShotIndex);

USTRUCT(BlueprintType)
struct FFortReplayFXState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ReplayFX")
	int32 DefaultParticleLODBias;

	UPROPERTY(BlueprintReadOnly, Category="ReplayFX")
	int32 DefaultDepthOfFieldQuality;

	UPROPERTY(BlueprintReadOnly, Category="ReplayFX")
	int32 OverrideParticleLODBias;

	UPROPERTY(BlueprintReadOnly, Category="ReplayFX")
	int32 OverrideDepthOfFieldQuality;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayFXStateChange, FFortReplayFXState, FXState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayHudNotificationSuppressionChanged, bool, bShouldSuppress);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayHudVisibilityChanged, const EHudVisibilityState, IsVisible);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayLevelStreamingChanged, bool, bStreaming);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayPauseStateChanged, bool, bPaused);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayPlaybackMultiplierChanged, float, NewMultiplier);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReplayScrubComplete);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReplayScrubStart);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplaySessionIDWatermarkChanged, bool, bShowWatermark);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayTimeChanged, float, TimeNow);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReplayTimelineFocusChanged, bool, bIsTimelineFocus);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReplayTimelineMarkerAdded, EFortReplayEventType, EventType, float, TimeRatio, int32, MarkerIdx);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReplayTimelineMarkersCleared);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FReplayTimelineRangeChanged, float, StartTime, float, EndTime);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSequencerReadyDelegate, bool, bIsReadyForPlayback);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleHighlightsListDelegate);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleReplayPlayerList);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FToggleReplayViewSettings);

USTRUCT()
struct FFortReplayEvent
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FFortReplayPlaybackState
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Timeline")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="Timeline")
	float EndTime;

	UPROPERTY(BlueprintReadOnly, Category="Timeline")
	float TimeNow;

	UPROPERTY(BlueprintReadOnly, Category="Timeline")
	bool bIsPaused;

	UPROPERTY(BlueprintReadOnly, Category="Timeline")
	float PlaybackSpeedMultiplier;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	EHudVisibilityState HUDVisibility;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	bool bLevelStreaming;

	UPROPERTY(BlueprintReadOnly, Category="HUD")
	bool bHasRelevancyZone;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortReplayContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void DecreasePlaybackMultiplier();

	UFUNCTION(BlueprintPure, Category="ReplayContext")
	FText GetCameraNameFromType(const ESpectatorCameraType CamType) const;

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	FString GetEventTooltip(int32 EventIndex);

	UFUNCTION(BlueprintPure)
	float GetMaxMapZoomLevel() const;

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void IncreasePlaybackMultiplier();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	bool IsDepthOfFieldActive();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void JumpReplayToTimelinePosition(float TimeRatio);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void JumpToEvent(int32 EventIndex);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void JumpToNextEvent();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void JumpToPreviousEvent();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void ReplayHUDCleanup();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void SetSessionIdWatermarkVisible(bool bIsVisible);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void SkipBack(const float TimeInSeconds);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void SkipForward(const float TimeInSeconds);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void SkipTo(const float TimeInSeconds);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void TakeScreenshot();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void ToggleHighlightsListVisibility();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void ToggleHUDVisibility();

	UFUNCTION(BlueprintCallable)
	bool ToggleIconVisibility(UClass* ToToggle);

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void TogglePlayerListVisibility();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void TogglePlayPause();

	UFUNCTION(BlueprintCallable, Category="ReplayContext")
	void ToggleViewSettingsVisibility();

	UPROPERTY(BlueprintReadOnly, Category="FortReplayContext")
	FFortReplayPlaybackState PlaybackState;

	UPROPERTY(BlueprintReadOnly, Category="FortReplayContext")
	FFortReplayFXState EffectsState;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayFXStateChange OnReplayFXStateChange;

	UPROPERTY(BlueprintReadOnly, Category="FortReplayContext")
	float TimeBeforeEvent;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayPauseStateChanged OnPauseStateChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplaySessionIDWatermarkChanged OnSessionIdWatermarkVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayTimeChanged OnReplayTimeChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayTimelineRangeChanged OnReplayTimelineChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayPlaybackMultiplierChanged OnReplayPlaybackMultiplierChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayHudVisibilityChanged OnReplayHudVisibilityChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayHudNotificationSuppressionChanged OnReplayHudNotificationSuppressionChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FToggleReplayViewSettings OnToggleReplayViewSettings;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FToggleReplayPlayerList OnToggleReplayPlayerList;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FToggleHighlightsListDelegate OnToggleHighlightsListEvent;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayLevelStreamingChanged OnReplayLevelStreamingChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FSequencerReadyDelegate OnSequencerReadyEvent;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayTimelineFocusChanged OnReplayTimelineFocusChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayTimelineMarkerAdded OnReplayTimelineMarkerAdded;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayTimelineMarkersCleared OnReplayTimelineMarkersCleared;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayScrubStart OnReplayScrubStart;

	UPROPERTY(BlueprintAssignable, Category="ReplayContext")
	FReplayScrubComplete OnReplayScrubComplete;

	UPROPERTY(BlueprintAssignable, Category="ReplaySequencer")
	FNoParamDelegate OnToggleSequencer;

	UPROPERTY(BlueprintAssignable, Category="ReplaySequencer")
	FNoParamDelegate OnSequenceFinished;

	UPROPERTY(BlueprintAssignable, Category="ReplaySequencer")
	FOnCurrentShotChanged OnSequenceShotChanged;

	UPROPERTY(BlueprintAssignable, Category="ReplaySequencer")
	FHighlightReelPlayingDelegate OnHighlightPlayingEvent;

private:
	UFUNCTION()
	void OnHighQualityFxEnabledChanged(bool bEnabled);

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortSpectateClickableMapIcon>> InteractiveMapIcons;

	UPROPERTY()
	TMap<TSubclassOf<UObject>, bool> UniqueMapIconVisibility;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerControllerSpectating> SpectatingPC;

};

