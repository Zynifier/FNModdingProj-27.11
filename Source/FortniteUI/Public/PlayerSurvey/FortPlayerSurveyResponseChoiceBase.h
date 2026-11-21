// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FortPlayerSurveyResponseChoiceBase.generated.h"

class UCommonTextBlock;

UENUM(BlueprintType)
enum EFortPlayerSurveyResponseChoiceType
{
	Checkbox = 0,
	Radio = 1,
};

UCLASS(Abstract)
class UFortPlayerSurveyResponseChoiceBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetChoiceType(EFortPlayerSurveyResponseChoiceType Type);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSurveyResetChoice();

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortPlayerSurveyResponseChoiceBase", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Response;

};

