// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortCommunityVotingRevealScreen.generated.h"

class UCommonBorder;
class UCommonButtonLegacy;
class UDynamicEntryBox;
class UFortCommunityVotingManager;
class UFortCommunityVotingOptionReveal;
class UFortStoreFrontOfferInfo;
class URichTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCommunityVotingRevealScreen : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void Dismiss();

	UFUNCTION(BlueprintImplementableEvent, Category="ComRevealScreen")
	void StartFadeInAnimation();

	UFUNCTION(BlueprintImplementableEvent, Category="ComRevealScreen")
	void StartFadeOutScreen(float Delay);

	UFUNCTION(BlueprintImplementableEvent, Category="ComRevealScreen")
	void StartFinalAnimation();

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingRevealScreen")
	float MaxRevealPlayRate;

	UPROPERTY(EditAnywhere, Category="FortCommunityVotingRevealScreen")
	float MinRevealPlayRate;

private:
	UFUNCTION()
	void HandleCloseButtonClicked();

	UFUNCTION()
	void HandleDetailButtonClicked();

	UPROPERTY(Transient)
	TObjectPtr<UFortCommunityVotingManager> VotingManager;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCommunityVotingOptionReveal>> GeneratedOption;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortCommunityVotingOptionReveal>> LoserOptions;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCommunityVotingOptionReveal> WinnerOption;

	UPROPERTY(Transient)
	TObjectPtr<UFortStoreFrontOfferInfo> WinnerOfferInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_Options;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Detail;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_ItemReturns;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> BorderRarityColored;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCommunityVotingOptionReveal> ComOptionRevealWinner;

};

