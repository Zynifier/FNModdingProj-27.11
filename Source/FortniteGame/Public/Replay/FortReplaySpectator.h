// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Player/FortPlayerControllerSpectating.h"
#include "Replay/ReplaySequenceComponentOwner.h"
#include "FortReplaySpectator.generated.h"

class AFortPawn;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortReplaySpectator;
class APostProcessVolume;
class AUnicornDriver;
class IFortTimeOfDayManagerInterface;
class UFortReplaySequenceComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FServerHighlightsAvailableDelegate, AFortReplaySpectator*, Sender, bool, bAreHghlightsAvailable);

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortReplaySpectator : public AFortPlayerControllerSpectating, public IReplaySequenceComponentOwner
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AreReplayGameHighlightsAvailable() const;

	UFUNCTION(BlueprintPure)
	UFortReplaySequenceComponent* GetSequencerComponent() const;

	UFUNCTION(BlueprintPure)
	bool HasPermissionToViewHighlights() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotifyNewPlaybackMultiplier(float NewMultiplier);

	UFUNCTION(BlueprintImplementableEvent)
	void OnZoomInBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnZoomInEnd();

	UFUNCTION(BlueprintImplementableEvent)
	void OnZoomOutBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnZoomOutEnd();

	UFUNCTION(BlueprintCallable)
	void PlayThroughHightlightReel(const FHighlightReel& Highlights);

	UFUNCTION(Exec)
	void SequencerLoadAndPlayFile(const FString& SequenceFileName);

	UFUNCTION(BlueprintCallable)
	void SetAllowTimeDilation(bool bAllow);

	UFUNCTION()
	bool SetOverrideTimeOfDay(bool bOverride, float Time, bool bImmediate, float Speed);

	UFUNCTION()
	bool SetTimeOfDaySpeed(float Speed);

	UFUNCTION(BlueprintPure)
	bool ShouldSetupUIForRecording() const;

	UFUNCTION(Exec)
	void SkipToNextSequencerShot() const;

	UFUNCTION(Exec)
	void SkipToSequencerShot(int32 ShotIndex) const;

	UPROPERTY()
	TArray<float> PlaybackSpeedLUT;

	UPROPERTY(BlueprintAssignable)
	FServerHighlightsAvailableDelegate OnServerHighlightsAvailableEvent;

	UPROPERTY(Config)
	float HighlightAnnotationTime;

	UPROPERTY(Config)
	float ExtendedGameHighlightsTargetSeconds;

	UPROPERTY(Config)
	float GameHighlightsTargetSeconds;

	UPROPERTY(Config)
	float FeatureReelTargetSeconds;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPauseStateChanged(bool bNewPauseState);

	UFUNCTION()
	void OnPawnForReplayRelevancyChanged(AFortPawn* NewRelevancyPawn);

	UPROPERTY()
	FUniqueNetIdRepl FollowedPlayerUniqueId;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerState> FollowedPlayerPrivate;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortReplaySequenceComponent> SequencerComponent;

private:
	UFUNCTION()
	void OnDemoScrubComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnPlayerStatePlacementChanged(AFortPlayerStateAthena* Sender, int32 InPlace);

	UFUNCTION()
	void OnReplayExtractionPreScrubComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnScrubComplete(bool bWasSuccessful);

	UFUNCTION()
	void OnShotStartGotoTimeComplete(bool bWasSuccessful);

	UFUNCTION(Exec)
	void SetCloudAltitudes(float NewCloudAltitude = 5000.000000f);

	UPROPERTY(Transient)
	TObjectPtr<APostProcessVolume> MotionBlurTargetFPSVolume;

	UPROPERTY()
	TScriptInterface<IFortTimeOfDayManagerInterface> OverriddenTODManager;

	UPROPERTY(Config)
	float SequencerLoadingScreenRevealTime;

	UPROPERTY(Config)
	bool bShouldUpdateReplayContextAboutSequencer;

	UPROPERTY(Config)
	float BaseSequencerRetryFindPawnGraceTime;

	UPROPERTY(Config)
	float HighlightShotExtraLeadTime;

	UPROPERTY()
	TObjectPtr<AUnicornDriver> UnicornDriver;

};

