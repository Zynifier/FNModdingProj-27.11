// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAISystem.h"

UFortAISystem::UFortAISystem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

bool UFortAISystem::IsInCone2D(FVector ConeOrigin, FVector ConeDirection, float HalfAngle, FVector LocationToCheck)
{
	return false;
}
