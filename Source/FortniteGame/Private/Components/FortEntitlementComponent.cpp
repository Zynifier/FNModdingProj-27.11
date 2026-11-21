// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortEntitlementComponent.h"
#include "Net/UnrealNetwork.h"

void UFortEntitlementComponent::OnRep_Entitlements()
{
}

void UFortEntitlementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortEntitlementComponent, Entitlements);
}
