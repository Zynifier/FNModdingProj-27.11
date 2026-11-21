// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "CommonUserWidget.h"
#include "AthenaBattleMapNodeTooltip.generated.h"

class ABattleMapNode;
class ABattleMapPawnLive;
class AFortPlayerControllerSpectating;
class UCommonTextBlock;
class UWidget;
enum class BattleMapHoveredReason : int32;
enum class ESpectatorCameraType : uint8;

UCLASS()
class UAthenaBattleMapNodeTooltip : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleCameraTypeChanged(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType);

	UFUNCTION()
	void HandleHoveredNode(const ABattleMapNode* Node, BattleMapHoveredReason Reason);

	UFUNCTION()
	void HandleInputMethodChanged(ECommonInputType NewInputType);

	UFUNCTION()
	void HandleTimelineModeChanged(bool bEnabled);

	UFUNCTION()
	void HandleToggledBattleMapLive(ABattleMapPawnLive* BattleMapPawn);

	UFUNCTION()
	void HandleUnhoveredNode(const ABattleMapNode* Node, BattleMapHoveredReason Reason);

	UFUNCTION()
	void OnReplayLevelStreamingChanged(const bool bStreaming);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NodeTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NodeDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NodeTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Selection;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_Scrubbing;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> Widget_ScrubbingGamepad;

};

