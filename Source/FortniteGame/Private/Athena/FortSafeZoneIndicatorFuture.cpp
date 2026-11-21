// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortSafeZoneIndicatorFuture.h"
#include "Net/UnrealNetwork.h"

void AFortSafeZoneIndicatorFuture::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortSafeZoneIndicatorFuture, NextNextCenter);
	DOREPLIFETIME(AFortSafeZoneIndicatorFuture, NextNextRadius);
}
