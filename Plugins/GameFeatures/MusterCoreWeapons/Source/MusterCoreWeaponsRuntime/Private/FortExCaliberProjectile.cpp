// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortExCaliberProjectile.h"
#include "Net/UnrealNetwork.h"

void AFortExCaliberProjectile::OnAttachedActorDestroyed(AActor* DestroyedActor)
{
}

void AFortExCaliberProjectile::OnAttachedBuildingDestroyed(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortExCaliberProjectile::OnRep_bSimulationRunning()
{
}

void AFortExCaliberProjectile::RestartSimulating()
{
}

void AFortExCaliberProjectile::SetupSwordRevealEffects(UStaticMeshComponent* ProjectileMesh, float SwordRevealAlpha, float ColorChangeAlpha, float HDRMultiplierAlpha)
{
}

void AFortExCaliberProjectile::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortExCaliberProjectile, bSimulationRunning);
}
