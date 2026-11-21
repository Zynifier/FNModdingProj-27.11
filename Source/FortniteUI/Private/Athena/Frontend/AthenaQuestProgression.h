// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaQuestProgression.generated.h"

class UCommonRichTextBlock;
class UCommonTextBlock;
class UProgressBar;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaQuestProgression : public UCommonUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChallengeDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_ChallengeCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_Challenge_Front;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar_Challenge_Back;

};

