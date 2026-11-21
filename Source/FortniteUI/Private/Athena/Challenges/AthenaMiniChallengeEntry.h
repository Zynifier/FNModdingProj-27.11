// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaMiniChallengeEntry.generated.h"

class UFortLazyImage;
class UFortQuestItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaMiniChallengeEntry : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void FinishedQuestUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void QuestCompletedFinishFill();

	UFUNCTION(BlueprintImplementableEvent)
	void RefeshWithNewQuest();

	UFUNCTION(BlueprintImplementableEvent)
	void SetXpValue(int32 XpRewardValue);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateQuestDescription(const FText& Description);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void TriggerNewQuestGranted();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateProgressBar(int32 LastKnownCount, int32 AchivedCount, int32 GoalCount);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> QuestIcon;

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItemDefinition> QuestDef;

	UPROPERTY(Transient)
	TObjectPtr<UFortQuestItemDefinition> PendingQuestDef;

	UPROPERTY(Transient)
	int32 DisplayGoal;

	UPROPERTY(Transient)
	int32 DisplayAchivedCount;

	UPROPERTY(Transient)
	int32 PendingGoalCount;

	UPROPERTY(Transient)
	int32 PendingLastKnown;

	UPROPERTY(Transient)
	int32 PendingAchivedCount;

	UPROPERTY(Transient)
	int32 PendingXpValue;

	UPROPERTY(Transient)
	bool bPendingUpdate;

	UPROPERTY(BlueprintReadOnly, Category="AthenaMiniChallengeEntry")
	bool bIsFirstTimeBoosted;

	UPROPERTY(EditAnywhere, Category="AthenaMiniChallengeEntry")
	FName ParamName;

};

