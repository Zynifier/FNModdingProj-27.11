// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortLOSComponent.h"
#include "Net/UnrealNetwork.h"

void UFortLOSComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortLOSComponent, bHasBeenFound);
}
