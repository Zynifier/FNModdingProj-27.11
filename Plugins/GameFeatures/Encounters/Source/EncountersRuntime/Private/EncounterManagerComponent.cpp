// Copyright Epic Games, Inc. All Rights Reserved.

#include "EncounterManagerComponent.h"

UEncounterManagerComponent::UEncounterManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UEncounterManagerComponent::AddExplicitContributor(APlayerController* Contributor)
{
}

TSoftClassPtr<AActor> UEncounterManagerComponent::GetVariable_ActorClass(const FGameplayTag& VarName) const
{
	return TSoftClassPtr<AActor>();
}

bool UEncounterManagerComponent::GetVariable_Bool(const FGameplayTag& VarName) const
{
	return false;
}

float UEncounterManagerComponent::GetVariable_Float(const FGameplayTag& VarName) const
{
	return float();
}

FGameplayTag UEncounterManagerComponent::GetVariable_GameplayTag(const FGameplayTag& VarName) const
{
	return FGameplayTag();
}

int32 UEncounterManagerComponent::GetVariable_Int(const FGameplayTag& VarName) const
{
	return int32();
}

const UFortWorldItemDefinition* UEncounterManagerComponent::GetVariable_ItemDefinition(const FGameplayTag& VarName) const
{
	return nullptr;
}

const UFortAthenaLivingWorldEncounter* UEncounterManagerComponent::GetVariable_LWMEncounter(const FGameplayTag& VarName) const
{
	return nullptr;
}

FGameplayTagQuery UEncounterManagerComponent::GetVariable_TagQuery(const FGameplayTag& VarName) const
{
	return FGameplayTagQuery();
}

void UEncounterManagerComponent::HandleEncounterFailure(int32 RewardIndex)
{
}

void UEncounterManagerComponent::HandleEncounterSuccess(int32 RewardIndex)
{
}

void UEncounterManagerComponent::OnStateTreeStatusChanged(EStateTreeRunStatus Status)
{
}

void UEncounterManagerComponent::RemoveExplicitContributor(APlayerController* Contributor)
{
}
