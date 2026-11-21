// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/Components/FortVehicleSeatComponent.h"
#include "Net/UnrealNetwork.h"

FAthenaCarPlayerSlot UFortVehicleSeatComponent::BP_GetPlayerSlot(const int32 SeatIndex) const
{
	return FAthenaCarPlayerSlot();
}

const TArray<FAthenaCarPlayerSlot>& UFortVehicleSeatComponent::GetPlayerSlots() const
{
	static TArray<FAthenaCarPlayerSlot> Dummy;
	return Dummy;
}

void UFortVehicleSeatComponent::OnRep_PlayerSlots()
{
}

void UFortVehicleSeatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehicleSeatComponent, PlayerSlots);
}
