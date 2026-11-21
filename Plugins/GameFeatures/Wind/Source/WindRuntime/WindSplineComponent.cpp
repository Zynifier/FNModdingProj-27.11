// Copyright Epic Games, Inc. All Rights Reserved.

#include "WindSplineComponent.h"
#include "Net/UnrealNetwork.h"

void UWindSplineComponent::Disable()
{
}

void UWindSplineComponent::Enable()
{
}

void UWindSplineComponent::GetClosestActiveLocations(const FVector& InTargetLocation, bool& bIsClosestPointActive, FVector& ClosestPointOnSpline, TArray<FVector>& ClosestActiveLocations) const
{
}

float UWindSplineComponent::GetTargetingRadius() const
{
	return float();
}

void UWindSplineComponent::GetWindDataAtLocation(const FVector& InTargetLocation, FVector& OutDirection, float& OutAttenuation) const
{
}

void UWindSplineComponent::OnRep_Blockages()
{
}

void UWindSplineComponent::OnRep_TargetData()
{
}

void UWindSplineComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UWindSplineComponent, TargetData);
	DOREPLIFETIME(UWindSplineComponent, Blockages);
}
