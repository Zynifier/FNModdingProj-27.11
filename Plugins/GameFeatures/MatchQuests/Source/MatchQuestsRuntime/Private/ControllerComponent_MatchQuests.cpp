// Copyright Epic Games, Inc. All Rights Reserved.

#include "ControllerComponent_MatchQuests.h"
#include "Net/UnrealNetwork.h"

UControllerComponent_MatchQuests::UControllerComponent_MatchQuests(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UControllerComponent_MatchQuests::OnRep_QuestOffering() const
{
}

void UControllerComponent_MatchQuests::Server_SetSelectedQuest_Implementation(const TScriptInterface<IQuestDefinitionInterface>& Quest)
{
}

void UControllerComponent_MatchQuests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UControllerComponent_MatchQuests, QuestOffering);
}
