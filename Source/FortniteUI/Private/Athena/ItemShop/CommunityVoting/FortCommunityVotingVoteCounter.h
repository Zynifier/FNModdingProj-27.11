// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingVoteCounter.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingVoteCounter : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PlayFadeIn();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayFadeOut();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIdle();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayIncreaseVote();

	UPROPERTY(BlueprintReadOnly, Category="FortCommunityVotingVoteCounter")
	bool HasOneOrMoreVote;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_CurrentVoteNumber;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_NextVoteNumber;

};

