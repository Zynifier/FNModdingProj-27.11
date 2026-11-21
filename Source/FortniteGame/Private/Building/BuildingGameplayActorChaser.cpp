// Copyright Epic Games, Inc. All Rights Reserved.

#include "Building/BuildingGameplayActorChaser.h"
#include "Net/UnrealNetwork.h"

void ABuildingGameplayActorChaser::AttachedToChaseTarget()
{
}

void ABuildingGameplayActorChaser::ChaseTargetDamaged()
{
}

void ABuildingGameplayActorChaser::DetachedFromChaseTarget()
{
}

void ABuildingGameplayActorChaser::EndForcedPlayerForwardMovement()
{
}

void ABuildingGameplayActorChaser::ForcePlayerForwardMovement(AFortPlayerPawn* Player, float MaxSpeedScale)
{
}

AActor* ABuildingGameplayActorChaser::GetChaseTarget()
{
	return nullptr;
}

bool ABuildingGameplayActorChaser::IsValidTarget(UObject* PotentialTarget)
{
	return false;
}

void ABuildingGameplayActorChaser::LookForNewTarget()
{
}

void ABuildingGameplayActorChaser::MulticastNetCullDistance_Implementation(float DistanceSquared)
{
}

void ABuildingGameplayActorChaser::OnRep_PatrolTurnData()
{
}

void ABuildingGameplayActorChaser::PotentialTargetFound(AActor* InDetectedItem)
{
}

void ABuildingGameplayActorChaser::RandomNewPatrolDestination()
{
}

void ABuildingGameplayActorChaser::SetChaseTarget_Implementation(AActor* InChaseTarget, bool bInHomeOnChaseTarget, float InTargetReachedDistanceOverride)
{
}

void ABuildingGameplayActorChaser::SetHealthBarMarkerPosition(float MarkerPosition)
{
}

void ABuildingGameplayActorChaser::ShouldCancelTargetSearch(bool& bShouldCancel)
{
}

void ABuildingGameplayActorChaser::StayAboveWater()
{
}

void ABuildingGameplayActorChaser::TargetSearchComplete(bool WasCancelled)
{
}

void ABuildingGameplayActorChaser::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABuildingGameplayActorChaser, PatrolTurnData);
}
