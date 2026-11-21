// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCommunityVotingTutorialPopup.generated.h"

class UCommonButtonLegacy;
class UCommonWidgetSwitcherLegacy;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingTutorialPopup : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CloseTutorial();

protected:
	UFUNCTION(BlueprintCallable)
	void OnSlideAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayInSlideAnimation(int32 Index);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayOutSlideAnimation(int32 Index);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayTutorialAnimation();

private:
	UPROPERTY(EditAnywhere, Category="FortCommunityVotingTutorialPopup")
	int32 NumberOfSlide;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingTutorialPopup")
	float DelayBetweenSlide;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingTutorialPopup")
	float DelayOutAnimation;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingTutorialPopup", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ButtonNextInputAction;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingTutorialPopup", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ButtonCloseInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextStep;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Buttons_Switcher;

};

