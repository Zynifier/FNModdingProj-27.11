// Copyright Epic Games, Inc. All Rights Reserved.

#include "AudioShapeLineListComponent.h"

int32 UAudioShapeLineListComponent::AddPoint(const FVector& InPoint)
{
	return int32();
}

void UAudioShapeLineListComponent::GetPoints(TArray<FVector>& OutPoints) const
{
}

bool UAudioShapeLineListComponent::RemovePoint(int32 InIndex)
{
	return false;
}

bool UAudioShapeLineListComponent::UpdatePoint(int32 InIndex, const FVector& InPoint)
{
	return false;
}
