// Copyright Epic Games, Inc. All Rights Reserved.

#include "VoteBroadcasterComponent.h"
#include "Net/UnrealNetwork.h"

void UVoteBroadcasterComponent::OnVoteCasted(const FUniqueNetIdRepl& UserNetId, const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, const FGameplayTag& VoteSelectionId)
{
}

void UVoteBroadcasterComponent::ServerSubmitVotesAggregated_Implementation(FName VoteSessionId, FName VoteId, FName VoteSelectionId, int32 VoteDelta)
{
}
bool UVoteBroadcasterComponent::ServerSubmitVotesAggregated_Validate(FName VoteSessionId, FName VoteId, FName VoteSelectionId, int32 VoteDelta)
{
	return true;
}

void UVoteBroadcasterComponent::VoteEnd(FName VoteSessionId, FName VoteId, FName WinningVoteSelectionId)
{
}

void UVoteBroadcasterComponent::VoteSessionComplete(FName VoteSessionId)
{
}

void UVoteBroadcasterComponent::VoteSessionSetup(FName VoteSessionId, FName StartingVoteId, EVoteSessionNetworkType NetworkType)
{
}

void UVoteBroadcasterComponent::VoteSessionShutdown(FName VoteSessionId)
{
}

void UVoteBroadcasterComponent::VoteSetup(FName VoteSessionId, FName VoteId)
{
}

void UVoteBroadcasterComponent::VoteStart(FName VoteSessionId, FName VoteId)
{
}

void UVoteBroadcasterComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVoteBroadcasterComponent, VoteSessionRuntimeList);
	DOREPLIFETIME(UVoteBroadcasterComponent, VoteRuntimeList);
	DOREPLIFETIME(UVoteBroadcasterComponent, VoteResultsList);
}
