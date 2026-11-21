// Copyright Epic Games, Inc. All Rights Reserved.

#include "CurieManager.h"
#include "UObject/Class.h"

bool FCurieElementPairKey::operator==(const FCurieElementPairKey& Other) const
{
	return StaticStruct()->CompareScriptStruct(this, &Other, 0);
}

uint32 GetTypeHash(const FCurieElementPairKey& Value)
{
	return 0;
}

UCurieManager::UCurieManager(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UCurieManager::BindDelegateForCurieElementAttached(UObject* CurieOwner, const FCurieElementAttachedSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieElementBeginInteract(UObject* CurieOwner, const FCurieElementBeginInteractSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieElementDetached(UObject* CurieOwner, const FCurieElementDetachedSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieElementEndInteract(UObject* CurieOwner, const FCurieElementEndInteractSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieElementInteract(UObject* CurieOwner, const FCurieElementInteractSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieStateAttached(UObject* CurieOwner, const FCurieStateAttachedSignature& Delegate)
{
}

void UCurieManager::BindDelegateForCurieStateDetached(UObject* CurieOwner, const FCurieStateDetachedSignature& Delegate)
{
}

void UCurieManager::HandleContainerOwnerDestroyed(AActor* OwnerActor)
{
}

void UCurieManager::UnbindDelegateForCurieElementAttached(UObject* CurieOwner, const FCurieElementAttachedSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieElementBeginInteract(UObject* CurieOwner, const FCurieElementBeginInteractSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieElementDetached(UObject* CurieOwner, const FCurieElementDetachedSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieElementEndInteract(UObject* CurieOwner, const FCurieElementEndInteractSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieElementInteract(UObject* CurieOwner, const FCurieElementInteractSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieStateAttached(UObject* CurieOwner, const FCurieStateAttachedSignature& Delegate)
{
}

void UCurieManager::UnbindDelegateForCurieStateDetached(UObject* CurieOwner, const FCurieStateDetachedSignature& Delegate)
{
}
