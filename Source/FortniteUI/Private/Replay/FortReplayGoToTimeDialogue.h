// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "CommonActivatablePanelLegacy.h"
#include "FortReplayGoToTimeDialogue.generated.h"

class UCommonButtonLegacy;
class UEditableText;
class UTextBlock;

UCLASS(meta=(DisableNativeTick))
class UFortReplayGoToTimeDialogue : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleReplayTimelineChanged(float StartTime, float EndTime);

	UFUNCTION()
	void HandleTextChanged(const FText& Text);

	UFUNCTION()
	void HandleTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_GoToSeconds;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_HowTo;

};

