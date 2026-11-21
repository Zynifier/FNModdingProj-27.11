// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortWeaponComponent_Subweapon.h"
#include "Net/UnrealNetwork.h"

void UFortWeaponComponent_Subweapon::HandleAimDownSightsChanged(const bool bIsADS)
{
}

void UFortWeaponComponent_Subweapon::OnRep_SubweaponData()
{
}

void UFortWeaponComponent_Subweapon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortWeaponComponent_Subweapon, SubweaponData);
}
