// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeListEntry.h"
#include "AthenaChallengeListEntry_GoalCard.generated.h"

class UAthenaGoalsPageQuestCard;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaChallengeListEntry_GoalCard : public UAthenaChallengeListEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeDataSet(bool bDisabled);

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaChallengeListEntry_GoalCard", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaGoalsPageQuestCard> GoalCard;

};

