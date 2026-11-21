// Copyright Epic Games, Inc. All Rights Reserved.

#include "Movement/FortMovementComp_GroundSpline.h"
#include "Net/UnrealNetwork.h"

void UFortMovementComp_GroundSpline::ClientOnlySnapToServerLocationAndSpeed()
{
}

FGroundSplineSpeedData UFortMovementComp_GroundSpline::GetCurrentSpeeds() const
{
	return FGroundSplineSpeedData();
}

USplineComponent* UFortMovementComp_GroundSpline::GetSpline() const
{
	return nullptr;
}

float UFortMovementComp_GroundSpline::GetSplineDistance() const
{
	return float();
}

FGroundSplineSpeedData UFortMovementComp_GroundSpline::GetTargetSpeeds() const
{
	return FGroundSplineSpeedData();
}

bool UFortMovementComp_GroundSpline::GetTransformAtDistanceOnSpline(FTransform& OutTransform, float Distance) const
{
	return false;
}

void UFortMovementComp_GroundSpline::OnRep_ReplicatedSplineLocationData()
{
}

void UFortMovementComp_GroundSpline::OnRep_ReplicatedTargetSpeeds()
{
}

void UFortMovementComp_GroundSpline::SetAbilitySystemComponent(UAbilitySystemComponent* NewAbilitySystemComponent)
{
}

void UFortMovementComp_GroundSpline::SetSpline(USplineComponent* NewTravelSpline, float NewDistanceOnSpline)
{
}

void UFortMovementComp_GroundSpline::SetTargetSpeeds(const FGroundSplineSpeedData& NewTargetSpeeds)
{
}

void UFortMovementComp_GroundSpline::TeleportToDistanceOnSpline(USplineComponent* NewTravelSpline, float Distance)
{
}

void UFortMovementComp_GroundSpline::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMovementComp_GroundSpline, bTickGroundSplineMovement);
	DOREPLIFETIME(UFortMovementComp_GroundSpline, ReplicatedSplineLocationData);
	DOREPLIFETIME(UFortMovementComp_GroundSpline, ReplicatedTargetSpeeds);
}
