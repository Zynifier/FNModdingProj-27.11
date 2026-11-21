// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPhysicsChainWeaponComponent.h"
#include "Net/UnrealNetwork.h"

void UFortPhysicsChainWeaponComponent::EstablishChainConnectionPoint(UPrimitiveComponent* RootPoint, UPrimitiveComponent* GCComponent, const FVector& AttachPosition, const FVector& AttachPointNormal)
{
}

FVector UFortPhysicsChainWeaponComponent::GetChainConnectionPoint()
{
	return FVector();
}

float UFortPhysicsChainWeaponComponent::GetChainLinkMeshLength()
{
	return float();
}

bool UFortPhysicsChainWeaponComponent::GetCreateChainBool()
{
	return false;
}

int32 UFortPhysicsChainWeaponComponent::GetMaxChainLength()
{
	return int32();
}

void UFortPhysicsChainWeaponComponent::SetCreateChainBool(bool bSetCreateChain)
{
}

void UFortPhysicsChainWeaponComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPhysicsChainWeaponComponent, bCreateChain);
	DOREPLIFETIME(UFortPhysicsChainWeaponComponent, CurrentAttachPoint);
}
