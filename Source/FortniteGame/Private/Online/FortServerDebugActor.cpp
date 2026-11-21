// Copyright Epic Games, Inc. All Rights Reserved.

#include "Online/FortServerDebugActor.h"
#include "Net/UnrealNetwork.h"

void AFortServerDebugActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortServerDebugActor, ServerMemSharedInKb);
	DOREPLIFETIME(AFortServerDebugActor, ServerMemUniqueInKb);
	DOREPLIFETIME(AFortServerDebugActor, ServerMemVirtualInKb);
	DOREPLIFETIME(AFortServerDebugActor, ServerMemPhysicalInKb);
	DOREPLIFETIME(AFortServerDebugActor, SharedDeltaInLastMinute);
	DOREPLIFETIME(AFortServerDebugActor, SharedDeltaSinceProcessStart);
	DOREPLIFETIME(AFortServerDebugActor, SharedDeltaSinceDebugStart);
	DOREPLIFETIME(AFortServerDebugActor, UniqueDeltaInLastMinute);
	DOREPLIFETIME(AFortServerDebugActor, UniqueDeltaSinceProcessStart);
	DOREPLIFETIME(AFortServerDebugActor, UniqueDeltaSinceDebugStart);
}
