// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/SpecialActor/FortGlobalActorRegistrySubsystem.h"

FGameplayTag UActorRegisterData_GameplayTagBased::GetGameplayTag() const
{
	return FGameplayTag();
}

const TArray<AActor*>& UActorRegisterData_GameplayTagBased::GetRegisteredActors() const
{
	static TArray<AActor*> Dummy;
	return Dummy;
}

void UActorRegisterData_GameplayTagBased::HandleListenerRemoved()
{
}

void UActorRegisterData_GameplayTagBased::RegisteredActorDestroyed(AActor* DestroyedActor)
{
}

void UActorRegisterData_GameplayTagBased::RemoveIfNotUsed()
{
}

UActorRegisterData_GameplayTagBased* UFortGlobalActorRegistrySubsystem::GetActorRegistryDataForGameplayTag(const FGameplayTag& GameplayTag)
{
	return nullptr;
}

void UFortGlobalActorRegistrySubsystem::GetRegisteredActors(TArray<AActor*>& OutActors, const FGameplayTag& GameplayTag)
{
}

const TArray<FGameplayTag> UFortGlobalActorRegistrySubsystem::GetRegistrationTagsForActor(const AActor* InActor) const
{
	return TArray<FGameplayTag>();
}

void UFortGlobalActorRegistrySubsystem::LogActorRegistration() const
{
}

void UFortGlobalActorRegistrySubsystem::RegisterActor(const FGameplayTag& GameplayTag, AActor* InActor)
{
}

void UFortGlobalActorRegistrySubsystem::RegisterActors(const FGameplayTag& GameplayTag, const TArray<AActor*>& InActors)
{
}

void UFortGlobalActorRegistrySubsystem::RegisterActorsWithMultipleGameplayTags(const TArray<FGameplayTag>& GameplayTags, const TArray<AActor*>& InActors)
{
}

void UFortGlobalActorRegistrySubsystem::UnregisterActor(const FGameplayTag& GameplayTag, AActor* InActor)
{
}

void UFortGlobalActorRegistrySubsystem::UnregisterActors(const FGameplayTag& GameplayTag, const TArray<AActor*>& InActors)
{
}

void UFortGlobalActorRegistrySubsystem::UnregisterActorsFromAllGameplayTags(const TArray<AActor*>& InActors)
{
}

void UFortGlobalActorRegistrySubsystem::UnregisterActorsWithMultipleGameplayTags(const TArray<FGameplayTag>& GameplayTags, const TArray<AActor*>& InActors)
{
}
