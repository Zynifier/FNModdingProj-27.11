// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortCosmeticLoadoutComponent.h"
#include "Net/UnrealNetwork.h"

const FCosmeticLoadout& UFortCosmeticLoadoutComponent::GetCosmeticLoadout() const
{
	static FCosmeticLoadout Dummy;
	return Dummy;
}

void UFortCosmeticLoadoutComponent::OnRep_CosmeticLoadout()
{
}

void UFortCosmeticLoadoutComponent::SetCosmeticLoadout(const FCosmeticLoadout& NewCosmeticLoadout)
{
}

void UFortCosmeticLoadoutComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCosmeticLoadoutComponent, CosmeticLoadout);
}
