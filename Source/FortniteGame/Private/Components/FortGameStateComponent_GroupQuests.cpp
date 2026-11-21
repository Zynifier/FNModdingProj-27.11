// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortGameStateComponent_GroupQuests.h"
#include "Net/UnrealNetwork.h"

void UFortGameStateComponent_GroupQuests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortGameStateComponent_GroupQuests, GrantedQuestDataArray);
	DOREPLIFETIME(UFortGameStateComponent_GroupQuests, UpdatedQuestObjectivesArray);
}
