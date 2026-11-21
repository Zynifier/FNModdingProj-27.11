// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaChallengeRecapEntry.generated.h"

class UCommonTextBlock;
class UWidgetSwitcher;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeRecapEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void IntroFinished();

	UFUNCTION(BlueprintCallable)
	void OutroFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void StartIntroAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void StartOutroAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateProgressBar(float StartingPercent, float EndingPercent);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestObjective;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CompletionCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidgetSwitcher> Switcher_Progression;

};

