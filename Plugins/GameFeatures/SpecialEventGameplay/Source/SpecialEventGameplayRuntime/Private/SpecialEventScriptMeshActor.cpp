// Copyright Epic Games, Inc. All Rights Reserved.

#include "SpecialEventScriptMeshActor.h"
#include "Net/UnrealNetwork.h"

void ASpecialEventScriptMeshActor::MeshRootClearCalendarTimer()
{
}

void ASpecialEventScriptMeshActor::MeshRootLogCalendarTimer()
{
}

void ASpecialEventScriptMeshActor::MeshRootResetEvent()
{
}

void ASpecialEventScriptMeshActor::MeshRootStartCalendarTimer()
{
}

void ASpecialEventScriptMeshActor::MeshRootStartCalendarTimerOnly()
{
}

void ASpecialEventScriptMeshActor::MeshRootStartEvent()
{
}

void ASpecialEventScriptMeshActor::OnRep_RootStartTime()
{
}

void ASpecialEventScriptMeshActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ASpecialEventScriptMeshActor, RootStartTime);
}
