// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaSpectatorHUDControlsBase.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerState;
class AFortReplaySpectator;
class UCommonButtonLegacy;
class UFortTimelineBase;
class UIconTextButtonSpectatorBase;
enum class ESpectatorCameraType : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorHUDControlsBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void CenterControls();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ResetFocusToPlayPauseIfNeeded();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleBattleMapTimelineModeChanged(bool bIsOnTimelineMode);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCameraTypeChanged(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

private:
	UFUNCTION()
	void HandleReplayHighlightsAvailable(AFortReplaySpectator* Sender, bool bIsAvailable);

	UFUNCTION()
	void OnCameraTypeChangedInternal(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortTimelineBase> ReplayTimeline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_FocusTimeline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UIconTextButtonSpectatorBase> IconTextButtonReplay_PlayHighlights;

};

