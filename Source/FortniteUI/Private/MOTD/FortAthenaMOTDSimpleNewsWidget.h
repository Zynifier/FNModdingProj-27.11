// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "MOTD/FortAthenaMOTDWidget.h"
#include "FortAthenaMOTDSimpleNewsWidget.generated.h"

class UCommonButtonLegacy;
class UEpicCMSImage;
class URichTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAthenaMOTDSimpleNewsWidget : public UCommonActivatableWidget, public IFortAthenaMOTDNewsChildren
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDSimpleNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> CMSImage_NewsImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDSimpleNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_NewsTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDSimpleNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichTextBlock_NewsBody;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMOTDSimpleNewsWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> CommonButton_Close;

};

