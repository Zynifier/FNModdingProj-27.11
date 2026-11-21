// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortProjectileAthena.h"
#include "Net/UnrealNetwork.h"

void AFortProjectileAthena::KillAfterNoPawnHit()
{
}

void AFortProjectileAthena::OnOwnerDestroyed(AActor* DestroyedOwner)
{
}

void AFortProjectileAthena::OnRep_FireStart()
{
}

void AFortProjectileAthena::OnRep_PawnHitResult()
{
}

void AFortProjectileAthena::ServerNotifyAutoKillDistanceExceeded_Implementation()
{
}

void AFortProjectileAthena::ServerNotifyEndOverlap_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
}
bool AFortProjectileAthena::ServerNotifyEndOverlap_Validate(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
	return true;
}

void AFortProjectileAthena::ServerNotifyPawnHit_Implementation(FHitResult Hit, const TArray<uint8>& Context)
{
}
bool AFortProjectileAthena::ServerNotifyPawnHit_Validate(FHitResult Hit, const TArray<uint8>& Context)
{
	return true;
}

void AFortProjectileAthena::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortProjectileAthena, FireStartLoc);
	DOREPLIFETIME(AFortProjectileAthena, PawnHitResult);
}
