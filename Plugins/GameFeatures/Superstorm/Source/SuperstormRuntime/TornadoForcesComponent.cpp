// Copyright Epic Games, Inc. All Rights Reserved.

#include "TornadoForcesComponent.h"
#include "Net/UnrealNetwork.h"

UTempestTornadoForcesComponent::UTempestTornadoForcesComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UTempestTornadoForcesComponent::IsActorInTornado(AActor* Actor) const
{
	return false;
}

void UTempestTornadoForcesComponent::OnVehicleInTornadoPlayerExit(const AFortPlayerControllerAthena* PlayerController, AFortAthenaVehicle* Vehicle)
{
}

void UTempestTornadoForcesComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UTempestTornadoForcesComponent, ActorsToClientSimulate);
}
