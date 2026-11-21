// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaAircraft.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaAircraft::EjectPlayersInAircraft()
{
}

float AFortAthenaAircraft::GetDropEndTime() const
{
	return float();
}

float AFortAthenaAircraft::GetDropStartTime() const
{
	return float();
}

void AFortAthenaAircraft::OnRep_ReplicatedFlightTimestamp()
{
}

AFortAthenaAircraft* AFortAthenaAircraft::SpawnAircraft(UWorld* World, TSubclassOf<AFortAthenaAircraft> AircraftClass, const FAircraftFlightInfo& InFlightInfo)
{
	return nullptr;
}

void AFortAthenaAircraft::StartFlightPath(float StartTime)
{
}

void AFortAthenaAircraft::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaAircraft, FlightInfo);
	DOREPLIFETIME(AFortAthenaAircraft, FlightStartTime);
	DOREPLIFETIME(AFortAthenaAircraft, FlightEndTime);
	DOREPLIFETIME(AFortAthenaAircraft, DropStartTime);
	DOREPLIFETIME(AFortAthenaAircraft, DropEndTime);
	DOREPLIFETIME(AFortAthenaAircraft, ReplicatedFlightTimestamp);
	DOREPLIFETIME(AFortAthenaAircraft, AircraftIndex);
}
