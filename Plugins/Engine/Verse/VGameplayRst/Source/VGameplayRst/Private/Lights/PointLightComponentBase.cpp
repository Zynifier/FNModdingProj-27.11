// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lights/PointLightComponentBase.h"
#include "Net/UnrealNetwork.h"

void UPointLightComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPointLightComponentBase, ReplicatedLightProperties);
}
