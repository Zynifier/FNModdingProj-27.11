// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortTimelineBase.generated.h"

class UCanvasPanel;
class UCommonTextBlock;
class UFortReplayTimelineMarker;
class UOverlay;
class UProgressBar;
class USlider;
enum class EFortReplayEventType : uint8;
enum class EHudVisibilityState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTimelineBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleReplayHudVisibilityChanged(EHudVisibilityState VisibilityState);

	UFUNCTION()
	void HandleReplayTimeChanged(float ReplayTime);

	UFUNCTION()
	void HandleReplayTimelineChanged(float StartTime, float EndTime);

	UFUNCTION()
	void HandleReplayTimelineMarkerAdded(EFortReplayEventType EventType, float RelativeTime, int32 EventIndex);

	UPROPERTY(EditDefaultsOnly, Category="FortTimelineBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ConfirmActionRowHandle;

	UPROPERTY(EditDefaultsOnly, Category="FortTimelineBase", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle CancelActionRowHandle;

	UPROPERTY(EditAnywhere, Category="FortTimelineBase")
	TSubclassOf<UFortReplayTimelineMarker> TimelineMarkerClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USlider> Slider_Gamepad;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTimelineBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_TimeElapsed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CurrentTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_EndTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCanvasPanel> CanvasPanel_Markers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_ProgressBar;

};

