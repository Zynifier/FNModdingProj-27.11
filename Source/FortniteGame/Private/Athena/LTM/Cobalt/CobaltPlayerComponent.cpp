// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/Cobalt/CobaltPlayerComponent.h"
#include "Net/UnrealNetwork.h"

void UCobaltPlayerComponent::ClientOnPawnKilled(AFortPlayerStateAthena* Victim)
{
}

void UCobaltPlayerComponent::OnPawnEnterWater(AFortPlayerPawn* Pawn)
{
}

void UCobaltPlayerComponent::OnPawnLanded(const FHitResult& Hit)
{
}

void UCobaltPlayerComponent::OnPlayerPawnLoaded(AFortPlayerController* PlayerController)
{
}

void UCobaltPlayerComponent::OnRep_CachedMutator()
{
}

void UCobaltPlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UCobaltPlayerComponent, CachedMutator);
}
