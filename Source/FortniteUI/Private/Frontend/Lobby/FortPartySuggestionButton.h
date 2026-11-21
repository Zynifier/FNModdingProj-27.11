// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortPartySuggestionButton.generated.h"

class UCommonTextBlock;
class UFortSocialNameTextBlock;

UCLASS(Abstract)
class UFortPartySuggestionButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateDisplayInfo();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDismissSuggestion();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayInfoUpdated(bool bIsInvited, bool bIsPlaying);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewSuggestionAdded();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSuggestionAccepted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSuggestionChanged();

private:
	UFUNCTION()
	void HandleLobbyStarted();

	UFUNCTION()
	void HandleSuggestionAccepted(int32 PlayerId);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialNameTextBlock> Text_SocialName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActionText;

};

