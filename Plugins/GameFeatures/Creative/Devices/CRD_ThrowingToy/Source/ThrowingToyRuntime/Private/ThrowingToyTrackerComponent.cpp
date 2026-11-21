// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThrowingToyTrackerComponent.h"
#include "Net/UnrealNetwork.h"

void UThrowingToyTrackerComponent::AddThrowingToy(AActor* ThrowingToyActor, const FGuid& WorldItemGuid)
{
}

AActor* UThrowingToyTrackerComponent::GetAndReleaseThrowingToy(const FGuid& WorldItemGuid)
{
	return nullptr;
}

EThrowingToyItemRemovedReason UThrowingToyTrackerComponent::GetRecentThrowingToyItemRemovedReason()
{
	return EThrowingToyItemRemovedReason();
}

AActor* UThrowingToyTrackerComponent::GetThrowingToy(const FGuid& WorldItemGuid)
{
	return nullptr;
}

void UThrowingToyTrackerComponent::SetRecentThrowingToyItemRemovedReason(EThrowingToyItemRemovedReason RemovedReason)
{
}

void UThrowingToyTrackerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UThrowingToyTrackerComponent, ThrowingToysData);
}
