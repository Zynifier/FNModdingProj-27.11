// Copyright Epic Games, Inc. All Rights Reserved.

#include "Vehicles/Components/FortVehiclePontoonsComponent.h"
#include "Net/UnrealNetwork.h"

UFortVehiclePontoonsComponent::UFortVehiclePontoonsComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortVehiclePontoonsComponent::OnRep_PontoonRadius(const TArray<float>& PrevPontoonRadiuses)
{
}

void UFortVehiclePontoonsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortVehiclePontoonsComponent, OverridePontoonRadiuses);
}
