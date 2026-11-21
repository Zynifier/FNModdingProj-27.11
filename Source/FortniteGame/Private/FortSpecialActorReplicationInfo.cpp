// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSpecialActorReplicationInfo.h"
#include "Net/UnrealNetwork.h"

void AFortSpecialActorReplicationInfo::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSpecialActorReplicationInfo, SpecialActorRepList);
	DOREPLIFETIME(AFortSpecialActorReplicationInfo, SpecialActorTransforms);
	DOREPLIFETIME(AFortSpecialActorReplicationInfo, SlateBrushes);
	DOREPLIFETIME(AFortSpecialActorReplicationInfo, BrushScales);
}
