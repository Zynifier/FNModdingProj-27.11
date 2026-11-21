// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaGoalsPageQuestCardLine.generated.h"

class UAthenaChallengeRewards;
class UCommonRichTextBlock;
class UCommonTextBlock;

UCLASS(Abstract, meta=(Category="Fortnite UI"))
class UAthenaGoalsPageQuestCardLine : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaGoalsPageQuestCardLine(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void Reset();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetObjectiveProgress(const int32 Achieved, const int32 Required, const bool bIsRewardAcquired);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageQuestCardLine", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_GoalName;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageQuestCardLine", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeRewards> UserWidget_Rewards;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaGoalsPageQuestCardLine", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_QuestID;

};

