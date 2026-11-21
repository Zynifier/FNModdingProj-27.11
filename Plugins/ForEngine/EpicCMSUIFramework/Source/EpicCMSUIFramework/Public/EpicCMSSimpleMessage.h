// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "EpicCMSSimpleMessage.generated.h"

class UCommonTextBlock;
class UEpicCMSImage;

UCLASS(Abstract)
class EPICCMSUIFRAMEWORK_API UEpicCMSSimpleMessage : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Simple Message", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> TitleText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Simple Message", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> BodyText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Simple Message", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UEpicCMSImage> PrimaryImage;

};

