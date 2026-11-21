// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/IQuestInstanceManagerInterface.h"

void IQuestInstanceManagerInterface::BindEventToOnQuestCompleted(FOnGenericBlueprintQuestEvent DelegateSignature)
{
}

void IQuestInstanceManagerInterface::BindEventToOnQuestGranted(FOnGenericBlueprintQuestEvent DelegateSignature)
{
}

TScriptInterface<IQuestInstanceInterface> IQuestInstanceManagerInterface::FindQuestInstance(const FString& QuestID) const
{
	return TScriptInterface<IQuestInstanceInterface>();
}

TScriptInterface<IQuestInstanceInterface> IQuestInstanceManagerInterface::GrantQuest(const TScriptInterface<IQuestDefinitionInterface>& QuestDefinition)
{
	return TScriptInterface<IQuestInstanceInterface>();
}

void IQuestInstanceManagerInterface::UnbindAllEventsFromOnQuestCompleted(UObject* EventReceiver)
{
}

void IQuestInstanceManagerInterface::UnbindAllEventsFromOnQuestGranted(UObject* EventReceiver)
{
}
