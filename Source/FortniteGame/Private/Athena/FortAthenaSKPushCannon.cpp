// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortAthenaSKPushCannon.h"
#include "Net/UnrealNetwork.h"

FRotator AFortAthenaSKPushCannon::GetCurrentWorldAimOrientationCorrected() const
{
	return FRotator();
}

void AFortAthenaSKPushCannon::MultiCastPushCannonLaunchedPlayer_Implementation()
{
}

void AFortAthenaSKPushCannon::ServerSetPassengerTorquing_Implementation(bool bSetTo)
{
}
bool AFortAthenaSKPushCannon::ServerSetPassengerTorquing_Validate(bool bSetTo)
{
	return true;
}

void AFortAthenaSKPushCannon::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaSKPushCannon, bPlayerTorquingRepped);
}
