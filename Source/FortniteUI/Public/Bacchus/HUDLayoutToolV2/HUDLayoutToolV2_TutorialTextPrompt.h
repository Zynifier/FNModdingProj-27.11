// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "HUDLayoutToolV2_TutorialTextPrompt.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UHUDLayoutToolV2_TutorialTextPrompt : public UCommonActivatableWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TutorialTextPrompt")
	FText TitleText;

	UPROPERTY(EditAnywhere, Category="HUDLayoutToolV2_TutorialTextPrompt")
	FText DescriptionText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Title;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_Description;

};

