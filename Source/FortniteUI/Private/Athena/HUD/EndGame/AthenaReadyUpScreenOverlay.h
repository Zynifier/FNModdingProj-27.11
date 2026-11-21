// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Misc/Timespan.h"
#include "AthenaReadyUpScreenOverlay.generated.h"

class UAthenaIGMPartyMemberWidget;
class UAthenaPreserveSquadButton;
class UCommonButtonBase;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UPanelWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaReadyUpScreenOverlay : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCancelReadyUp();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownProgressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCountdownStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitToLobbyCountdownProgressed(float CountdownValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCancelled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingErrorMessage(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingFinished(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingUpdate(FTimespan ElapsedTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnReadyUp();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaReadyUpScreenOverlay")
	float ToLobbyDelayOnError;

	UPROPERTY(EditInstanceOnly, Category="AthenaReadyUpScreenOverlay", meta=(MultiLine="TRUE"))
	FText ReadyUpStatusText;

	UPROPERTY(EditInstanceOnly, Category="AthenaReadyUpScreenOverlay", meta=(MultiLine="TRUE"))
	FText MatchmakingMessageText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Cancel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_StartMatch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_MatchmakingStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_CountdownStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_FindingMatchStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Waiting;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_NoStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingElapsed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownCurrent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownNext;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaPreserveSquadButton> Button_StayTogether;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PartyKPTStatus;

	UPROPERTY(Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaIGMPartyMemberWidget>> PartyWidgets;

};

