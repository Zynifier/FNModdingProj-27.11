// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingTrapFloor_Turret.h"
#include "Net/UnrealNetwork.h"

void ABuildingTrapFloor_Turret::ActivateTurret()
{
}

void ABuildingTrapFloor_Turret::AddOverlapComponent(UPrimitiveComponent* OverlapComponent)
{
}

void ABuildingTrapFloor_Turret::BindTimers()
{
}

void ABuildingTrapFloor_Turret::ConsumeAmmo()
{
}

void ABuildingTrapFloor_Turret::DeactivateTurret()
{
}

void ABuildingTrapFloor_Turret::FinishReload()
{
}

void ABuildingTrapFloor_Turret::FireTurret()
{
}

AFortPlayerPawn* ABuildingTrapFloor_Turret::GetClosestTarget()
{
	return nullptr;
}

AFortPawn* ABuildingTrapFloor_Turret::GetTarget()
{
	return nullptr;
}

void ABuildingTrapFloor_Turret::MinigameEnded()
{
}

void ABuildingTrapFloor_Turret::MinigameStarted()
{
}

void ABuildingTrapFloor_Turret::OnEnterTurretRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ABuildingTrapFloor_Turret::OnLeaveTurretRange(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ABuildingTrapFloor_Turret::OnRep_CurrentlyActive()
{
}

void ABuildingTrapFloor_Turret::PerformGunRotation(const AFortPawn* TargetActor, const FVector& AimLocation, const FRotator& CurrentRotation, USceneComponent* RotateComponent)
{
}

void ABuildingTrapFloor_Turret::RotateTurretClient()
{
}

void ABuildingTrapFloor_Turret::RotateTurretServer()
{
}

void ABuildingTrapFloor_Turret::SetTarget(AFortPawn* NewTarget)
{
}

void ABuildingTrapFloor_Turret::UnbindTimers()
{
}

void ABuildingTrapFloor_Turret::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingTrapFloor_Turret, Target);
	DOREPLIFETIME(ABuildingTrapFloor_Turret, CurrentRotationalSpeed);
	DOREPLIFETIME(ABuildingTrapFloor_Turret, bCurrentlyActive);
	DOREPLIFETIME(ABuildingTrapFloor_Turret, ShootLocation);
	DOREPLIFETIME(ABuildingTrapFloor_Turret, bIsSearching);
}
