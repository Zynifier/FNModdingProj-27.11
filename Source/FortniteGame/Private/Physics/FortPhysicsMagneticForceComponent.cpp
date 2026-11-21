// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsMagneticForceComponent.h"
#include "Net/UnrealNetwork.h"

UFortPhysicsMagneticForceComponent::UFortPhysicsMagneticForceComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortPhysicsMagneticForceComponent::BeginMagneticForce(const float Magnitude, const float DistanceFallOffBias, const float DistanceFallOffExponent, const bool bShouldAffectOwner, const bool bAtLocation, const FVector Location, const bool bLocationIsRelative, const UTargetingPreset* TargetingPreset, FPhysicsMagneticForceHandle& OutHandle)
{
}

void UFortPhysicsMagneticForceComponent::EndAllMagneticForces()
{
}

void UFortPhysicsMagneticForceComponent::EndMagneticForce(FPhysicsMagneticForceHandle& Handle)
{
}

void UFortPhysicsMagneticForceComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPhysicsMagneticForceComponent, ForcesToApply);
}
