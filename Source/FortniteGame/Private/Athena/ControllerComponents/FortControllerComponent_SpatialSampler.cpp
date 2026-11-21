// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/ControllerComponents/FortControllerComponent_SpatialSampler.h"
#include "Net/UnrealNetwork.h"

bool UFortControllerComponent_SpatialSampler::BeginSpatialSampling()
{
	return false;
}

void UFortControllerComponent_SpatialSampler::ClientTeleportedToNextSamplingLocation_Implementation(const FVector& Location)
{
}

void UFortControllerComponent_SpatialSampler::EndSpatialSampling()
{
}

void UFortControllerComponent_SpatialSampler::ServerAddSamplingLocation_Implementation(const FVector& Location)
{
}

void UFortControllerComponent_SpatialSampler::ServerAddSamplingLocations_Implementation(const TArray<FVector>& Locations)
{
}

void UFortControllerComponent_SpatialSampler::ServerBeginSpatialSampling_Implementation()
{
}

void UFortControllerComponent_SpatialSampler::ServerEndSpatialSampling_Implementation()
{
}

void UFortControllerComponent_SpatialSampler::ServerRegisterOnSamplingLocationChangedHandleID_Implementation(const uint64 ID)
{
}

void UFortControllerComponent_SpatialSampler::ServerReleaseSamplingLocation_Implementation()
{
}

void UFortControllerComponent_SpatialSampler::ServerRemoveAllSamplingLocations_Implementation()
{
}

void UFortControllerComponent_SpatialSampler::ServerUnregisterOnSamplingLocationChangedHandleID_Implementation(const uint64 ID)
{
}

void UFortControllerComponent_SpatialSampler::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_SpatialSampler, NumPendingSamplingLocations);
	DOREPLIFETIME(UFortControllerComponent_SpatialSampler, bIsSampling);
}
