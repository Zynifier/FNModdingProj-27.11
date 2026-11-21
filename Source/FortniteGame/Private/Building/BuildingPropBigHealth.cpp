// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingPropBigHealth.h"
#include "Net/UnrealNetwork.h"

float ABuildingPropBigHealth::GetHealthValuePercent()
{
	return float();
}

FText ABuildingPropBigHealth::GetHealthValueText()
{
	return FText();
}

void ABuildingPropBigHealth::OnRep_BigHealth()
{
}

void ABuildingPropBigHealth::SetBigHealth(int64 NewHealth)
{
}

void ABuildingPropBigHealth::SetBigHealthMax(int64 NewHealth)
{
}

void ABuildingPropBigHealth::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingPropBigHealth, BigHealth);
	DOREPLIFETIME(ABuildingPropBigHealth, BigHealthMax);
}
