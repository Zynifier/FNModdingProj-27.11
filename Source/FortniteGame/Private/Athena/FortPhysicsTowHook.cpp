// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPhysicsTowHook.h"
#include "Net/UnrealNetwork.h"

bool AFortPhysicsTowHook::GetEndPoint(FVector& OutEndPoint) const
{
	return false;
}

bool AFortPhysicsTowHook::GetStartPoint(FVector& OutStartPoint) const
{
	return false;
}

void AFortPhysicsTowHook::OnRep_ReplicatedAttachStates()
{
}

void AFortPhysicsTowHook::SetTowhookExtensionState(FTowhookExtensionState NewExtensionState)
{
}

void AFortPhysicsTowHook::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPhysicsTowHook, ReplicatedAttachStates);
}
