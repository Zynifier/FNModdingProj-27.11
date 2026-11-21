// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_PinQuest.h"

UFortControllerComponent_PinQuest::UFortControllerComponent_PinQuest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortControllerComponent_PinQuest::ClientPinQuest_Implementation(const UFortQuestItemDefinition_Athena* QuestDefToPin)
{
}

EAthenaPinnedQuestType UFortControllerComponent_PinQuest::GetPinnedQuestType() const
{
	return EAthenaPinnedQuestType();
}

void UFortControllerComponent_PinQuest::ServerPinQuest_Implementation(const UFortQuestItemDefinition_Athena* QuestDefToPin)
{
}
