// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutatorUtilities.h"

void UFortAthenaMutatorUtilities::AdjustRespawnLocationForGroundHeight(FVector& InOutRespawnLocation, float MinRespawnHeightAboveGround, const AActor* WorldContextActor)
{
}

void UFortAthenaMutatorUtilities::ApplyActorOptionsComponentToDataRegistry(const UObject* WorldContextObject, const UFortActorOptionsComponent* FortActorOptionsComponent)
{
}

void UFortAthenaMutatorUtilities::RemoveDataRegistryOptionsForContextObject(const UObject* WorldContextObject)
{
}

void UFortAthenaMutatorUtilities::SetPlayerPortraitInMaterial(const AFortPlayerStateAthena* Player, UMaterialInstanceDynamic* Material, FName MaterialParam)
{
}

bool UFortAthenaMutatorUtilities::SphereTraceForParachuteLandingGeometry(FHitResult& OutHit, const UObject* WorldContextObject, const FVector& InLocation, float TraceStartZ, float TraceEndZ, float TraceSphereRadius)
{
	return false;
}
