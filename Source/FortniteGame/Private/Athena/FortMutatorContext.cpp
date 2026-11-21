// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/FortMutatorContext.h"

void IFortMutatorContext::GetMutatorContext(FMutatorContext& MutatorContext) const
{
}

void IFortMutatorOwner::AddMutatorToList(AFortGameplayMutator* Mutator)
{
}

void IFortMutatorOwner::GetMutatorRelevantPlayers(TArray<APlayerState*>& OutPlayers) const
{
}

void IFortMutatorOwner::RemoveMutatorFromList(AFortGameplayMutator* Mutator)
{
}
