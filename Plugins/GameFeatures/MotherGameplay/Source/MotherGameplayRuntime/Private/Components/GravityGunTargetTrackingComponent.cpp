// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/GravityGunTargetTrackingComponent.h"

void UGravityGunTargetTrackingComponent::FindTargetActor(AActor* OwningPlayer, const FVector& TraceStart, const FVector& TraceEnd)
{
}

bool UGravityGunTargetTrackingComponent::FindTargetProjectile(AActor* OwningPlayer, const FVector& TraceStart, const FVector& TraceEnd, float TargetingRadius)
{
	return false;
}

bool UGravityGunTargetTrackingComponent::IsValidTarget(AActor* OwningPlayer, AActor* PotentialTarget, FGameplayTagContainer& ReasonForFailure)
{
	return false;
}
