// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Player/FortPlayerStateOutpost.h"
#include "Net/UnrealNetwork.h"

bool AFortPlayerStateOutpost::HasPermissionToEditOutpost() const
{
	return false;
}

bool AFortPlayerStateOutpost::IsOutpostOwner() const
{
	return false;
}

void AFortPlayerStateOutpost::OnRep_HasPermissionToEditOutpost()
{
}

void AFortPlayerStateOutpost::ServerSetHasPermissionToEditOutpost_Implementation(AFortPlayerStateOutpost* InPlayer, bool bHasPermission)
{
}
bool AFortPlayerStateOutpost::ServerSetHasPermissionToEditOutpost_Validate(AFortPlayerStateOutpost* InPlayer, bool bHasPermission)
{
	return true;
}

void AFortPlayerStateOutpost::SetHasPermissionToEditOutpost(AFortPlayerStateOutpost* InPlayer, bool bHasPermission)
{
}

void AFortPlayerStateOutpost::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerStateOutpost, bHasPermissionToEditOutpost);
}
