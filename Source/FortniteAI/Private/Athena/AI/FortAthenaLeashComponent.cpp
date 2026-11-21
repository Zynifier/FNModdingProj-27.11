// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaLeashComponent.h"

const FVector& UFortAthenaLeashComponent::GetLeashCenter() const
{
	static FVector Dummy;
	return Dummy;
}

float UFortAthenaLeashComponent::GetLeashRadius() const
{
	return float();
}

bool UFortAthenaLeashComponent::IsInsideLeash(const FVector& Location) const
{
	return false;
}

void UFortAthenaLeashComponent::SetLeashRadius(float NewRadius)
{
}
