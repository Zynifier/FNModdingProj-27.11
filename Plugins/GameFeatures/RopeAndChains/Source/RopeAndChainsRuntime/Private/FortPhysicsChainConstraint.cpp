// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPhysicsChainConstraint.h"
#include "Net/UnrealNetwork.h"

void AFortPhysicsChainConstraint::DestroyAttachPoint(AActor* DamagedActor)
{
}

void AFortPhysicsChainConstraint::DestroyAttachPointConstraint(bool bStart)
{
}

void AFortPhysicsChainConstraint::DestroyAttachPointConstraintForComponent(UPrimitiveComponent* DamagedComponent)
{
}

void AFortPhysicsChainConstraint::DestroyBuildingPoint(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void AFortPhysicsChainConstraint::DestroyGCBuildingPoint(const FChaosBreakEvent& BreakEvent)
{
}

bool AFortPhysicsChainConstraint::LandscapeCheck()
{
	return false;
}

void AFortPhysicsChainConstraint::OnPhysicsStateChange(UPrimitiveComponent* PrimitiveComponent, EComponentPhysicsStateChange StateChange)
{
}

void AFortPhysicsChainConstraint::OnRep_CreateChain()
{
}

void AFortPhysicsChainConstraint::OnRep_DestroyAttachPoint()
{
}

void AFortPhysicsChainConstraint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPhysicsChainConstraint, StartPointAttachData);
	DOREPLIFETIME(AFortPhysicsChainConstraint, EndPointAttachData);
	DOREPLIFETIME(AFortPhysicsChainConstraint, NumberOfLinks);
	DOREPLIFETIME(AFortPhysicsChainConstraint, ChainLinkMesh);
	DOREPLIFETIME(AFortPhysicsChainConstraint, bCreateChainOnClient);
	DOREPLIFETIME(AFortPhysicsChainConstraint, bDestroyAttachPointOnClient);
	DOREPLIFETIME(AFortPhysicsChainConstraint, bDestroyStart);
}
