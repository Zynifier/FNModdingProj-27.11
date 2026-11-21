// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCommunityVotingModalPopup.generated.h"

class UCommonBorder;
class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortCommunityVotingScreen;
class UFortCommunityVotingTileCandidate;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingModalPopup : public UFortActivatablePanel
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void Dismiss();

	UFUNCTION()
	void HandleButton(bool& bPassThrough);

	UFUNCTION(BlueprintCallable)
	void HandleButtonArgless();

	UFUNCTION()
	void HandleVoteButtonClicked();

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingModalPopup", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle buttonInputAction;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingModalPopup")
	TSubclassOf<UFortCommunityVotingScreen> VotingScreenClass;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingModalPopup")
	TSubclassOf<UFortCommunityVotingTileCandidate> CandidateClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_VoteNow;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_TapToCloseZone;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Options;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Banner;

};

