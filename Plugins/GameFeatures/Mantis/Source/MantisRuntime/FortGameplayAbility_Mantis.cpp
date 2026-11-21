// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortGameplayAbility_Mantis.h"

void UFortGameplayAbility_Mantis::ConfigureRootMotionWarping_Implementation(const FName TechniqueName, bool& bOutAllowTranslationWarp, bool& bOutAllowRotationWarp, AActor*& OutTargetActor, bool& bOutSnapshotTargetActorLocation, bool& bOutWarpTranslationToLocation, FVector& OutTargetLocation)
{
}

FName UFortGameplayAbility_Mantis::GetDynamicMontageNameForTechnique_Implementation(const FName TechniqueName) const
{
	return FName();
}

int32 UFortGameplayAbility_Mantis::GetLevelForGameplayEffectContainer_Implementation(const FGameplayTag ApplicationTag) const
{
	return int32();
}

void UFortGameplayAbility_Mantis::OnMontageCancelled()
{
}

void UFortGameplayAbility_Mantis::OnMontageFinished()
{
}
