// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingAvailableVotesWidget.generated.h"

class UCommonTextBlock;
class UFortEventDateTimeTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingAvailableVotesWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ApplyCurrentVoteNumber();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayAvailableVotes();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayCountdown(float StartValue);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayDecreaseVote();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayEventOver(float StartValue);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIdle();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIncreaseVote();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_CurrentVoteNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NextVoteNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortEventDateTimeTextBlock> DateTimeTextBlock_VoteCountdown;

};

