// Copyright Epic Games, Inc. All Rights Reserved.

#include "Curie/FortCurieManager.h"
#include "Net/UnrealNetwork.h"

void UFortCurieManager::BindDelegateOnToggleGroupFullyActive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate)
{
}

void UFortCurieManager::BindDelegateOnToggleGroupFullyInactive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate)
{
}

void UFortCurieManager::BindDelegateOnToggleGroupMemberActiveStateChange(FGameplayTag ToggleGroup, FCurieToggleGroupMemberStateChangeSignature Delegate)
{
}

void UFortCurieManager::InternalPhysicsComponentAwakeChanged(UPrimitiveComponent* SimulatingComponent, const bool bIsAwake)
{
}

void UFortCurieManager::OnRep_ValidStateIdentifiers()
{
}

void UFortCurieManager::OnToggleGroupComponentActivated(UActorComponent* InComponent, bool bReset)
{
}

void UFortCurieManager::OnToggleGroupComponentDeactivated(UActorComponent* InComponent)
{
}

void UFortCurieManager::UnbindDelegateOnToggleGroupFullyActive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate)
{
}

void UFortCurieManager::UnbindDelegateOnToggleGroupFullyInactive(FGameplayTag ToggleGroup, FCurieToggleGroupSameStateSignature Delegate)
{
}

void UFortCurieManager::UnbindDelegateOnToggleGroupMemberActiveStateChange(FGameplayTag ToggleGroup, FCurieToggleGroupMemberStateChangeSignature Delegate)
{
}

void UFortCurieManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCurieManager, ValidStateIdentifiers);
}
