// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortAthenaQuestGameplayAbility.generated.h"

class UFortQuestItem;

UCLASS()
class UFortAthenaQuestGameplayAbility : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnObjectiveCompleted(const UFortQuestItem* QuestItem, const FName ObjectiveBackendName);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnObjectiveUpdated(const UFortQuestItem* QuestItem, const FName ObjectiveBackendName, const int32 AchivedCount, const int32 GoalCount);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnQuestCompleted(const UFortQuestItem* QuestItem);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortQuestItem>> BoundQuestItems;

};

