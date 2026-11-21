// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaGoalsPageBaseCard.generated.h"

class UAthenaChallengeDateTimeTextBlock;
class UDynamicEntryBox;
class UPanelWidget;
enum class EAthenaChallengeTimerState : uint8;

UCLASS(Abstract, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaGoalsPageBaseCard : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaGoalsPageBaseCard(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnTimerSet(const EAthenaChallengeTimerState TimerState);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowNewBang(bool bEnabled);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageBaseCard", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Goals;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageBaseCard", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaChallengeDateTimeTextBlock> DateTimeText_TimeRemaining;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageBaseCard", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_TimeRemaining;

	UPROPERTY(EditDefaultsOnly, Category="AthenaGoalsPageBaseCard", meta=(ClampMax="100", ClampMin="0"))
	int32 GoalPreallocationCount;

};

