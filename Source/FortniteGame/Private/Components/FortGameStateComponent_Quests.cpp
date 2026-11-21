// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_Quests.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_Quests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_Quests, GrantedQuestDataArray);
	DOREPLIFETIME(UFortGameStateComponent_Quests, UpdatedQuestObjectivesArray);
}
