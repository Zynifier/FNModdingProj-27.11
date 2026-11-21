// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_AutoPickup.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_AutoPickup::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupDefaultItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupAmmoItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupConsumableItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupGadgetItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupTrapItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupWeaponItems);
	DOREPLIFETIME(AFortAthenaMutator_AutoPickup, AutoPickupWorldResourceItems);
}
