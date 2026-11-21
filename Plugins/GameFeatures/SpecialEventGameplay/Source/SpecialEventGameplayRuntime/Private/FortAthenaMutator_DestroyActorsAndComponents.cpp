// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortAthenaMutator_DestroyActorsAndComponents.h"
#include "Net/UnrealNetwork.h"

void AFortAthenaMutator_DestroyActorsAndComponents::OnActorSpawned(AActor* Actor)
{
}

void AFortAthenaMutator_DestroyActorsAndComponents::OnRep_ActorDefinitions(const TArray<FDestroyActorsAndComponentsMutator_ActorDefinition>& OldActorDefinitions)
{
}

void AFortAthenaMutator_DestroyActorsAndComponents::OnTrackedActorDestroyed(AActor* DestroyedActor)
{
}

void AFortAthenaMutator_DestroyActorsAndComponents::PermanentlyDisableActorDefinitions(const FGameplayTagContainer& InTags)
{
}

void AFortAthenaMutator_DestroyActorsAndComponents::SetActorDefinitionsEnabled(const FGameplayTagContainer& InTags, const bool bEnabled)
{
}

void AFortAthenaMutator_DestroyActorsAndComponents::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortAthenaMutator_DestroyActorsAndComponents, ActorDefinitions);
}

void UFortCheatManager_DestroyActorsAndComponents::DestroyActorsAndComponentsMutator_ListActorComponents(const FString& InActorName) const
{
}

void UFortCheatManager_DestroyActorsAndComponents::DestroyActorsAndComponentsMutator_SetActorDefinitionsEnabled(const FString& TagString, const bool bEnabled)
{
}
