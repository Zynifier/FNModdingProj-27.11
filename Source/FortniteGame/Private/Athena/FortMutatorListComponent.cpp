// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortMutatorListComponent.h"
#include "Net/UnrealNetwork.h"

void UFortMutatorListComponent::AddOrUpdatePropertyOverrides(const TMap<FString, FString>& Properties)
{
}

AFortGameplayMutator* UFortMutatorListComponent::GetMutatorByClass(TSubclassOf<AFortGameplayMutator> MutatorClass) const
{
	return nullptr;
}

TMap<FString, FString> UFortMutatorListComponent::GetPropertyOverridesAsStrings() const
{
	return TMap<FString, FString>();
}

TMap<FString, FString> UFortMutatorListComponent::GetPropertyOverridesAsStringsRaw() const
{
	return TMap<FString, FString>();
}

void UFortMutatorListComponent::OnMinigameSetUp(AFortMinigame* Minigame)
{
}

void UFortMutatorListComponent::OnRep_PropertyOverrideArray()
{
}

void UFortMutatorListComponent::RegisterMinigameMutators()
{
}

bool UFortMutatorListComponent::RemovePropertyOverride(const FString& Property)
{
	return false;
}

void UFortMutatorListComponent::ResolvePendingRepOverrides()
{
}

void UFortMutatorListComponent::SetMutatorsActive(bool bActive)
{
}

void UFortMutatorListComponent::SetPropertyOverrides(const TMap<FString, FString>& Properties)
{
}

void UFortMutatorListComponent::UnregisterMinigameMutators()
{
}

void UFortMutatorListComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortMutatorListComponent, OverrideData);
}
