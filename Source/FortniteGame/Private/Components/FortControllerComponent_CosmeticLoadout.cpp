// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_CosmeticLoadout.h"
#include "Net/UnrealNetwork.h"

const FCosmeticLoadout& UFortControllerComponent_CosmeticLoadout::GetCosmeticLoadout() const
{
	static FCosmeticLoadout Dummy;
	return Dummy;
}

void UFortControllerComponent_CosmeticLoadout::OnRep_CosmeticLoadout()
{
}

void UFortControllerComponent_CosmeticLoadout::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_CosmeticLoadout, CosmeticLoadout);
}
