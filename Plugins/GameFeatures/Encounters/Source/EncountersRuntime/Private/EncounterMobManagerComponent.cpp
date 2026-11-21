// Copyright Epic Games, Inc. All Rights Reserved.

#include "EncounterMobManagerComponent.h"

UEncounterMobManagerComponent::UEncounterMobManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UEncounterMobManagerComponent::EndAndCleanupAllMobEncounters()
{
}

void UEncounterMobManagerComponent::EndMobEncounter(const FGameplayTag& MobIdentifier)
{
}

void UEncounterMobManagerComponent::OnMobActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum)
{
}

void UEncounterMobManagerComponent::OnMobActorSpawn(AActor* SpawnedActor)
{
}

void UEncounterMobManagerComponent::OnMobPawnEndPlay(AActor* Mob, EEndPlayReason::Type EndPlayReason)
{
}

void UEncounterMobManagerComponent::PauseMobEncounter(const FGameplayTag& MobIdentifier)
{
}

void UEncounterMobManagerComponent::ResumeMobEncounter(const FGameplayTag& MobIdentifier)
{
}

bool UEncounterMobManagerComponent::StartMobEncounter(const FGameplayTag& MobIdentifier)
{
	return false;
}
