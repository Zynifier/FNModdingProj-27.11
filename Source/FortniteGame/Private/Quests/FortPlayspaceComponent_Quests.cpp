// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/FortPlayspaceComponent_Quests.h"
#include "Net/UnrealNetwork.h"

void UFortPlayspaceComponent_Quests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayspaceComponent_Quests, GrantedQuestDataArray);
	DOREPLIFETIME(UFortPlayspaceComponent_Quests, UpdatedQuestObjectivesArray);
}
