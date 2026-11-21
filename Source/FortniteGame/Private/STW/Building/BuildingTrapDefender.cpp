// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/Building/BuildingTrapDefender.h"
#include "Net/UnrealNetwork.h"

FText ABuildingTrapDefender::GetLastInteractErrorText()
{
	return FText();
}

AFortAIPawn* ABuildingTrapDefender::SpawnDefenderfromItem(UFortAccountItem* DefenderItem, const FName& DefenderSquadId, const FTransform& SpawnTransform, AActor* InOwner)
{
	return nullptr;
}

void ABuildingTrapDefender::SupplyDefender(const UFortWorldItem* WeaponToGive, const int32 AmmoQuantity)
{
}

UFortWorldItem* ABuildingTrapDefender::TakeWeaponAwayFromDefender(UFortWorldItem* WeaponToTakeAway)
{
	return nullptr;
}

void ABuildingTrapDefender::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingTrapDefender, DefenderPawn);
	DOREPLIFETIME(ABuildingTrapDefender, DefenderItemDefinition);
	DOREPLIFETIME(ABuildingTrapDefender, DefenderItemLevel);
}
