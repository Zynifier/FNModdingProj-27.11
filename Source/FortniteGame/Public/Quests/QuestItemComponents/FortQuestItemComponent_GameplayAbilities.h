// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/QuestItemComponents/FortQuestItemComponent.h"
#include "FortQuestItemComponent_GameplayAbilities.generated.h"

class IQuestInstanceInterface;
class IQuestInstanceParticipantInterface;
class UFortQuestItem;

UCLASS()
class UFortQuestItemComponent_GameplayAbilities : public UFortQuestItemComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleRegisterAbilitiesForAdditionalParticipants(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

	UFUNCTION()
	void HandleRemoveAbilitiesFromAdditionalParticipants(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants);

	UFUNCTION()
	void ListenForObjectiveReset(const UFortQuestItem* QuestItem, const FName ObjectiveBackendName);

};

