// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortPlayerParachute.h"
#include "Net/UnrealNetwork.h"

void AFortPlayerParachute::ApplyVariants()
{
}

void AFortPlayerParachute::DisableTrailParticles()
{
}

TArray<USkeletalMeshComponentBudgeted*> AFortPlayerParachute::GetBitsMeshComponents() const
{
	return TArray<USkeletalMeshComponentBudgeted*>();
}

AFortPlayerPawn* AFortPlayerParachute::GetFortPlayerPawn() const
{
	return nullptr;
}

USkeletalMeshComponent* AFortPlayerParachute::GetParachuteRootMesh() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerParachute::GetTrailVFX2Component() const
{
	return nullptr;
}

UFXSystemComponent* AFortPlayerParachute::GetTrailVFXComponent() const
{
	return nullptr;
}

void AFortPlayerParachute::InitalizeFromItemDef(const UAthenaGliderItemDefinition* InParachuteItemDef, bool bSynchronousLoad)
{
}

bool AFortPlayerParachute::IsGliderFullyDeployedAccordingToAnim() const
{
	return false;
}

void AFortPlayerParachute::OnParachuteTrailUpdated_Implementation(float MovementLengthSquared, float ForwardDot, float RightDot, float RotationalMovementAcceleration)
{
}

void AFortPlayerParachute::OnRep_ParachuteItemDef()
{
}

void AFortPlayerParachute::OnRep_PlayerPawn(const AFortPlayerPawn* PreviousPlayerPawn)
{
}

void AFortPlayerParachute::SetChuteMeshVisibility(bool bNewParachuteVisible)
{
}

void AFortPlayerParachute::SetPlayerPawn(AFortPlayerPawn* InPlayerPawn)
{
}

void AFortPlayerParachute::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortPlayerParachute, PlayerPawn);
	DOREPLIFETIME(AFortPlayerParachute, ParachuteItemDef);
}
