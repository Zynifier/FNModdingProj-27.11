// Copyright Epic Games, Inc. All Rights Reserved.

#include "Abilities/Tasks/FortAbilityTask_PlayContextualAnimAndWait.h"

UFortAbilityTask_PlayContextualAnimAndWait* UFortAbilityTask_PlayContextualAnimAndWait::CreatePlayContextualAnimAndWaitProxy(UGameplayAbility* OwningAbility, FName TaskInstanceName, const UContextualAnimSceneAsset* SceneAsset, const TMap<FName, FContextualAnimSceneBindingContext>& Params)
{
	return nullptr;
}

void UFortAbilityTask_PlayContextualAnimAndWait::OnGameplayAbilityCancelled()
{
}

void UFortAbilityTask_PlayContextualAnimAndWait::OnLeftContextualAnimScene(UContextualAnimSceneActorComponent* SceneActorComponent)
{
}
