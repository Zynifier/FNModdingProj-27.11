// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "GameplayTagContainer.h"
#include "MeshNetworkComponent.h"
#include "VotingFrameworkTypes.h"
#include "VoteBroadcasterComponent.generated.h"

enum class EVoteSessionNetworkType : uint8;

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Voting"), meta=(BlueprintSpawnableComponent))
class UVoteBroadcasterComponent : public UMeshNetworkComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteEnd(FName VoteSessionId, FName VoteId, FName WinningVoteSelectionId);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteSessionComplete(FName VoteSessionId);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteSessionSetup(FName VoteSessionId, FName StartingVoteId, EVoteSessionNetworkType NetworkType);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteSessionShutdown(FName VoteSessionId);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteSetup(FName VoteSessionId, FName VoteId);

	UFUNCTION(BlueprintCallable, Category="VotingFramework | Broadcaster")
	void VoteStart(FName VoteSessionId, FName VoteId);

protected:
	UFUNCTION()
	void OnVoteCasted(const FUniqueNetIdRepl& UserNetId, const FGameplayTag& VoteSessionId, const FGameplayTag& VoteId, const FGameplayTag& VoteSelectionId);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerSubmitVotesAggregated(FName VoteSessionId, FName VoteId, FName VoteSelectionId, int32 VoteDelta);

	UPROPERTY(EditAnywhere, Category="VotingFramework | Broadcaster")
	TArray<FVoteSessionSettings> VoteSessionSettingsList;

	UPROPERTY(Transient, Replicated)
	FVoteSessionRuntimeArray VoteSessionRuntimeList;

	UPROPERTY(Transient, Replicated)
	FVoteRuntimeArray VoteRuntimeList;

	UPROPERTY(Transient, Replicated)
	FVoteSelectionResultsArray VoteResultsList;

	UPROPERTY(Transient)
	TMap<FUniqueNetIdRepl, FCastedVote> PlayerCastedVotesMap;

};

