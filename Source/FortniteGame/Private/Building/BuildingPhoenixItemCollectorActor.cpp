// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingPhoenixItemCollectorActor.h"
#include "Net/UnrealNetwork.h"

bool ABuildingPhoenixItemCollectorActor::GetActiveOutputRecipe(FRecipe& OutRecipe) const
{
	return false;
}

int32 ABuildingPhoenixItemCollectorActor::GetOutputRewardLevel() const
{
	return int32();
}

EFortRarity ABuildingPhoenixItemCollectorActor::GetOutputRewardRarity() const
{
	return EFortRarity();
}

void ABuildingPhoenixItemCollectorActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingPhoenixItemCollectorActor, OutputItemRecipes);
}
