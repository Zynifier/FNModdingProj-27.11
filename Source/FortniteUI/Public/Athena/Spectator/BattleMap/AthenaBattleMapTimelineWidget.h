// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "AthenaBattleMapTimelineWidget.generated.h"

class ABattleMapNode;
class ABattleMapPawnLive;
class AFortPlayerControllerSpectating;
class UCommonButtonLegacy;
enum class ESpectatorCameraType : uint8;

UENUM()
enum class EBattleMapTimelineWidgetState : uint8
{
	None = 0,
	HasNext = 1,
	HasPrevious = 2,
	IsInReplay = 4,
	CanBeScrubbed = 8,
	IsStreaming = 16,
	Invalid = 32,
};

UCLASS()
class UAthenaBattleMapTimelineWidget : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleCameraTypeChanged(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType);

	UFUNCTION()
	void HandleExitBattleMapPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleSelectedNode(const ABattleMapNode* InSelectedNode);

	UFUNCTION()
	void HandleTimelineBackwardPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleTimelineForwardPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleTimelineModeChanged(bool bEnabled);

	UFUNCTION()
	void HandleTimelineScrubToPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleTimelineStopPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleToggledBattleMapLive(ABattleMapPawnLive* BattleMapPawn);

	UFUNCTION()
	void HandleZoomInHeld(float HeldPercent);

	UFUNCTION()
	void HandleZoomInPressed(bool& bPassThrough);

	UFUNCTION()
	void HandleZoomOutHeld(float HeldPercent);

	UFUNCTION()
	void HandleZoomOutPressed(bool& bPassThrough);

	UFUNCTION()
	void OnReplayLevelStreamingChanged(const bool bStreaming);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Forward;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Backward;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	float ForwardButtonPositionAlpha;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	float BackwardButtonPositionAlpha;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle ForwardDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle BackwardDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle StopDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle ScrubToDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle ExitBattleMapDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle ZoomInDataTableRow;

	UPROPERTY(EditDefaultsOnly, Category="BattleMap")
	FDataTableRowHandle ZoomOutDataTableRow;

};

