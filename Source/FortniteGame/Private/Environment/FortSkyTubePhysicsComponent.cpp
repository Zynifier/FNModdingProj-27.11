// Copyright Epic Games, Inc. All Rights Reserved.

#include "Environment/FortSkyTubePhysicsComponent.h"
#include "Net/UnrealNetwork.h"

UFortSkyTubePhysicsComponent::UFortSkyTubePhysicsComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortSkyTubePhysicsComponent::ComputeAccelerations(const float DeltaTime, UPrimitiveComponent* PrimComp, FVector& OutLinearAcceleration, FVector& OutAngularAccelerationRad)
{
}

void UFortSkyTubePhysicsComponent::EnterSkyTube(AFortSkyTube* InSkyTube)
{
}

void UFortSkyTubePhysicsComponent::ExitSkyTube(AFortSkyTube* InSkyTube)
{
}

bool UFortSkyTubePhysicsComponent::IsInSkyTube() const
{
	return false;
}

bool UFortSkyTubePhysicsComponent::IsMagnetized() const
{
	return false;
}

bool UFortSkyTubePhysicsComponent::IsSkyTubeForceEnabled() const
{
	return false;
}

void UFortSkyTubePhysicsComponent::OnRep_Magnetized(bool bPreviousMagnetized)
{
}

void UFortSkyTubePhysicsComponent::OnRep_SkyTube(AFortSkyTube* PreviousSkyTube)
{
}

void UFortSkyTubePhysicsComponent::SetMagnetization(const bool bInMagnetized)
{
}

void UFortSkyTubePhysicsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortSkyTubePhysicsComponent, SkyTube);
	DOREPLIFETIME(UFortSkyTubePhysicsComponent, bMagnetized);
}
