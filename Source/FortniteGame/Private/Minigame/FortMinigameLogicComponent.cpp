// Copyright Epic Games, Inc. All Rights Reserved.

#include "Minigame/FortMinigameLogicComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMinigameLogicComponent::AddMinigameTag(const FGameplayTag& Tag)
{
}

void UFortMinigameLogicComponent::HandleMinigameEnded_Implementation()
{
}

void UFortMinigameLogicComponent::HandleMinigameSet_Implementation()
{
}

void UFortMinigameLogicComponent::HandleMinigameStarted_Implementation()
{
}

void UFortMinigameLogicComponent::HandleMinigameStateChanged_Implementation(AFortMinigame* Minigame, EFortMinigameState NewMinigameState)
{
}

void UFortMinigameLogicComponent::HandlePostMinigameStarted_Implementation()
{
}

void UFortMinigameLogicComponent::OnCurrentMinigameDestroyed(AActor* DestroyedActor)
{
}

void UFortMinigameLogicComponent::RemoveMinigameTag(const FGameplayTag& Tag)
{
}

bool UFortMinigameLogicComponent::TryAttachToMinigame()
{
	return false;
}

void UFortMinigameLogicComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMinigameLogicComponent, MinigameTags);
	DOREPLIFETIME(UFortMinigameLogicComponent, CurrentMinigame);
}
