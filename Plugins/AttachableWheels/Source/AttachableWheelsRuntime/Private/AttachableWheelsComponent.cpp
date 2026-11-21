// Copyright Epic Games, Inc. All Rights Reserved.

#include "AttachableWheelsComponent.h"

int32 UAttachableWheelsComponent::DetachAllWheels()
{
	return int32();
}

void UAttachableWheelsComponent::DrawDebug() const
{
}

AAttachableWheel* UAttachableWheelsComponent::GetAttachedWheelClosestOnAxis(const FVector& Point, float& OutClosetDistanceToAxis, FVector& OutClosestPointOnAxis, FVector& OutClosestAxis) const
{
	return nullptr;
}

TArray<AAttachableWheel*> UAttachableWheelsComponent::GetAttachedWheels() const
{
	return TArray<AAttachableWheel*>();
}

bool UAttachableWheelsComponent::HandleWheelAttached_Internal(AAttachableWheel* AttachedWheel)
{
	return false;
}

bool UAttachableWheelsComponent::HandleWheelDetached_Internal(AAttachableWheel* AttachedWheel)
{
	return false;
}
