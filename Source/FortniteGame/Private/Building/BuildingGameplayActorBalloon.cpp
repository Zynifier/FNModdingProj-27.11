// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorBalloon.h"
#include "Net/UnrealNetwork.h"

void ABuildingGameplayActorBalloon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorBalloon, BalloonLocationSelection);
}
