// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingThanksPopup.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingThanksPopup : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void BroadcastOnFadeOutEnds();

	UFUNCTION(BlueprintCallable)
	void BroadcastOnFadeOutStarts();

	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION(BlueprintImplementableEvent, Category="ThanksVotingPopup")
	void FadeInPopup();

	UFUNCTION(BlueprintImplementableEvent, Category="ThanksVotingPopup")
	void FadeOutPopup();

	UFUNCTION(BlueprintCallable)
	void StartCountdown();

	UFUNCTION()
	void UpdateCountdown();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> ThanksForVoting_Countdown;

};

