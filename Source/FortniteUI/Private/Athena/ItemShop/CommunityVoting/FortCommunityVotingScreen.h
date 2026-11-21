// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCommunityVotingScreen.generated.h"

class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;
class UDynamicEntryBox;
class UFortCommunityVotingAvailableVotesWidget;
class UFortCommunityVotingCountdown;
class UFortCommunityVotingManager;
class UFortCommunityVotingModalPopup;
class UFortCommunityVotingOption;
class UFortCommunityVotingThanksPopup;
class UFortCommunityVotingTutorialPopup;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="VotingScreen")
	void FadeOutScreen();

private:
	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION()
	void HandleBackButton(bool& bPassthrough);

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingScreen")
	FText RevealWinnerPopupTitle;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingScreen")
	FText RevealWinnerPopupBanner;

	UPROPERTY(EditDefaultsOnly, Category="FortCommunityVotingScreen")
	TSubclassOf<UFortCommunityVotingModalPopup> CommunityVotingModalPopupClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCommunityVotingScreen")
	TSubclassOf<UFortCommunityVotingTutorialPopup> CommunityVotingModalTutorialPopupClass;

	UPROPERTY(EditDefaultsOnly, Category="FortCommunityVotingScreen", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle BackInput;

	UPROPERTY(Transient)
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCommunityVotingOption> HighlightedOption;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingCountdown> Countdown_RemainingTime;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Options;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ComBackButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingAvailableVotesWidget> AvailableSparksWidget;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_VotingTip;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingThanksPopup> Com_ThanksForVotingMessage;

};

