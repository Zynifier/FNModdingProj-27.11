// Copyright Epic Games, Inc. All Rights Reserved.

#include "VoteResponderComponent.h"
#include "Net/UnrealNetwork.h"

void UVoteResponderComponent::CastDefaultVoteSelection(const APlayerState* InPlayerState)
{
}

void UVoteResponderComponent::CastManualVoteSelection(const APlayerState* InPlayerState, const FGameplayTag& VoteSelection)
{
}

void UVoteResponderComponent::CastManualVoteSelectionAtIndex(const APlayerState* InPlayerState, const int32 SelectionIndex)
{
}

void UVoteResponderComponent::ServerCastVoteSelection_Implementation(const FUniqueNetIdRepl& InUserId, const FCastedVote& CastedVote)
{
}
bool UVoteResponderComponent::ServerCastVoteSelection_Validate(const FUniqueNetIdRepl& InUserId, const FCastedVote& CastedVote)
{
	return true;
}

void UVoteResponderComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVoteResponderComponent, SupportedVoteSelections);
	DOREPLIFETIME(UVoteResponderComponent, bShouldLockVotingAfterCasted);
}
