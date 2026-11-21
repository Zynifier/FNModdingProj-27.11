// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayCueTypes.h"

void UFortGameplayCueFunctionLibrary::AddGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context)
{
}

void UFortGameplayCueFunctionLibrary::AddGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies)
{
}

void UFortGameplayCueFunctionLibrary::BuildCueParametersFromHitResult(AActor* SourceActor, const FHitResult& HitResult, FGameplayCueParameters& OutCueParameters)
{
}

void UFortGameplayCueFunctionLibrary::BuildCueParametersFromSource(AActor* SourceActor, FGameplayCueParameters& OutCueParameters)
{
}

bool UFortGameplayCueFunctionLibrary::CheckSpawnConditionForCueParameters(AActor* Target, const FGameplayCueParameters& CueParameters, const FFortGameplayCueSpawnCondition& Condition)
{
	return false;
}

bool UFortGameplayCueFunctionLibrary::CheckSpawnConditionForHitResult(AActor* Target, AActor* SourceActor, const FHitResult& HitResult, const FFortGameplayCueSpawnCondition& Condition)
{
	return false;
}

bool UFortGameplayCueFunctionLibrary::CheckSpawnConditionForSource(AActor* Target, AActor* SourceActor, const FFortGameplayCueSpawnCondition& Condition)
{
	return false;
}

void UFortGameplayCueFunctionLibrary::ExecuteGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag, FGameplayEffectContextHandle Context)
{
}

void UFortGameplayCueFunctionLibrary::ExecuteGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies)
{
}

void UFortGameplayCueFunctionLibrary::PlayBurstEffect(const FFortBurstEffectData& BurstEffect, AActor* Target, const FGameplayCueParameters& CueParameters, FFortGameplayCueSpawnResult& OutResult)
{
}

void UFortGameplayCueFunctionLibrary::RemoveGameplayCue(AActor* TargetActor, const FGameplayTag GameplayCueTag)
{
}

void UFortGameplayCueFunctionLibrary::RemoveGameplayCueLocal(AActor* Target, FGameplayTag GameplayCueTag, const FGameplayCueParameters& CueParameters, bool bOnlyNotifies)
{
}
