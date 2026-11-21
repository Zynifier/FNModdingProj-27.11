// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerPushableCart.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerPushableCart::AddPlayerToPushArea(AFortPlayerPawn* PlayerToAdd)
{
}

AActor* AFortPlayerPushableCart::GetCameraActor_Implementation()
{
	return nullptr;
}

float AFortPlayerPushableCart::GetCartDistanceAlongSpline() const
{
	return float();
}

void AFortPlayerPushableCart::GetCheckPointTransforms(TArray<FTransform>& OutTransforms) const
{
}

uint8 AFortPlayerPushableCart::GetDefenderTeam() const
{
	return uint8();
}

float AFortPlayerPushableCart::GetDesiredSpeed() const
{
	return float();
}

float AFortPlayerPushableCart::GetDistanceToNextCheckPoint() const
{
	return float();
}

bool AFortPlayerPushableCart::GetIsPlayerPushable() const
{
	return false;
}

uint8 AFortPlayerPushableCart::GetLastReachedCheckPointIndex() const
{
	return uint8();
}

uint8 AFortPlayerPushableCart::GetNextCheckPointIndex() const
{
	return uint8();
}

float AFortPlayerPushableCart::GetPercentProgressTowardsNextCheckPoint() const
{
	return float();
}

UShapeComponent* AFortPlayerPushableCart::GetPushAreaShapeComponent_Implementation() const
{
	return nullptr;
}

uint8 AFortPlayerPushableCart::GetPusherTeam() const
{
	return uint8();
}

int32 AFortPlayerPushableCart::GetPushingStrength() const
{
	return int32();
}

float AFortPlayerPushableCart::GetSplineDistanceAtCheckPoint(int32 CheckPointIndex) const
{
	return float();
}

int32 AFortPlayerPushableCart::GetSplineIndexForCurrentCheckPoint() const
{
	return int32();
}

int32 AFortPlayerPushableCart::GetSplineIndexForNextCheckPoint() const
{
	return int32();
}

uint8 AFortPlayerPushableCart::GetTotalActiveDefenders() const
{
	return uint8();
}

uint8 AFortPlayerPushableCart::GetTotalActivePushers() const
{
	return uint8();
}

int32 AFortPlayerPushableCart::GetTotalCheckPoints() const
{
	return int32();
}

void AFortPlayerPushableCart::GetTransformAtCheckPoint(FTransform& OutTransform, int32 CheckPointIndex) const
{
}

bool AFortPlayerPushableCart::IsCartContested() const
{
	return false;
}

bool AFortPlayerPushableCart::IsNearCheckpoint()
{
	return false;
}

void AFortPlayerPushableCart::OnRep_bIsNearCheckpoint()
{
}

void AFortPlayerPushableCart::OnRep_CurrentCheckpoint()
{
}

void AFortPlayerPushableCart::OnRep_TeamRoles()
{
}

void AFortPlayerPushableCart::OnRep_TotalActiveDefenders()
{
}

void AFortPlayerPushableCart::OnRep_TotalActivePushers()
{
}

void AFortPlayerPushableCart::OnSplinePointReached(int32 SplinePointReached, bool bWasMovingForward)
{
}

void AFortPlayerPushableCart::RemovePlayerFromPushArea(AFortPlayerPawn* PlayerToRemove)
{
}

void AFortPlayerPushableCart::SetNearCheckpoint(bool bNear)
{
}

void AFortPlayerPushableCart::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerPushableCart, SplineComponent);
	DOREPLIFETIME(AFortPlayerPushableCart, SplineCheckPointIndices);
	DOREPLIFETIME(AFortPlayerPushableCart, CurrentCheckPoint);
	DOREPLIFETIME(AFortPlayerPushableCart, TeamRoles);
	DOREPLIFETIME(AFortPlayerPushableCart, TotalActivePushers);
	DOREPLIFETIME(AFortPlayerPushableCart, TotalActiveDefenders);
	DOREPLIFETIME(AFortPlayerPushableCart, bIsPushable);
	DOREPLIFETIME(AFortPlayerPushableCart, bIsNearCheckpoint);
}
