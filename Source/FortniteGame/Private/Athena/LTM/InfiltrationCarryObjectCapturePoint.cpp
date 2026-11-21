// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/InfiltrationCarryObjectCapturePoint.h"
#include "Net/UnrealNetwork.h"

void AInfiltrationCarryObjectCapturePoint::IntelTagCallback(const FGameplayTag Tag, int32 NewCount)
{
}

void AInfiltrationCarryObjectCapturePoint::MulticastIntelCaptured_Implementation()
{
}

void AInfiltrationCarryObjectCapturePoint::OnPawnBeginOverlap(AFortPlayerPawn* TouchingPawn)
{
}

void AInfiltrationCarryObjectCapturePoint::OnPawnEndOverlap(AFortPlayerPawn* TouchingPawn)
{
}

void AInfiltrationCarryObjectCapturePoint::OnRep_bCapturePointEnabled()
{
}

void AInfiltrationCarryObjectCapturePoint::StartUpdatingUIVisibility()
{
}

void AInfiltrationCarryObjectCapturePoint::StopUpdatingUIVisibility()
{
}

void AInfiltrationCarryObjectCapturePoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AInfiltrationCarryObjectCapturePoint, bCapturePointEnabled);
}
