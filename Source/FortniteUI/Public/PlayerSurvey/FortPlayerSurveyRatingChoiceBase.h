// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortPlayerSurveyRatingChoiceBase.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UFortPlayerSurveyRatingChoiceBase : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSurveyResetChoice();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortPlayerSurveyRatingChoiceBase", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_RatingValue;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortPlayerSurveyRatingChoiceBase", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Label;

};

