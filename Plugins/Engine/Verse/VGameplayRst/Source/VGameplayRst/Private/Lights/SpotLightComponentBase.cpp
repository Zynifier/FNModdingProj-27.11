// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lights/SpotLightComponentBase.h"
#include "Net/UnrealNetwork.h"

void USpotLightComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(USpotLightComponentBase, ReplicatedLightProperties);
}
