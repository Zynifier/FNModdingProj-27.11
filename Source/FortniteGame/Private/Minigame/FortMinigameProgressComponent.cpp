// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameProgressComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMinigameProgressComponent::AbortProgress(APlayerState* PlayerState)
{
}

void UFortMinigameProgressComponent::FinishProgress(APlayerState* PlayerState)
{
}

bool UFortMinigameProgressComponent::HasActivationTime() const
{
	return false;
}

void UFortMinigameProgressComponent::RevertProgress(APlayerState* PlayerState)
{
}

void UFortMinigameProgressComponent::StartProgress(APlayerState* PlayerState)
{
}

void UFortMinigameProgressComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameProgressComponent, ActivationTime);
}
