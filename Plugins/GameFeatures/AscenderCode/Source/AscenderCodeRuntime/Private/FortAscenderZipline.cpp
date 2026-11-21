// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAscenderZipline.h"
#include "Net/UnrealNetwork.h"

UPrimitiveComponent* AFortAscenderZipline::GetInteractComponentOverride_Implementation(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const
{
	return nullptr;
}

AFortPlayerPawn* AFortAscenderZipline::GetPawnUsingHandle() const
{
	return nullptr;
}

void AFortAscenderZipline::HandleFloorActorDestroyed(AActor* Actor)
{
}

void AFortAscenderZipline::HandleFloorActorHealthChanged()
{
}

void AFortAscenderZipline::HandlePawnUsingHandleDied(AFortPawn* DeadPawn)
{
}

void AFortAscenderZipline::OnRep_InitialSplineEndLocation()
{
}

void AFortAscenderZipline::OnRep_PawnUsingHandle()
{
}

void AFortAscenderZipline::OnRep_TargetSplineEndLocation()
{
}

void AFortAscenderZipline::SetupAscender(const bool bFromConstruction, const bool bFromReplication)
{
}

void AFortAscenderZipline::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAscenderZipline, InitialSplineEndLocation);
	DOREPLIFETIME(AFortAscenderZipline, TargetSplineEndLocation);
	DOREPLIFETIME(AFortAscenderZipline, PawnUsingHandle);
}
