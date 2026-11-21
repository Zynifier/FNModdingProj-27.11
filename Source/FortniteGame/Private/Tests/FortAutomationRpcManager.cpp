// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tests/FortAutomationRpcManager.h"
#include "Net/UnrealNetwork.h"

void AFortAutomationRpcTrackedActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAutomationRpcTrackedActor, TrackedActor);
	DOREPLIFETIME(AFortAutomationRpcTrackedActor, ActorName);
}
