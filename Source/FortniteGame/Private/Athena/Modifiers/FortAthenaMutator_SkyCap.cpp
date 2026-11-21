// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/FortAthenaMutator_SkyCap.h"
#include "Net/UnrealNetwork.h"

void AAthenaSkyCap::OnRep_SkyCapState()
{
}

void AAthenaSkyCap::OnStopMovement(const FHitResult& ImpactResult, float Time)
{
}

void AAthenaSkyCap::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AAthenaSkyCap, SkyCapState);
}
