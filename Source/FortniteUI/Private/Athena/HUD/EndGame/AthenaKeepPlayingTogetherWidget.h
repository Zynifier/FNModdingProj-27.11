// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Misc/Timespan.h"
#include "AthenaKeepPlayingTogetherWidget.generated.h"

class UAthenaIGMSquadDisplayWidget;
class UCommonActivatableWidgetSwitcher;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UPanelWidget;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UAthenaKeepPlayingTogetherWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleOptInClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSkipClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitToLobbyCountdownProgressed(float CountdownValue);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingCanceled();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingErrorMessage(const FText& Message);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingFinished(bool bSuccess);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchmakingUpdate(FTimespan ElapsedTime);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreMatchmakingCountdownProgressed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreMatchmakingCountdownStarted();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaKeepPlayingTogetherWidget")
	float ToLobbyDelayOnError;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaIGMSquadDisplayWidget> SquadDisplayWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaKeepPlayingTogetherWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Skip;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaKeepPlayingTogetherWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_OptIn;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_OptInCountdown;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_MatchmakingStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_CountdownStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_FindingMatchStatus;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Error;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Container_Waiting;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MatchmakingElapsed;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownCurrent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CountdownNext;

};

