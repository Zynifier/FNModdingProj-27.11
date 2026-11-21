// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/FortGameplayCueNotify_Looping.h"

bool AFortGameplayCueNotify_Looping::GetSpawnTransform(AActor* TargetActor, FName AttachPointName, const FGameplayCueParameters& Parameters, FTransform& OutTransform) const
{
	return false;
}

USceneComponent* AFortGameplayCueNotify_Looping::GetTargetComponent(AActor* TargetActor, const FGameplayCueParameters& Parameters) const
{
	return nullptr;
}
