// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PlayerSurvey/FortPlayerSurveyResponseWidget.h"
#include "FortPlayerSurveyChoiceResponseWidget.generated.h"

class UDynamicEntryBox;

UCLASS(Abstract)
class UFortPlayerSurveyChoiceResponseWidget : public UFortPlayerSurveyResponseWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetNumberOfResponses(int32 NumberOfResponses);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerSurveyChoiceResponseWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Responses;

};

