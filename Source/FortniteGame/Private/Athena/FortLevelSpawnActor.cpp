// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortLevelSpawnActor.h"
#include "Net/UnrealNetwork.h"

void AFortLevelSpawnActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortLevelSpawnActor, SpecialActorID);
}
