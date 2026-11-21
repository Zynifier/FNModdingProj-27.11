// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/QuestItemComponents/FortQuestItemComponent_ObjectiveGate.h"

void UFortQuestItemComponent_ObjectiveGate::HandleRegisterGatesForAdditionalParticipant(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants)
{
}

void UFortQuestItemComponent_ObjectiveGate::HandleRemoveGatesFromAdditionalParticipant(const TScriptInterface<IQuestInstanceInterface>& QuestInstance, const TArray<TScriptInterface<IQuestInstanceParticipantInterface>>& Participants)
{
}

void UFortQuestItemComponent_ObjectiveGate::SetGateOpenState(const FName ObjBackendName, const TSubclassOf<UFortGameplayAbility_ObjectiveGate> GateClass, const bool bInOpenCloseState)
{
}

void UFortQuestItemComponent_ObjectiveGate::SetVerbBasedGateOpenState(const FName ObjBackendName, const FGuid& GateID, const bool bInOpenCloseState)
{
}
