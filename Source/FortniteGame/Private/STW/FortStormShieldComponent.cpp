// Copyright Epic Games, Inc. All Rights Reserved.

#include "STW/FortStormShieldComponent.h"
#include "Net/UnrealNetwork.h"

void UFortStormShieldComponent::OwnerDestroyed(AActor* InOwner)
{
}

void UFortStormShieldComponent::StormShieldCreated(AFortMissionStormShield* Shield)
{
}

void UFortStormShieldComponent::StormShieldDestroyed(AActor* DestroyedActor)
{
}

void UFortStormShieldComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortStormShieldComponent, bCareAboutEdgeOfStorm);
}
