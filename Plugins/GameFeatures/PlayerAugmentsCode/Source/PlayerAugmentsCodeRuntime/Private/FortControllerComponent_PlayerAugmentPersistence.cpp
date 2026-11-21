// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortControllerComponent_PlayerAugmentPersistence.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_PlayerAugmentPersistence::AuthoritySetCarryOverPlayerAugments(const TArray<FCarryOverPlayerAugment>& NewCarryOverPlayerAugments)
{
}

void UFortControllerComponent_PlayerAugmentPersistence::AuthoritySetRollCountSinceLastRandomUnlock(int32 NewRollCount)
{
}

void UFortControllerComponent_PlayerAugmentPersistence::AuthorityUnlockPlayerAugment(UFortPlayerAugmentItemDefinition* PlayerAugmentToUnlock)
{
}

void UFortControllerComponent_PlayerAugmentPersistence::GetCarryOverPlayerAugments(TArray<FCarryOverPlayerAugment>& OutCarryOverPlayerAugments) const
{
}

void UFortControllerComponent_PlayerAugmentPersistence::GetLockedList(TArray<FPlayerAugmentLockStatus>& OutLockedList, bool bIncludeSharedAugments) const
{
}

FPlayerAugmentLockStatus UFortControllerComponent_PlayerAugmentPersistence::GetLockStatus(UFortPlayerAugmentItemDefinition* PlayerAugmentItemDefinition) const
{
	return FPlayerAugmentLockStatus();
}

void UFortControllerComponent_PlayerAugmentPersistence::GetLockStatusForAll(TArray<FPlayerAugmentLockStatus>& OutLockStatusArray) const
{
}

int32 UFortControllerComponent_PlayerAugmentPersistence::GetRollCountSinceLastRandomUnlock() const
{
	return int32();
}

void UFortControllerComponent_PlayerAugmentPersistence::HandleCollectionDataLoaded(TSoftObjectPtr<UFortCollectionData> BaseCollectionDataSoftPtr)
{
}

void UFortControllerComponent_PlayerAugmentPersistence::HandleCollectionDataTableLoaded(TSoftObjectPtr<UFortCollectionsDataTable> CollectionsDataTableSoftPtr)
{
}

void UFortControllerComponent_PlayerAugmentPersistence::HandleMcpProfilesInitialized()
{
}

void UFortControllerComponent_PlayerAugmentPersistence::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_PlayerAugmentPersistence, LivePlayerAugmentsPersistenceData);
	DOREPLIFETIME(UFortControllerComponent_PlayerAugmentPersistence, ReplicatedSharedPlayerAugments);
}
