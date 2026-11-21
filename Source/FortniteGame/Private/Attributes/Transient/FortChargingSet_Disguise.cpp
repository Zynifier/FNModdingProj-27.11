// Copyright Epic Games, Inc. All Rights Reserved.

#include "Attributes/Transient/FortChargingSet_Disguise.h"
#include "Net/UnrealNetwork.h"

void UFortChargingSet_Disguise::OnRep_Charge(const FFortGameplayAttributeData& OldValue)
{
}

void UFortChargingSet_Disguise::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortChargingSet_Disguise, Charge);
	DOREPLIFETIME(UFortChargingSet_Disguise, MaxCharge);
	DOREPLIFETIME(UFortChargingSet_Disguise, ChargeRate);
	DOREPLIFETIME(UFortChargingSet_Disguise, ServerTimeChargeIncrements);
}
