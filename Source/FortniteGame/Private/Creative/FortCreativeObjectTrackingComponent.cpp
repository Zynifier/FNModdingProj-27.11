// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeObjectTrackingComponent.h"
#include "Net/UnrealNetwork.h"

void UFortCreativeObjectTrackingComponent::ServerSetPreviewLocation_Implementation(bool bPreviewActive, const FVector& Location)
{
}

void UFortCreativeObjectTrackingComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeObjectTrackingComponent, bUpdatePreviewLocation);
}
