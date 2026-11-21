// Copyright Epic Games, Inc. All Rights Reserved.

#include "Quests/ControllerComponent_Quests.h"
#include "Net/UnrealNetwork.h"

UControllerComponent_Quests::UControllerComponent_Quests(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UControllerComponent_Quests::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UControllerComponent_Quests, GrantedQuestDataArray);
	DOREPLIFETIME(UControllerComponent_Quests, UpdatedQuestObjectivesArray);
}
