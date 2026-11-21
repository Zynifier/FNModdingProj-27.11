// Copyright Epic Games, Inc. All Rights Reserved.

#include "Targeting/TargetingFilterTask_ObstructedByWorld.h"

UTargetingFilterTask_ObstructedByWorld::UTargetingFilterTask_ObstructedByWorld(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FVector UTargetingFilterTask_ObstructedByWorld::GetSourceLocation_Implementation(const FTargetingRequestHandle& TargetingHandle) const
{
	return FVector();
}

FVector UTargetingFilterTask_ObstructedByWorld::GetSourceOffset_Implementation(const FTargetingRequestHandle& TargetingHandle) const
{
	return FVector();
}
