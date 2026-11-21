// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "FortOnboardingTooltipWidget.generated.h"

class UCommonButtonBase;

UCLASS()
class FORTNITEUI_API UFortOnboardingTooltipWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	virtual const int32 GetSecondsBeforeClosing() const;

	UFUNCTION(BlueprintCallable)
	virtual void NotifyCloseAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndTooltip();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowTooltip();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortOnboardingTooltipWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Dismiss_Button;

	UPROPERTY(EditAnywhere, Category="Onboarding")
	FGameplayTag OnboardingTutorialId;

	UPROPERTY(EditAnywhere, Category="FortOnboardingTooltipWidget", meta=(EditCondition="false", EditConditionHides))
	bool bDesignTime_ShowTutorialDurationSeconds;

	UPROPERTY(EditAnywhere, Category="Onboarding", meta=(EditCondition="bDesignTime_ShowTutorialDurationSeconds", EditConditionHides))
	int32 TutorialDurationSeconds;

};

