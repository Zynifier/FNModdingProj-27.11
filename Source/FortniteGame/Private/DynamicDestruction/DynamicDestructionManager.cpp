// Copyright Epic Games, Inc. All Rights Reserved.

#include "DynamicDestruction/DynamicDestructionManager.h"

void UDynamicDestructionManager::EndDynamicDestructionBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject, bool bCanceled)
{
}

bool UDynamicDestructionManager::IsDynamicDestructionActiveBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject)
{
	return false;
}

void UDynamicDestructionManager::OnDestroyedActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason)
{
}

void UDynamicDestructionManager::SpawnStandaloneDynamicDestructionFX(const FDynamicDestructionMeshInfo& MeshInfo, const FDynamicDestructionDamageData& DamageData, EDynamicDestructionResourceType ResourceTypeOverride)
{
}

void UDynamicDestructionManager::StartDynamicDestructionBP(const TScriptInterface<IDynamicDestructionObjectInterface> DestroyedObject, const FDynamicDestructionDamageData& DamageData)
{
}
