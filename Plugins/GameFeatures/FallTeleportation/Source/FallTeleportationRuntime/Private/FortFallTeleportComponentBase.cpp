// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortFallTeleportComponentBase.h"

bool UFortFallTeleportComponentBase::IsTeleportLocationValid(const FVector& LocationToTest) const
{
	return false;
}

bool UFortFallTeleportComponentBase::IsValidActorToTeleportOn(AActor* ActorToTeleportOn) const
{
	return false;
}

void UFortFallTeleportComponentBase::UpdateLastGroundLocation(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}
