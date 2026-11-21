// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_QuestManagerDataReplicator.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_QuestManagerDataReplicator::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_QuestManagerDataReplicator, QuestRecordDataArray);
	DOREPLIFETIME(UFortControllerComponent_QuestManagerDataReplicator, ObjectiveRecordDataArray);
}
