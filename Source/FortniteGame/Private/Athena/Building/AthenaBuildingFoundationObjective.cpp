// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Building/AthenaBuildingFoundationObjective.h"
#include "Net/UnrealNetwork.h"

void AAthenaBuildingFoundationObjective::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaBuildingFoundationObjective, CurrentHealth);
	DOREPLIFETIME(AAthenaBuildingFoundationObjective, MaxHealth);
}
