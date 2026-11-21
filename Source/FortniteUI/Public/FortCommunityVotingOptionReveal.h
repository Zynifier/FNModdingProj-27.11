// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCommunityVotingOptionReveal.generated.h"

class UFortCommunityVotingManager;
class UImage;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingOptionReveal : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnWinnerRevealAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent, Category="ComOptionReveal")
	void RevealWinnerAnimation();

	UFUNCTION(BlueprintImplementableEvent, Category="ComOptionReveal")
	void StartRevealAnimation(float PlayRate);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Main;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Duplicate;

};

