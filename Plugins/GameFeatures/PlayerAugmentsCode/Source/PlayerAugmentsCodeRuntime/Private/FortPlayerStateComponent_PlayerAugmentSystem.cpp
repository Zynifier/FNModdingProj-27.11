// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlayerStateComponent_PlayerAugmentSystem.h"
#include "Net/UnrealNetwork.h"

void UFortPlayerStateComponent_PlayerAugmentSystem::ClientClearMatchAugmentDataCache_Implementation()
{
}

TArray<UFortPlayerAugmentItemDefinition*> UFortPlayerStateComponent_PlayerAugmentSystem::GetActiveAugments(AActor* Actor)
{
	return TArray<UFortPlayerAugmentItemDefinition*>();
}

UFortPlayerStateComponent_PlayerAugmentSystem* UFortPlayerStateComponent_PlayerAugmentSystem::GetAugmentComponent(const AActor* PlayerContextActor)
{
	return nullptr;
}

UFortPlayerStateComponent_PlayerAugmentSystem* UFortPlayerStateComponent_PlayerAugmentSystem::GetAugmentComponentValidated(EAugmentExecResult& OutExec, const AActor* PlayerContextActor)
{
	return nullptr;
}

double UFortPlayerStateComponent_PlayerAugmentSystem::GetAugmentMatchDataCacheFloat(EAugmentExecResult& OutExec, FGameplayTag TargetAugmentCacheTag)
{
	return double();
}

void UFortPlayerStateComponent_PlayerAugmentSystem::HandleBotPlayerPawnSpawned(AFortAthenaAIBotController* BotController, AFortPlayerPawnAthena* BotPawn)
{
}

void UFortPlayerStateComponent_PlayerAugmentSystem::HandlePlayerPawnSpawned()
{
}

void UFortPlayerStateComponent_PlayerAugmentSystem::OnRep_ActiveAugments()
{
}

void UFortPlayerStateComponent_PlayerAugmentSystem::SetAugmentMatchDataCacheFloat(FGameplayTag TargetAugmentCacheTag, double InData)
{
}

void UFortPlayerStateComponent_PlayerAugmentSystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortPlayerStateComponent_PlayerAugmentSystem, ActiveAugments);
}
