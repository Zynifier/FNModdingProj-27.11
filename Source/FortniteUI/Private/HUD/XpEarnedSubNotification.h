// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "XpEarnedSubNotification.generated.h"

class UFortQuestItem;
enum class EFortEarnedSubRewardType : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UXpEarnedSubNotification : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FinishedDisplayAnim();

	UFUNCTION(BlueprintImplementableEvent)
	void StartNotificationIntro();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetRewardValue(int32 RewardValue, EFortEarnedSubRewardType RewardType);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItem> QuestItem;

	UPROPERTY(Transient)
	bool bHasDisplayedXp;

	UPROPERTY(Transient)
	bool bHasDisplayedBars;

};

