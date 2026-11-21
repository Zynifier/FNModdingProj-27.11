// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortUrgentQuestData.h"
#include "FortTransientQuestGameplayAbility.generated.h"

class UFortQuestItemDefinition_Athena;

UCLASS()
class UFortTransientQuestGameplayAbility : public UFortGameplayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPostAbilityInitialization();

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CompleteQuest() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void FailQuest() const;

	UFUNCTION(BlueprintCallable)
	void StartUrgentQuestEvent(FUrgentQuestData UrgentQuestData);

	UFUNCTION(BlueprintCallable)
	void StopUrgentQuestEvent(const FUrgentQuestData& UrgentQuestData);

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnPostAbilityInitialization, Category="FortTransientQuestGameplayAbility")
	TObjectPtr<UFortQuestItemDefinition_Athena> QuestItemDefinition;

};

