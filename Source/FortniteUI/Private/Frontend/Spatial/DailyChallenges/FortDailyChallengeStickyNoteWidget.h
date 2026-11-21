// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortDailyChallengeStickyNoteWidget.generated.h"

class UAthenaConfirmationWindow;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class USizeBox;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortDailyChallengeStickyNoteWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHasChallengeUpdated(bool bHasAssignedChallenge);

private:
	UPROPERTY(EditInstanceOnly, Category="FortDailyChallengeStickyNoteWidget")
	int32 MyDailyChallengeIndex;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDailyChallengeStickyNoteWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_RerollChallenge;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ChallengeDesc;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Progress;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_ContentEnforcedSize;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortDailyChallengeStickyNoteWidget", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_NextChallengeTime;

	UPROPERTY(EditDefaultsOnly, Category="FortDailyChallengeStickyNoteWidget")
	TSubclassOf<UAthenaConfirmationWindow> ConfirmationWindowClass;

};

