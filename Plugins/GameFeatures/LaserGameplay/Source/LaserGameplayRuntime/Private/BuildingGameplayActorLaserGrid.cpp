// Copyright Epic Games, Inc. All Rights Reserved.

#include "BuildingGameplayActorLaserGrid.h"
#include "Net/UnrealNetwork.h"

bool ABuildingGameplayActorLaserGrid::CanActorTriggerLaserGrid_Implementation(const AActor* TriggeringActor) const
{
	return false;
}

void ABuildingGameplayActorLaserGrid::GetActiveLaserGridConnections(TArray<FLaserGridConnectionEntry>& OutActiveLaserGridConnections) const
{
}

void ABuildingGameplayActorLaserGrid::HandleAttachedBuildingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum)
{
}

void ABuildingGameplayActorLaserGrid::HandleLaserCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABuildingGameplayActorLaserGrid::HandlePatternTimerComplete_PostTransition()
{
}

void ABuildingGameplayActorLaserGrid::HandlePatternTimerComplete_PreTransition()
{
}

void ABuildingGameplayActorLaserGrid::OnRep_bEnabled()
{
}

void ABuildingGameplayActorLaserGrid::OnRep_LaserGridConnections()
{
}

void ABuildingGameplayActorLaserGrid::SetLaserGridEnable(const bool bEnable)
{
}

void ABuildingGameplayActorLaserGrid::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorLaserGrid, LaserGridConnections);
	DOREPLIFETIME(ABuildingGameplayActorLaserGrid, LaserGridOutlets);
	DOREPLIFETIME(ABuildingGameplayActorLaserGrid, bEnabled);
}
