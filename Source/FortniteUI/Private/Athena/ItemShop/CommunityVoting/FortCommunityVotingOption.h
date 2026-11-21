// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortCommunityVotingOption.generated.h"

class UAthenaItemShopOfferDetailsPreviewWidget;
class UCommonButtonLegacy;
class UFortCommunityVotingFeedback;
class UFortCommunityVotingManager;
class UFortCommunityVotingOptionPreview;
class UFortCommunityVotingVoteCounter;
class UOverlay;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingOption : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool HaveVotesRemaining();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void DisableButtons();

	UFUNCTION(BlueprintImplementableEvent)
	void EnableButtons();

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCommunityVotingOption", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ComOptionVote;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCommunityVotingOption", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> ComOptionDetails;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortCommunityVotingOption", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingVoteCounter> FlameCounter;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingOption")
	TSubclassOf<UFortCommunityVotingFeedback> VoteFeedbackClass;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingOption")
	TSubclassOf<UAthenaItemShopOfferDetailsPreviewWidget> PreviewDetailWidgetClass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingOptionPreview> ComOptionPreview;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> ComVoteFeedbackContainer;

};

