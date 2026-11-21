// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeTeleporter.h"

bool AFortCreativeTeleporter::IsLocationBlocked(const AActor* ActorToTeleport, FVector LocationToTeleport, const FRotator& InPawnTeleportedRotation) const
{
	return false;
}

bool AFortCreativeTeleporter::IsPortalDebuggingEnabled() const
{
	return false;
}

bool AFortCreativeTeleporter::IsTeleporterBlocked(const AActor* ActorToTeleport, const FRotator& InPawnTeleportedRotation) const
{
	return false;
}
