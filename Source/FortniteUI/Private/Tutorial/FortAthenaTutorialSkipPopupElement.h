// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateBrush.h"
#include "FortAthenaTutorialSkipPopupElement.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(meta=(DisableNativeTick))
class UFortAthenaTutorialSkipPopupElement : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaTutorialSkipPopupElement(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoundWidgets")
	FSlateBrush StepIconSlateBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BoundWidgets")
	FText StepDescription;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="BoundWidgets", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Step_TextBlock;

	UPROPERTY(BlueprintReadOnly, Export, Category="BoundWidgets", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Step_ImageIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="BoundWidgets", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Checkmark_Image;

};

