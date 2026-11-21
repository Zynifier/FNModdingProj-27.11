// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortControllerComponent_AugmentGrantingSystem.h"
#include "Net/UnrealNetwork.h"

const UFortWorldItem* UAugmentFuctionLibrary::GiveAugmentWithPreventDropping(UFortPlayerAugmentItemDefinition* ChosenAugmentDef, TScriptInterface<IFortInventoryOwnerInterface> InventoryOwner)
{
	return nullptr;
}

void UFortControllerComponent_AugmentGrantingSystem::AuthorityGrantFreeReroll()
{
}

void UFortControllerComponent_AugmentGrantingSystem::AuthorityGrantNewAugment()
{
}

void UFortControllerComponent_AugmentGrantingSystem::AuthorityIncrementLockedSelectionChoices(const int32 NumLocksToAdd)
{
}

void UFortControllerComponent_AugmentGrantingSystem::AuthorityRequestSelectionToolItemGrant(UObject* Instigator)
{
}

void UFortControllerComponent_AugmentGrantingSystem::AuthorityResetAugmentData()
{
}

void UFortControllerComponent_AugmentGrantingSystem::AuthoritySetAvailableAugmentChoices(const TArray<FPlayerAugmentChoiceDatum>& AvailableAugmentsToGrant)
{
}

bool UFortControllerComponent_AugmentGrantingSystem::CanReroll() const
{
	return false;
}

void UFortControllerComponent_AugmentGrantingSystem::ClientSelectAvailableAugmentToGrant(UFortPlayerAugmentItemDefinition* ChosenAugmentDef)
{
}

UFortControllerComponent_AugmentGrantingSystem* UFortControllerComponent_AugmentGrantingSystem::GetAugmentGrantingComponentFromController(const AController* Controller)
{
	return nullptr;
}

TArray<FPlayerAugmentChoiceDatum> UFortControllerComponent_AugmentGrantingSystem::GetAvailableAugmentsToGrant() const
{
	return TArray<FPlayerAugmentChoiceDatum>();
}

int32 UFortControllerComponent_AugmentGrantingSystem::GetNumFreeRerolls() const
{
	return int32();
}

int32 UFortControllerComponent_AugmentGrantingSystem::GetPendingAugmentsToGrant() const
{
	return int32();
}

void UFortControllerComponent_AugmentGrantingSystem::HandleChangedBuildMode(bool bEnteredBuildMode)
{
}

void UFortControllerComponent_AugmentGrantingSystem::HandleHolsteredEvent()
{
}

void UFortControllerComponent_AugmentGrantingSystem::HandlePossessedPawnChanged(APawn* OldPawn, APawn* NewPawn)
{
}

void UFortControllerComponent_AugmentGrantingSystem::HandleToggleFullscreenMap(bool bVisible)
{
}

void UFortControllerComponent_AugmentGrantingSystem::HandleUnHolsteredEvent()
{
}

bool UFortControllerComponent_AugmentGrantingSystem::IsSelectionChoicesLocked() const
{
	return false;
}

bool UFortControllerComponent_AugmentGrantingSystem::IsSelectionItemEquipped() const
{
	return false;
}

void UFortControllerComponent_AugmentGrantingSystem::OnMinigameStarted()
{
}

void UFortControllerComponent_AugmentGrantingSystem::OnRep_NumFreeRerolls()
{
}

void UFortControllerComponent_AugmentGrantingSystem::OnRep_NumLockedSelectionChoices()
{
}

void UFortControllerComponent_AugmentGrantingSystem::OnRep_ReplicatedAugmentChoices()
{
}

void UFortControllerComponent_AugmentGrantingSystem::OnRep_ReplicatedNumPendingAugmentsToGrant()
{
}

void UFortControllerComponent_AugmentGrantingSystem::OnRep_SelectorItemEntry()
{
}

void UFortControllerComponent_AugmentGrantingSystem::ServerGrantAugment_Implementation(UFortPlayerAugmentItemDefinition* ChosenAugmentDef)
{
}

void UFortControllerComponent_AugmentGrantingSystem::ServerRequestReroll_Implementation()
{
}

void UFortControllerComponent_AugmentGrantingSystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_AugmentGrantingSystem, ReplicatedNumPendingAugmentsToGrant);
	DOREPLIFETIME(UFortControllerComponent_AugmentGrantingSystem, ReplicatedAugmentChoices);
	DOREPLIFETIME(UFortControllerComponent_AugmentGrantingSystem, NumFreeRerolls);
	DOREPLIFETIME(UFortControllerComponent_AugmentGrantingSystem, NumLockedSelectionChoices);
	DOREPLIFETIME(UFortControllerComponent_AugmentGrantingSystem, SelectorItemEntry);
}
