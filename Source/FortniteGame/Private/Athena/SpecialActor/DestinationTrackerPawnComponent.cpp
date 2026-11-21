// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/DestinationTrackerPawnComponent.h"
#include "Net/UnrealNetwork.h"

UDestinationTrackerPawnComponent::UDestinationTrackerPawnComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UDestinationTrackerPawnComponent::ClearDestination()
{
}

const FVector& UDestinationTrackerPawnComponent::GetDestination() const
{
	static FVector Dummy;
	return Dummy;
}

const FRotator& UDestinationTrackerPawnComponent::GetDirection() const
{
	static FRotator Dummy;
	return Dummy;
}

float UDestinationTrackerPawnComponent::GetDistanceSquared() const
{
	return float();
}

bool UDestinationTrackerPawnComponent::HasDestination() const
{
	return false;
}

void UDestinationTrackerPawnComponent::OnRep_Destination()
{
}

void UDestinationTrackerPawnComponent::SetDestination(const FVector& InDestination)
{
}

void UDestinationTrackerPawnComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UDestinationTrackerPawnComponent, Destination);
}
