// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeKeyLockComponent.h"
#include "Net/UnrealNetwork.h"

int32 UFortCreativeKeyLockComponent::BlueprintGetKeyAmountOnPlayer(APawn* Pawn)
{
	return int32();
}

bool UFortCreativeKeyLockComponent::BlueprintHasKeysToInteract(APawn* Pawn)
{
	return false;
}

ECreativeKeyLockState UFortCreativeKeyLockComponent::GetCurrentState() const
{
	return ECreativeKeyLockState();
}

bool UFortCreativeKeyLockComponent::IsLocked() const
{
	return false;
}

bool UFortCreativeKeyLockComponent::Lock(APawn* Pawn)
{
	return false;
}

void UFortCreativeKeyLockComponent::OnRep_CurrentState()
{
}

void UFortCreativeKeyLockComponent::OnRep_RemainingKeysToUnlock()
{
}

void UFortCreativeKeyLockComponent::OnRep_UnlockKeyItem()
{
}

void UFortCreativeKeyLockComponent::Reset(bool DeferredReset)
{
}

void UFortCreativeKeyLockComponent::SetKeyItemDefinition(const FItemVariantHandle& ItemHandle)
{
}

void UFortCreativeKeyLockComponent::SetRequiredAllKeysAtOne(bool Required)
{
}

void UFortCreativeKeyLockComponent::SetRequiredKeys(int32 Amount)
{
}

void UFortCreativeKeyLockComponent::SetShouldConsumeKey(bool ShouldConsume)
{
}

bool UFortCreativeKeyLockComponent::Unlock(APawn* Pawn)
{
	return false;
}

void UFortCreativeKeyLockComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCreativeKeyLockComponent, CurrentState);
	DOREPLIFETIME(UFortCreativeKeyLockComponent, RequiredKeysToUnlockAmount);
	DOREPLIFETIME(UFortCreativeKeyLockComponent, RemainingKeysToUnlockAmount);
	DOREPLIFETIME(UFortCreativeKeyLockComponent, bRequireAllKeysAtOnce);
	DOREPLIFETIME(UFortCreativeKeyLockComponent, UnlockKeyItem);
}
