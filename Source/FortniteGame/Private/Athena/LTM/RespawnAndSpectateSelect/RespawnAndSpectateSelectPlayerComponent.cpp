// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/LTM/RespawnAndSpectateSelect/RespawnAndSpectateSelectPlayerComponent.h"
#include "Net/UnrealNetwork.h"

void URespawnAndSpectatePlayerComponent::OnRep_ReplicateClientScreenFade_FadeIn()
{
}

void URespawnAndSpectatePlayerComponent::ServerFadeOutComplete_Implementation()
{
}

void URespawnAndSpectatePlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(URespawnAndSpectatePlayerComponent, RespawnFailSafeTime);
	DOREPLIFETIME(URespawnAndSpectatePlayerComponent, ManagingMutator);
	DOREPLIFETIME(URespawnAndSpectatePlayerComponent, RespawningState);
	DOREPLIFETIME(URespawnAndSpectatePlayerComponent, ReplicateClientScreenFade_FadeIn);
}
