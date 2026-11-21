// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortBattleRoyalePlayerAugmentSystem.h"
#include "Net/UnrealNetwork.h"

void UFortBattleRoyalePlayerAugmentSystem::AuthoritySetServerGrantingStartedTimestamp(float ServerTimestamp)
{
}

void UFortBattleRoyalePlayerAugmentSystem::BlueprintAugmentLog(const FString& Message, EBattleRoyaleBPAugmentLogVerbosity Verbosity, bool bAutonomousProxyOnly)
{
}

void UFortBattleRoyalePlayerAugmentSystem::BP_GetAugmentController(EFortBRAugmentSystemCastResult& OutExec, AController*& OutController)
{
}

void UFortBattleRoyalePlayerAugmentSystem::BP_GetAugmentPlayerPawn(EFortBRAugmentSystemCastResult& OutExec, AFortPlayerPawn*& OutFortPlayerPawn)
{
}

FFortAugmentPassiveUnlockResult UFortBattleRoyalePlayerAugmentSystem::ChooseUnlockFromList_Implementation(const TArray<FPlayerAugmentLockStatus>& LockedList)
{
	return FFortAugmentPassiveUnlockResult();
}

float UFortBattleRoyalePlayerAugmentSystem::GetServerGrantingStartedTimestamp() const
{
	return float();
}

void UFortBattleRoyalePlayerAugmentSystem::HandlePossessedPawnChanged(APawn* OldPawn, APawn* NewPawn)
{
}

void UFortBattleRoyalePlayerAugmentSystem::OnRep_ServerGrantingStartedTimestamp()
{
}

void UFortBattleRoyalePlayerAugmentSystem::ResetMatchAugments()
{
}

FFortAugmentPassiveUnlockResult UFortBattleRoyalePlayerAugmentSystem::TryClaimUnlock()
{
	return FFortAugmentPassiveUnlockResult();
}

void UFortBattleRoyalePlayerAugmentSystem::TryIncrementUnlockRollCount()
{
}

void UFortBattleRoyalePlayerAugmentSystem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortBattleRoyalePlayerAugmentSystem, ServerGrantingStartedTimestamp);
}
