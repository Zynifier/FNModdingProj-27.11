// Copyright Epic Games, Inc. All Rights Reserved.

#include "Physics/FortPhysicsConstantForceComponent.h"
#include "Net/UnrealNetwork.h"

UFortPhysicsConstantForceComponent::UFortPhysicsConstantForceComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortPhysicsConstantForceComponent::BeginConstantForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, FName BoneName, FPhysicsConstantForceHandle& OutHandle)
{
}

void UFortPhysicsConstantForceComponent::BeginForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, bool bChangeForceOverDist, bool bApplyDrag, FName BoneName, FPhysicsConstantForceHandle& OutHandle, FVector ForceReductionNormal, float Start, float End, float DragCoeff, float DragAreaApproximation, AActor* RootActor, AActor* Origin)
{
}

void UFortPhysicsConstantForceComponent::BeginZVariableForce(FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, bool bApplyDrag, bool bReduceForceOverDistZ, FName BoneName, FPhysicsConstantForceHandle& OutHandle, float Start, float End, float DragCoeff, float DragAreaApproximation)
{
}

void UFortPhysicsConstantForceComponent::EndAllConstantForces()
{
}

void UFortPhysicsConstantForceComponent::EndConstantForce(FPhysicsConstantForceHandle& Handle)
{
}

void UFortPhysicsConstantForceComponent::ModifyConstantForce(const FPhysicsConstantForceHandle& Handle, FVector Force, bool bForceIsRelative, bool bAtLocation, FVector Location, bool bLocationIsRelative, bool bVelocityChange, FName BoneName)
{
}

void UFortPhysicsConstantForceComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPhysicsConstantForceComponent, bActivateFortPhysicsObjectOnBeginConstantForce);
	DOREPLIFETIME(UFortPhysicsConstantForceComponent, ForcesToApply);
}
