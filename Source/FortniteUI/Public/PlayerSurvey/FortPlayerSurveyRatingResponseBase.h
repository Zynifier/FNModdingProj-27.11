// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerSurvey/FortPlayerSurveyResponseWidget.h"
#include "FortPlayerSurveyRatingResponseBase.generated.h"

class UCommonButtonGroupBase;
class UDynamicEntryBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlayerSurveyRatingResponseBase : public UFortPlayerSurveyResponseWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Responses Set"))
	void OnResponsesSet_BP();

private:
	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ResponseGroup;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortPlayerSurveyRatingResponseBase", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Responses;

};

