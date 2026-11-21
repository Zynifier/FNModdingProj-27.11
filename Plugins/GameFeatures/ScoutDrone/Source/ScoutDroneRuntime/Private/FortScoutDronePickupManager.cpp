// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortScoutDronePickupManager.h"
#include "Net/UnrealNetwork.h"

UFortScoutDronePickupManager::UFortScoutDronePickupManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortScoutDronePickupManager::HasAnyAttachedActors() const
{
	return false;
}

bool UFortScoutDronePickupManager::HasAPawnAtached() const
{
	return false;
}

void UFortScoutDronePickupManager::OnAttachedPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortScoutDronePickupManager::OnPawnDBNOStateChanged(AFortPawn* Pawn, bool bIsDBNO)
{
}

void UFortScoutDronePickupManager::OnRep_AttachedTargets()
{
}

void UFortScoutDronePickupManager::ServerDropAttachedActors_Implementation()
{
}

void UFortScoutDronePickupManager::ServerUpdateItemAttachment_Implementation(FVector CalculatedItemOffset)
{
}

void UFortScoutDronePickupManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortScoutDronePickupManager, AttachedTargets);
}
